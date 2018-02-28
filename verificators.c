/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verificators.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schmurz <schmurz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 17:03:10 by schmurz           #+#    #+#             */
/*   Updated: 2018/02/28 18:44:40 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int arr_sort_asc(int *tab, int len)
{
	int i;

	i = 0;
	while (i < len - 1)
	{
		if (tab[i] > tab[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int pile_is_sort(t_pile pile)
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
		if (arr_sort_asc(simpile.vals, simpile.len))
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

int right_in_keeppile(t_pile apile, t_pile kpile)
{
	int i;

	i = 0;
	while (!ft_in_array(apile.vals[i], kpile.vals, kpile.len) && i < apile.len)
		i++;
	return(apile.vals[i]);
}

int left_in_keeppile(t_pile apile, t_pile kpile)
{
	int i;

	i = apile.len - 1;
	while (!ft_in_array(apile.vals[i], kpile.vals, kpile.len) && i >= 0)
		i--;
	return(apile.vals[i]);
}

int	good_to_push(t_pile apile, int num, t_pile kpile)
{
	return (
		(left_in_keeppile(apile, kpile) < num && num < right_in_keeppile(apile, kpile))
		|| (num > ft_intarr_max(kpile.vals, kpile.len) && left_in_keeppile(apile, kpile) == ft_intarr_max(kpile.vals, kpile.len))
		|| (num < ft_intarr_min(kpile.vals, kpile.len) && right_in_keeppile(apile, kpile) == ft_intarr_min(kpile.vals, kpile.len))
	);
}

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
