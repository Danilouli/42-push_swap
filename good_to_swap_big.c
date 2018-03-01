/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   good_to_swap_big.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schmurz <schmurz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 19:48:16 by schmurz           #+#    #+#             */
/*   Updated: 2018/03/01 20:07:55 by schmurz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int find_min_ind(t_pile pile)
{
  int i;
  int min;

  i = 0;
  min = ft_intarr_min(pile.vals, pile.len);
  while (pile.vals[i] != min && i < pile.len)
    i++;
  return (i);
}

int min_max_stick(t_pile pile)
{
  int ind_min;

  ind_min = find_min_ind(pile);
  if (ind_min > 0 && pile.vals[ind_min - 1] == ft_intarr_max(pile.vals, pile.len))
    return(1);
  if (ind_min == 0 && pile.vals[pile.len - 1] == ft_intarr_max(pile.vals, pile.len))
    return (1);
  return(0);
}

int good_to_swap_big(t_pile pile)
{
  if (pile.vals[0] > pile.vals[1])
  {
    if (pile.vals[0] != ft_intarr_max(pile.vals, pile.len))
      return (1);
    if (pile.vals[0] == ft_intarr_max(pile.vals, pile.len) &&
      pile.vals[1] != ft_intarr_min(pile.vals, pile.len))
      return (1);
  }
  return (0);
}
