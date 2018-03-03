/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_dist_and_cppile.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 12:49:50 by dsaadia           #+#    #+#             */
/*   Updated: 2018/03/03 11:49:14 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		dist_rrev_rotating(t_pile apile, t_pile bpile, t_pile keeppile)
{
	int		i;
	t_pile	asimpile;
	t_pile	bsimpile;

	asimpile = copy_pile(apile);
	bsimpile = copy_pile(bpile);
	i = 0;
	while (!(good_to_push(asimpile, bsimpile.vals[0], keeppile))
	&& i <= apile.len)
	{
		rrev_rotate(&asimpile, &bsimpile, 0);
		i++;
	}
	free(bsimpile.vals);
	free(asimpile.vals);
	return (i);
}

int		find_just_above(int num, t_pile keeppile)
{
	int i;
	int jabove;
	int k;

	k = num;
	jabove = num;
	i = 0;
	while (i < keeppile.len)
	{
		if (num < keeppile.vals[i])
		{
			k = keeppile.vals[i];
			if (k < jabove || jabove == num)
				jabove = keeppile.vals[i];
		}
		i++;
	}
	return (jabove);
}

int		find_just_under(int num, t_pile keeppile)
{
	int i;
	int junder;
	int k;

	k = num;
	junder = num;
	i = 0;
	while (i < keeppile.len)
	{
		if (num > keeppile.vals[i])
		{
			k = keeppile.vals[i];
			if (k > junder || junder == num)
				junder = keeppile.vals[i];
		}
		i++;
	}
	return (junder);
}

int		final_rra_or_ra(t_pile apile)
{
	t_pile	asimpile;
	int		min;
	int		ra;
	int		rra;

	asimpile = copy_pile(apile);
	ra = 0;
	rra = 0;
	min = ft_intarr_min(asimpile.vals, asimpile.len);
	while ((asimpile.vals)[0] != min)
	{
		rotate_nc(asimpile);
		ra++;
	}
	free(asimpile.vals);
	asimpile = copy_pile(apile);
	while ((asimpile.vals)[0] != min)
	{
		rev_rotate_nc(asimpile);
		rra++;
	}
	free(asimpile.vals);
	return ((ra < rra) ? 1 : 0);
}

t_pile	copy_pile(t_pile pile)
{
	t_pile simpile;

	simpile.len = pile.len;
	simpile.name = pile.name;
	simpile.vals = (int*)malloc(sizeof(int) * (simpile.len));
	simpile.vals = ft_int_tab_cpy(simpile.vals, pile.vals, simpile.len);
	return (simpile);
}
