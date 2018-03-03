/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verificators2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schmurz <schmurz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 18:33:50 by schmurz           #+#    #+#             */
/*   Updated: 2018/03/03 12:03:07 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	good_to_swap(t_pile *apile, t_pile *keeppile)
{
	if (!ft_in_array((apile->vals)[0], keeppile->vals, keeppile->len)
				&& ft_in_array((apile->vals)[1], keeppile->vals, keeppile->len)
				&& (apile->vals)[0] > (apile->vals)[1]
				&& (find_just_above((apile->vals)[0], *keeppile)
				== find_just_above((apile->vals)[1], *keeppile)
				|| (apile->vals)[1]
				== ft_intarr_max(keeppile->vals, keeppile->len)))
		return (0);
	if (ft_in_array((apile->vals)[0], keeppile->vals, keeppile->len)
			&& !ft_in_array((apile->vals)[1], keeppile->vals, keeppile->len)
			&& (apile->vals)[0] > (apile->vals)[1]
			&& (find_just_under((apile->vals)[0], *keeppile)
			== find_just_under((apile->vals)[1], *keeppile)
			|| (apile->vals)[0]
			== ft_intarr_min(keeppile->vals, keeppile->len)))
		return (1);
	return (-1);
}

int	rotate_a_or_both(t_pile *apile, t_pile *bpile, t_pile *keeppile)
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
