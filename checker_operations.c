/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schmurz <schmurz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 21:23:07 by schmurz           #+#    #+#             */
/*   Updated: 2018/02/14 22:42:10 by schmurz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap(t_pile *pile)
{
  int tmp;

  if (pile->len >= 2)
  {
    tmp = (pile->vals)[0];
    (pile->vals)[0] = (pile->vals)[1];
    (pile->vals)[1] = tmp;
  }
}

void sswap(t_pile *apile, t_pile *bpile)
{
  swap(apile);
  swap(bpile);
}

void rotate(t_pile *pile)
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
}

void rrotate(t_pile *apile, t_pile *bpile)
{
  rotate(apile);
  rotate(bpile);
}

void rev_rotate(t_pile *pile)
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
}

void rrev_rotate(t_pile *apile, t_pile *bpile)
{
  rev_rotate(apile);
  rev_rotate(bpile);
}

void push(t_pile *from_pile, t_pile *to_pile)
{
  if (from_pile->len > 0)
  {
    (to_pile->len)++;
    (to_pile->vals)[(to_pile->len) - 1] = 0;
    rev_rotate(to_pile);
    (to_pile->vals)[0] = (from_pile->vals)[0];
    rotate(from_pile);
    (from_pile->vals)[(from_pile->len) - 1] = 0;
    (from_pile->len)--;    
  }
}
