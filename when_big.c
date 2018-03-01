/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   when_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schmurz <schmurz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 18:35:30 by schmurz           #+#    #+#             */
/*   Updated: 2018/03/01 20:06:08 by schmurz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

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
  while (i < simpile.len)
  {
    ft_printf("%d\n",simpile.vals[i]);
    i++;
  }
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

int main(int argc, char **argv)
{
  t_pile apile;
  t_pile bpile;
  int med;
  int t;
  int gts;
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
  gts = good_to_swap_big(apile);
  ft_printf("median %d t %d gst %d\n",med, t, gts);
  bpile = create_b(apile.len);
  push_median(&apile, &bpile, med);
  view_piles(apile, bpile);
  ft_lstreverse(&g_ops);
  print_delete_g_ops(g_ops);
  ft_free_all(2, apile.vals, bpile.vals);
  return (0);
}
