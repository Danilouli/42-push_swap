/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_max_ver.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schmurz <schmurz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 16:35:31 by schmurz           #+#    #+#             */
/*   Updated: 2018/02/27 16:37:48 by schmurz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

int find_j(int *x, int *m, int l, int i)
{
  int j;
  int ret;

  j = 1;
  ret = 0;
  while (j <= l)
  {
    if (x[m[j] - 1] < x[i - 1] && j > ret)
      ret = j;
    j++;
  }
  return (ret);
}

t_pile  max_order_in_tab_swap(int *x, int n)
{
  t_pile m;
  t_pile p;
  t_pile ret;
	int i;
	int j;
	int l;

  m.len = 1;
  m.vals = (int*)malloc(sizeof(int)*n);
  p.len = 1;
  p.vals = (int*)malloc(sizeof(int)*n);
  ret.len = 1;
  ret.vals = (int*)malloc(sizeof(int)*n);
  l = 0;
  m.vals[0] = 0;
  i = 1;
  j = 0;
  while (i <= n)
  {
    // ft_printf("\ndans le while, boucle %d\n\n",i);
    // ft_printf("j vaut %d, l vaut %d\n",j, l);
    // ft_putendl("pile m");
    // view_pile(m);
    // ft_putendl("pile p");
    // view_pile(p);
    j = find_j(x, m.vals, l, i);
    // ft_printf("apres rech j vaut %d\n",j);
    p.len = i + 1;
    p.vals[i] = m.vals[j];
    // ft_putendl("re pile p");
    // view_pile(p);
    if (j == l || x[i - 1] < x[m.vals[j + 1] - 1])
    {
      // ft_putendl("On entre dans le if");
      l = (l > j+ 1) ? l : (j + 1);
      m.len = l + 1;
      m.vals[j + 1] = i;
      // ft_putendl("repile m apres if");
      // view_pile(m);
      // ft_printf("apres if l vaut %d\n",l);
    }
    i++;
  }
  ret.len = l;
  i = 0;
  j = m.vals[l];
  while (i < ret.len)
  {
    ret.vals[i] = x[j - 1];
    j = p.vals[j];
    i++;
  }
  return (ret);
}

int main(int argc, char **argv) {
 	t_pile apile;
	int *test;
  t_pile maxpile;
  int i;

	if (argc < 2)
		return (1);
	argv++;
	apile = create_a(argv);
  maxpile = max_order_in_tab_swap(apile.vals, apile.len);
  ft_printf("maxpile len %d\n", maxpile.len);
  i = 0;
  while (i < maxpile.len)
  {
    ft_printf("%d , ",maxpile.vals[i]);
    i++;
  }
	return (0);
}
