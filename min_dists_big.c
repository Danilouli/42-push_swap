/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_dists_big.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schmurz <schmurz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 19:47:04 by schmurz           #+#    #+#             */
/*   Updated: 2018/03/02 11:02:39 by schmurz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int dist_big_rotating_a(t_pile pile)
{
	int i;
	t_pile simpile;

	if (pile_is_sort(pile))
		return (0);
	simpile = copy_pile(pile);
	i = 0;
	while (!good_to_swap_big_a(simpile) && i <= pile.len)
	{
		rotate_nc(simpile);
		i++;
	}
	free(simpile.vals);
	return(i);
}

int dist_big_rev_rotating_a(t_pile pile)
{
  int i;
	t_pile simpile;

	if (pile_is_sort(pile))
		return (0);
	simpile = copy_pile(pile);
	i = 0;
	while (!good_to_swap_big_a(simpile) && i <= pile.len)
	{
		rev_rotate_nc(simpile);
		i++;
	}
	free(simpile.vals);
	return(i);
}

int dist_big_rotating_b(t_pile pile)
{
	int i;
	t_pile simpile;

	if (pile_is_revsort(pile))
		return (0);
	simpile = copy_pile(pile);
	i = 0;
	while (!good_to_swap_big_b(simpile) && i <= pile.len)
	{
		rotate_nc(simpile);
		i++;
	}
	free(simpile.vals);
	return(i);
}

int dist_big_rev_rotating_b(t_pile pile)
{
  int i;
	t_pile simpile;

	if (pile_is_revsort(pile))
		return (0);
	simpile = copy_pile(pile);
	i = 0;
	while (!good_to_swap_big_b(simpile) && i <= pile.len)
	{
		rev_rotate_nc(simpile);
		i++;
	}
	free(simpile.vals);
	return(i);
}

int dist_big_rrotating(t_pile apile, t_pile bpile)
{
	int i;
	t_pile asimpile;
	t_pile bsimpile;

	if (pile_is_sort(apile) || pile_is_revsort(bpile))
		return (0);
	asimpile = copy_pile(apile);
	bsimpile = copy_pile(bpile);
	i = 0;
  while (!(good_to_swap_big_a(asimpile) || good_to_swap_big_b(bsimpile))
  && i <= apile.len && i <= bpile.len)
	{
		rrotate(&asimpile, &bsimpile, 0);
		i++;
	}
	free(bsimpile.vals);
	free(asimpile.vals);
	return(i);
}

int dist_big_rrev_rotating(t_pile apile, t_pile bpile)
{
	int i;
	t_pile asimpile;
	t_pile bsimpile;

	if (pile_is_sort(apile) || pile_is_revsort(bpile))
		return (0);
	asimpile = copy_pile(apile);
	bsimpile = copy_pile(bpile);
	i = 0;
  while (!(good_to_swap_big_a(asimpile) || good_to_swap_big_b(bsimpile))
  && i <= apile.len && i <= bpile.len)
	{
		rrev_rotate(&asimpile, &bsimpile, 0);
		i++;
	}
	free(bsimpile.vals);
	free(asimpile.vals);
	return(i);
}
