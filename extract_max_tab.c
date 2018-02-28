/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_max_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schmurz <schmurz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 08:31:23 by schmurz           #+#    #+#             */
/*   Updated: 2018/02/27 17:23:55 by schmurz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int find_j(int *x, int *m, int l, int i)
{
  int j;
  int ret;

  j = 1;
  ret = 0;
  while (j <= l)
  {
    if (x[m[j]] < x[i] && j > ret)
      ret = j;
    j++;
  }
  return (ret);
}

static int fill_m_and_p(t_pile *m, t_pile *p, int *x, int n) {
  int i;
  int l;
  int j;

  i = 0;
  l = 0;
  j = 0;
  while (i < n)
  {
    j = find_j(x, m->vals, l, i);
    p->len = i + 1;
    p->vals[i] = m->vals[j];
    if (j == l || x[i] < x[m->vals[j + 1]])
    {
      l = (l > j+ 1) ? l : (j + 1);
      m->len = l + 1;
      m->vals[j + 1] = i;
    }
    i++;
  }
  return (l);
}

static void fill_ret(t_pile *ret, t_pile m, t_pile p, int *x)
{
  int i;
  int j;

  i = 0;
  j = m.vals[ret->len];
  while (i < ret->len)
  {
    ret->vals[i] = x[j];
    j = p.vals[j];
    i++;
  }
}

t_pile  max_order_in_tab(int *x, int n)
{
  t_pile m;
  t_pile p;
  t_pile ret;

  m.len = 1;
  m.vals = (int*)malloc(sizeof(int)*n);
  p.len = 1;
  p.vals = (int*)malloc(sizeof(int)*n);
  ret.len = 1;
  ret.vals = (int*)malloc(sizeof(int)*n);
  m.vals[0] = 0;
  ret.len = fill_m_and_p(&m, &p, x, n);
  fill_ret(&ret, m, p, x);
  free(m.vals);
  free(p.vals);
  ft_intarr_rev(&(ret.vals), ret.len);
  return (ret);
}

// int main(int argc, char **argv) {
//  	t_pile apile;
// 	int *test;
//   t_pile maxpile;
//   int i;
//
// 	if (argc < 2)
// 		return (1);
// 	argv++;
// 	apile = create_a(argv);
//   maxpile = max_order_in_tab(apile.vals, apile.len);
//   ft_printf("maxpile len %d\n", maxpile.len);
//   i = 0;
//   while (i < maxpile.len)
//   {
//     ft_printf("%d , ",maxpile.vals[i]);
//     i++;
//   }
// 	return (0);
// }
