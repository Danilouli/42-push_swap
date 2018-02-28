/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schmurz <schmurz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 22:32:30 by schmurz           #+#    #+#             */
/*   Updated: 2018/02/28 17:16:27 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void view_pile(t_pile pile)
{
  int i;

  i = 0;
  while (i < pile.len - 1)
  {
    ft_printf("%d, ",pile.vals[i]);
    i++;
  }
	if (pile.len > 0)
		ft_printf("%d",pile.vals[i]);
	ft_putchar('\n');
}

void view_piles(t_pile apile, t_pile bpile)
{
	ft_putendl("***Pile A***");
	view_pile(apile);
	ft_putendl("***Pile B***");
	view_pile(bpile);
	ft_putchar('\n');
}
