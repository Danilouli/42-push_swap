/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schmurz <schmurz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 21:23:07 by schmurz           #+#    #+#             */
/*   Updated: 2018/02/27 19:26:14 by schmurz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap(t_pile *pile, int wr)
{
  int tmp;

  if (pile->len >= 2)
  {
    tmp = (pile->vals)[0];
    (pile->vals)[0] = (pile->vals)[1];
    (pile->vals)[1] = tmp;
  }
	if (wr && pile->name == 'A')
		ft_lstadd(&g_ops, ft_lstnew("sa", 3));
	if (wr && pile->name == 'B')
		ft_lstadd(&g_ops, ft_lstnew("sb", 3));
}

void sswap(t_pile *apile, t_pile *bpile, int wr)
{
  swap(apile, 0);
  swap(bpile, 0);
	if (wr)
		ft_lstadd(&g_ops, ft_lstnew("ss", 3));
}

void rotate(t_pile *pile, int wr)
{
  int i;
  int tmp;

  if (pile->len >= 2)
  {
    i = -1;
    tmp = (pile->vals)[0];
    while (++i < ((pile->len) - 1))
      (pile->vals)[i] = (pile->vals)[i + 1];
    (pile->vals)[(pile->len) - 1] = tmp;
  }
	if (wr && pile->name == 'A')
		ft_lstadd(&g_ops, ft_lstnew("ra", 3));
	if (wr && pile->name == 'B')
		ft_lstadd(&g_ops, ft_lstnew("rb", 3));
}

void rotate_nc(t_pile pile)
{
  int i;
  int tmp;

  if (pile.len >= 2)
  {
    i = -1;
    tmp = (pile.vals)[0];
    while (++i < ((pile.len) - 1))
      (pile.vals)[i] = (pile.vals)[i + 1];
    (pile.vals)[(pile.len) - 1] = tmp;
  }
}

void rrotate(t_pile *apile, t_pile *bpile, int wr)
{
  rotate(apile, 0);
  rotate(bpile, 0);
	if (wr)
		ft_lstadd(&g_ops, ft_lstnew("rr", 3));
}

void rev_rotate(t_pile *pile, int wr)
{
  int i;
  int tmp;

  if (pile->len >= 2)
  {
    i = (pile->len);
    tmp = (pile->vals)[(pile->len) - 1];
    while (--i > 0)
    {
      (pile->vals)[i] = (pile->vals)[i - 1];
    }
    (pile->vals)[0] = tmp;
  }
	if (wr && pile->name == 'A')
		ft_lstadd(&g_ops, ft_lstnew("rra", 4));
	if (wr && pile->name == 'B')
		ft_lstadd(&g_ops, ft_lstnew("rrb", 4));
}

void rev_rotate_nc(t_pile pile)
{
  int i;
  int tmp;

  if (pile.len >= 2)
  {
    i = (pile.len);
    tmp = (pile.vals)[(pile.len) - 1];
    while (--i > 0)
    {
      (pile.vals)[i] = (pile.vals)[i - 1];
    }
    (pile.vals)[0] = tmp;
  }
}

void rrev_rotate(t_pile *apile, t_pile *bpile, int wr)
{
  rev_rotate(apile, 0);
  rev_rotate(bpile, 0);
	if (wr)
		ft_lstadd(&g_ops, ft_lstnew("rrr", 4));
}

void push(t_pile *from_pile, t_pile *to_pile, int wr)
{
  if (from_pile->len > 0)
  {
    (to_pile->len)++;
    (to_pile->vals)[(to_pile->len) - 1] = 0;
    rev_rotate(to_pile, 0);
    (to_pile->vals)[0] = (from_pile->vals)[0];
    rotate(from_pile, 0);
    (from_pile->vals)[(from_pile->len) - 1] = 0;
    (from_pile->len)--;
  }
	if (wr && from_pile->name == 'A')
		ft_lstadd(&g_ops, ft_lstnew("pb", 3));
	if (wr && from_pile->name == 'B')
		ft_lstadd(&g_ops, ft_lstnew("pa", 3));
}
