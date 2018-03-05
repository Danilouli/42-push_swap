/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verificators.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schmurz <schmurz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 17:03:10 by schmurz           #+#    #+#             */
/*   Updated: 2018/03/05 14:44:58 by schmurz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	arr_sort_asc(int *tab, int len)
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

int	pile_is_sort(t_pile pile)
{
	int		i;
	t_pile	simpile;

	simpile.len = pile.len;
	simpile.name = pile.name;
	simpile.vals = (int*)malloc(sizeof(int) * (simpile.len));
	ft_int_tab_cpy(simpile.vals, pile.vals, simpile.len);
	i = 0;
	while (i <= simpile.len + 1)
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

int	right_in_keeppile(t_pile apile, t_pile kpile)
{
	int i;

	i = 0;
	while (!ft_in_array(apile.vals[i], kpile.vals, kpile.len) && i < apile.len)
		i++;
	return (apile.vals[i]);
}

int	left_in_keeppile(t_pile apile, t_pile kpile)
{
	int i;

	i = apile.len - 1;
	while (!ft_in_array(apile.vals[i], kpile.vals, kpile.len) && i >= 0)
		i--;
	return (apile.vals[i]);
}

int	good_to_push(t_pile apile, int num, t_pile kpile)
{
	return (
		(left_in_keeppile(apile, kpile) < num
			&& num < right_in_keeppile(apile, kpile))
		|| (num > ft_intarr_max(kpile.vals, kpile.len)
			&& left_in_keeppile(apile, kpile)
			== ft_intarr_max(kpile.vals, kpile.len))
		|| (num < ft_intarr_min(kpile.vals, kpile.len)
			&& right_in_keeppile(apile, kpile)
			== ft_intarr_min(kpile.vals, kpile.len)));
}
