/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_dists_big.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schmurz <schmurz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 19:47:04 by schmurz           #+#    #+#             */
/*   Updated: 2018/03/01 20:07:30 by schmurz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int dist_big_rotating_a(t_pile apile, t_pile bpile, t_pile keeppile)
{
	int i;
	t_pile asimpile;
	t_pile bsimpile;

	asimpile = copy_pile(apile);
	bsimpile = copy_pile(bpile);
	i = 0;
	while (!(good_to_swap_big(asimpile) || good_to_swap_big(bsimpile))
  && i <= apile.len && i <= bpile.len)
	{
		rotate_nc(asimpile);
		i++;
	}
	free(asimpile.vals);
	free(bsimpile.vals);
	return(i);
}

int dist_big_rev_rotating_a(t_pile apile, t_pile bpile, t_pile keeppile)
{
	int i;
	t_pile asimpile;
	t_pile bsimpile;

	asimpile = copy_pile(apile);
	bsimpile = copy_pile(bpile);
	i = 0;
  while (!(good_to_swap_big(asimpile) || good_to_swap_big(bsimpile))
  && i <= apile.len && i <= bpile.len)
	{
		rev_rotate_nc(asimpile);
		i++;
	}
	free(asimpile.vals);
	free(bsimpile.vals);
	return(i);
}

int dist_big_rotating_b(t_pile apile, t_pile bpile, t_pile keeppile)
{
	int i;
	t_pile simpile;

	simpile = copy_pile(bpile);
	i = 0;
  while (!(good_to_swap_big(asimpile) || good_to_swap_big(bsimpile))
  && i <= apile.len && i <= bpile.len)
	{
		rotate_nc(simpile);
		i++;
	}
	free(simpile.vals);
	return(i);
}

int dist_big_rev_rotating_b(t_pile apile, t_pile bpile, t_pile keeppile)
{
	int i;
	t_pile simpile;

	simpile = copy_pile(bpile);
	i = 0;
  while (!(good_to_swap_big(asimpile) || good_to_swap_big(bsimpile))
  && i <= apile.len && i <= bpile.len)
	{
		rev_rotate_nc(simpile);
		i++;
	}
	free(simpile.vals);
	return(i);
}

int dist_big_rrotating(t_pile apile, t_pile bpile, t_pile keeppile)
{
	int i;

	t_pile asimpile;
	t_pile bsimpile;

	asimpile = copy_pile(apile);
	bsimpile = copy_pile(bpile);
	i = 0;
  while (!(good_to_swap_big(asimpile) || good_to_swap_big(bsimpile))
  && i <= apile.len && i <= bpile.len)
	{
		rrotate(&asimpile, &bsimpile, 0);
		i++;
	}
	free(bsimpile.vals);
	free(asimpile.vals);
	return(i);
}

int dist_big_rrev_rotating(t_pile apile, t_pile bpile, t_pile keeppile)
{
	int i;
	t_pile asimpile;
	t_pile bsimpile;

	asimpile = copy_pile(apile);
	bsimpile = copy_pile(bpile);
	i = 0;
  while (!(good_to_swap_big(asimpile) || good_to_swap_big(bsimpile))
  && i <= apile.len && i <= bpile.len)
	{
		rrev_rotate(&asimpile, &bsimpile, 0);
		i++;
	}
	free(bsimpile.vals);
	free(asimpile.vals);
	return(i);
}
