/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_dists.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 12:48:08 by dsaadia           #+#    #+#             */
/*   Updated: 2018/02/28 12:51:18 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int dist_rotating_a(t_pile apile, t_pile bpile, t_pile keeppile)
{
	int i;
	t_pile asimpile;
	t_pile bsimpile;

	asimpile = copy_pile(apile);
	bsimpile = copy_pile(bpile);
	i = 0;
	while (!(good_to_push(asimpile, bsimpile.vals[0], keeppile)) && i <= apile.len)
	{
		rotate_nc(asimpile);
		i++;
	}
	free(asimpile.vals);
	free(bsimpile.vals);
	return(i);
}

int dist_rev_rotating_a(t_pile apile, t_pile bpile, t_pile keeppile)
{
	int i;
	t_pile asimpile;
	t_pile bsimpile;

	asimpile = copy_pile(apile);
	bsimpile = copy_pile(bpile);
	i = 0;
	while (!(good_to_push(asimpile, bsimpile.vals[0], keeppile)) && i <= apile.len)
	{
		rev_rotate_nc(asimpile);
		i++;
	}
	free(asimpile.vals);
	free(bsimpile.vals);
	return(i);
}

int dist_rotating_b(t_pile apile, t_pile bpile, t_pile keeppile)
{
	int i;
	t_pile simpile;

	simpile = copy_pile(bpile);
	i = 0;
	while (!(good_to_push(apile, simpile.vals[0], keeppile)) && i <= apile.len)
	{
		rotate_nc(simpile);
		i++;
	}
	free(simpile.vals);
	return(i);
}

int dist_rev_rotating_b(t_pile apile, t_pile bpile, t_pile keeppile)
{
	int i;
	t_pile simpile;

	simpile = copy_pile(bpile);
	i = 0;
	while (!(good_to_push(apile, simpile.vals[0], keeppile)) && i <= apile.len)
	{
		rev_rotate_nc(simpile);
		i++;
	}
	free(simpile.vals);
	return(i);
}

int dist_rrotating(t_pile apile, t_pile bpile, t_pile keeppile)
{
	int i;

	t_pile asimpile;
	t_pile bsimpile;

	asimpile = copy_pile(apile);
	bsimpile = copy_pile(bpile);
	i = 0;
	while (!(good_to_push(asimpile, bsimpile.vals[0], keeppile)) && i <= apile.len)
	{
		rrotate(&asimpile, &bsimpile, 0);
		i++;
	}
	free(bsimpile.vals);
	free(asimpile.vals);
	return(i);
}
