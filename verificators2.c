/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verificators2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schmurz <schmurz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 18:33:50 by schmurz           #+#    #+#             */
/*   Updated: 2018/03/02 11:00:59 by schmurz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int good_to_swap(t_pile *apile, t_pile *keeppile)
{
	if (!ft_in_array((apile->vals)[0], keeppile->vals, keeppile->len)
				&& ft_in_array((apile->vals)[1], keeppile->vals, keeppile->len)
				&& (apile->vals)[0] > (apile->vals)[1]
				&& (find_just_above((apile->vals)[0], *keeppile)
				== find_just_above((apile->vals)[1], *keeppile)
				|| (apile->vals)[1] == ft_intarr_max(keeppile->vals, keeppile->len)))
				return (0);
	if (ft_in_array((apile->vals)[0], keeppile->vals, keeppile->len)
			&& !ft_in_array((apile->vals)[1], keeppile->vals, keeppile->len)
			&& (apile->vals)[0] > (apile->vals)[1]
			&& (find_just_under((apile->vals)[0], *keeppile)
			== find_just_under((apile->vals)[1], *keeppile)
			|| (apile->vals)[0] == ft_intarr_min(keeppile->vals, keeppile->len)))
				return (1);
	return (-1);
}

int rotate_a_or_both(t_pile *apile, t_pile *bpile, t_pile *keeppile)
{
	t_pile asimpile;
	t_pile bsimpile;

	asimpile = copy_pile(*apile);
	bsimpile = copy_pile(*bpile);
	rrotate(&asimpile, &bsimpile, 0);
	if (good_to_push(asimpile, bpile->vals[0], *keeppile))
	{
		free(asimpile.vals);
		free(bsimpile.vals);
		return (1);
	}
	free(asimpile.vals);
	free(bsimpile.vals);
	return (0);
}

int arr_sort_desc(int *tab, int len)
{
	int i;

	i = 0;
	while (i < len - 1)
	{
		if (tab[i] < tab[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int pile_is_revsort(t_pile pile)
{
	int i;
	t_pile simpile;

	simpile.len = pile.len;
	simpile.name = pile.name;
	simpile.vals = (int*)malloc(sizeof(int)*(simpile.len));
	ft_int_tab_cpy(simpile.vals, pile.vals, simpile.len);
	i = 0;
	while (i <= simpile.len)
	{
		if (arr_sort_desc(simpile.vals, simpile.len))
		{
			free(simpile.vals);
			return (1);
		}
		rotate_nc(simpile);
		i++;
	}
	free(simpile.vals);
	return (0);
}
