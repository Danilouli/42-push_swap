/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 16:15:48 by dsaadia           #+#    #+#             */
/*   Updated: 2018/03/03 19:36:23 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	min_mover(t_pile *apile, t_pile *bpile, t_pile *keeppile)
{
	int	d[6];

	d[0] = dist_rrotating(*apile, *bpile, *keeppile);
	d[1] = dist_rrev_rotating(*apile, *bpile, *keeppile);
	d[2] = dist_rotating_a(*apile, *bpile, *keeppile);
	d[3] = dist_rev_rotating_a(*apile, *bpile, *keeppile);
	d[4] = dist_rotating_b(*apile, *bpile, *keeppile);
	d[5] = dist_rev_rotating_b(*apile, *bpile, *keeppile);
	if (d[0] && d[0] < ft_min_nums(6, d[0], d[1], d[2], d[3], d[4], d[5])
		&& !ft_strequ((char*)(g_ops->content), "rrr"))
		rrotate(apile, bpile, 1);
	else if (d[1] && d[1] <= ft_min_nums(5, d[1], d[2], d[3], d[4], d[5])
		&& !ft_strequ((char*)(g_ops->content), "rr"))
		rrev_rotate(apile, bpile, 1);
	else if (d[2] <= ft_min_nums(4, d[2], d[3], d[4], d[5])
		&& !ft_strequ((char*)(g_ops->content), "rra"))
		rotate(apile, 1);
	else if (d[3] <= ft_min_nums(3, d[3], d[4], d[5])
		&& !ft_strequ((char*)(g_ops->content), "ra"))
		rev_rotate(apile, 1);
	else if (d[4] <= ft_min_nums(2, d[4], d[5])
		&& !ft_strequ((char*)(g_ops->content), "rrb"))
		rotate(bpile, 1);
	else if (!ft_strequ((char*)(g_ops->content), "rb"))
		rev_rotate(bpile, 1);
}

int		first_cases(t_pile *apile, t_pile *bpile, t_pile *keeppile)
{
	int gts;

	gts = 0;
	if (!ft_in_array((apile->vals)[0], keeppile->vals, keeppile->len)
	&& good_to_push(*apile, apile->vals[0], *keeppile))
	{
		ft_intarr_push(&(keeppile->vals), &(keeppile->len), apile->vals[0]);
		return (1);
	}
	else if ((gts = good_to_swap(apile, keeppile)) >= 0)
	{
		ft_intarr_push(&(keeppile->vals), &(keeppile->len), apile->vals[gts]);
		swap(apile, 1);
		return (1);
	}
	else if (bpile->len > 0
			&& good_to_push(*apile, (bpile->vals)[0], *keeppile))
	{
		ft_intarr_push(&(keeppile->vals), &(keeppile->len), bpile->vals[0]);
		push(bpile, apile, 1);
		return (1);
	}
	return (0);
}

void	push_max_order(t_pile *apile, t_pile *bpile, t_pile *keeppile)
{
	int final_len;
	int is_sort;

	final_len = apile->len;
	is_sort = pile_is_sort(*apile);
	while (!(is_sort && apile->len == final_len))
	{
		if (final_len > 450 || !first_cases(apile, bpile, keeppile))
		{
			if (final_len > 450)
				first_cases(apile, bpile, keeppile);
			if (!ft_in_array((apile->vals)[0], keeppile->vals, keeppile->len))
				push(apile, bpile, 1);
			else if (bpile->len > 0 && is_sort)
				min_mover(apile, bpile, keeppile);
			else if (ft_in_array((apile->vals)[0], keeppile->vals,
						keeppile->len))
				(rotate_a_or_both(apile, bpile, keeppile)) ?
				rrotate(apile, bpile, 1) : rotate(apile, 1);
		}
		if (!is_sort)
			is_sort = pile_is_sort(*apile);
	}
}

void	rotate_finish(t_pile *apile)
{
	int min_way;
	int min;

	min = ft_intarr_min(apile->vals, apile->len);
	min_way = final_rra_or_ra(*apile);
	if (min_way)
	{
		while ((apile->vals)[0] != min)
			rotate(apile, 1);
	}
	else
	{
		while ((apile->vals)[0] != min)
			rev_rotate(apile, 1);
	}
}

int		main(int argc, char **argv)
{
	t_pile apile;
	t_pile bpile;
	t_pile keeppile;
	t_pile simpile;

	apile = get_ps_apile(argv, argc);
	if (apile.len == -1 && ft_free_all(1, apile.vals))
	{
		if (argc > 1)
			ft_putendl_fd("Error", 2);
		return (1);
	}
	simpile = copy_pile(apile);
	if (!arr_sort_asc(simpile.vals, simpile.len))
		keeppile = pile_max_order(simpile);
	else
		keeppile.len = -1;
	bpile = create_b(apile.len);
	push_max_order(&apile, &bpile, &keeppile);
	rotate_finish(&apile);
	ft_lstreverse(&g_ops);
	print_delete_g_ops(g_ops);
	ft_free_all(3, apile.vals, bpile.vals, simpile.vals);
	(keeppile.len != -1) ? free(keeppile.vals) : (keeppile.len = 0);
	return (0);
}
