/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   when_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schmurz <schmurz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 18:35:30 by schmurz           #+#    #+#             */
/*   Updated: 2018/03/02 11:21:59 by schmurz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int not_zero_min(int arg_count, ...)
{
    int i;
    int min;
    int a;

    i = 1;
    va_list ap;
    va_start(ap, arg_count);
    min = va_arg(ap, int);
    while (i < arg_count)
    {
      a = va_arg(ap, int);
      if ((a > 0 && min == 0) || (0 < a && a < min))
          min = a;
      i++;
    }
    va_end(ap);
    return min;
}

void sort_tab(int **tab, int len)
{
  int i;
  int sorted;

  i = 0;
  sorted = 0;
  while (!sorted)
  {
    i = 0;
    sorted = 1;
    while (i < len - 1)
    {
      if ((*tab)[i] > (*tab)[i + 1])
      {
        ft_swap_ints(&((*tab)[i]), &((*tab)[i + 1]));
        sorted = 0;
      }
      i++;
    }
  }
}

int get_median(t_pile pile)
{
  int i;
  t_pile simpile;
  int half;

  if (pile.len <= 0)
    return (pile.vals[0]);
  i = 0;
  simpile = copy_pile(pile);
  half = simpile.len / 2;
  sort_tab(&(simpile.vals), simpile.len);
  i = (simpile.len % 2 == 0) ?
  (((simpile.vals[half] + simpile.vals[half - 1]) / 2)) :
  (simpile.vals[half]);
  return (i);
}

void push_median(t_pile *apile, t_pile *bpile, int med)
{
  while (ft_intarr_min(apile->vals, apile->len) <= med)
  {
    if (apile->vals[0] <= med)
      push(apile, bpile, 1);
    else
      rotate(apile,1);
  }
}

void min_big_mover(t_pile *apile, t_pile *bpile)
{
	int d[6];

  d[0] = dist_big_rrotating(*apile, *bpile);
  d[1] = dist_big_rrev_rotating(*apile, *bpile);
	d[2] = dist_big_rotating_a(*apile);
	d[3] =  dist_big_rev_rotating_a(*apile);
  d[4] = dist_big_rotating_b(*bpile);
	d[5] =  dist_big_rev_rotating_b(*bpile);
  // ft_printf("d0 %d d1 %d d2 %d d3 %d d4 %d d5 %d\n",d[0], d[1], d[2], d[3], d[4], d[5]);
	if (d[0] && d[0] < not_zero_min(6, d[0], d[1], d[2], d[3], d[4], d[5])
		&& !ft_strequ((char*)(g_ops->content),"rrr"))
		rrotate(apile, bpile, 1);
	else if (d[1] && d[1] <= not_zero_min(5, d[1], d[2], d[3], d[4], d[5])
		&& !ft_strequ((char*)(g_ops->content),"rr"))
		rrev_rotate(apile, bpile, 1);
	else if (d[2] && d[2] <= not_zero_min(4, d[2], d[3], d[4], d[5])
		&& !ft_strequ((char*)(g_ops->content),"rra"))
		rotate(apile, 1);
	else if (d[3] && d[3] <= not_zero_min(3, d[3], d[4], d[5])
		&& !ft_strequ((char*)(g_ops->content),"ra"))
		rev_rotate(apile, 1);
	else if (d[4] && d[4] <= not_zero_min(2, d[4], d[5])
		&& !ft_strequ((char*)(g_ops->content),"rrb"))
		rotate(bpile, 1);
	else if (d[5] && !ft_strequ((char*)(g_ops->content),"rb"))
		rev_rotate(bpile, 1);
}

void sort_both_big(t_pile *apile, t_pile *bpile)
{
  while (!(pile_is_sort(*apile) && pile_is_revsort(*bpile)))
  {
    if (good_to_swap_big_a(*apile) && good_to_swap_big_b(*bpile))
      sswap(apile, bpile, 1);
    else if (good_to_swap_big_a(*apile))
      swap(apile, 1);
    else if (good_to_swap_big_b(*bpile))
      swap(bpile, 1);
    min_big_mover(apile, bpile);
    // view_piles(*apile, *bpile);
  }
}

int final_rra_or_ra_b(t_pile bpile)
{
	t_pile bsimpile;
	int max;
	int ra;
	int rra;

	bsimpile = copy_pile(bpile);
	ra = 0;
	rra = 0;
	max = ft_intarr_max(bsimpile.vals, bsimpile.len);
	while ((bsimpile.vals)[0] != max)
	{
		rotate_nc(bsimpile);
		ra++;
	}
	free(bsimpile.vals);
	bsimpile = copy_pile(bpile);
	while ((bsimpile.vals)[0] != max)
	{
		rev_rotate_nc(bsimpile);
		rra++;
	}
	free(bsimpile.vals);
	return ((ra < rra) ? 1 : 0);
}

void rotate_finish_a(t_pile *apile)
{
	int min_way;
	int min;

	min = ft_intarr_min(apile->vals, apile->len);
	min_way = final_rra_or_ra(*apile);
	if (min_way)
	{
		while ((apile->vals)[0] != min)
			rotate(apile, 1);
	}
	else
	{
		while ((apile->vals)[0] != min)
			rev_rotate(apile, 1);
	}
}

void rotate_finish_b(t_pile *bpile)
{
	int max_way;
	int max;

	max = ft_intarr_max(bpile->vals, bpile->len);
	max_way = final_rra_or_ra_b(*bpile);
	if (max_way)
	{
		while ((bpile->vals)[0] != max)
			rotate(bpile, 1);
	}
	else
	{
		while ((bpile->vals)[0] != max)
			rev_rotate(bpile, 1);
	}
}

void repush_b(t_pile *apile, t_pile *bpile)
{
  while (bpile->len > 0)
    push(bpile, apile, 1);
}

int main(int argc, char **argv)
{
  t_pile apile;
  t_pile bpile;
  int med;
  int t;
  // int gts;
  // t_pile keeppile;
  // t_pile simpile;

  apile = get_ps_apile(argv, argc);
  if (apile.len == -1)
  {
    ft_putendl_fd("Error",2);
    return (1);
  }
  med = get_median(apile);
  t = min_max_stick(apile);
  // gts = good_to_swap_big_a(apile);
  // ft_printf("median %d t %d gst %d\n",med, t, gts);
  bpile = create_b(apile.len);
  push_median(&apile, &bpile, med);
  // view_piles(apile, bpile);
  sort_both_big(&apile, &bpile);
  rotate_finish_a(&apile);
  rotate_finish_b(&bpile);
  // view_piles(apile, bpile);
  repush_b(&apile, &bpile);
  // view_piles(apile, bpile);
  ft_lstreverse(&g_ops);
  print_delete_g_ops(g_ops);
  ft_free_all(2, apile.vals, bpile.vals);
  return (0);
}
