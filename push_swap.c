/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 16:15:48 by dsaadia           #+#    #+#             */
/*   Updated: 2018/02/14 23:32:59 by schmurz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_max(int *tab, int len)
{
	int i;
	int max;

	i = -1;
	max = tab[0];
	while (++i < len)
		max = (tab[i] > max) ? tab[i] : max;
	return (max);
}

int	ft_get_min(int *tab, int len)
{
	int i;
	int min;

	i = -1;
	min = tab[0];
	while (++i < len)
		min = (tab[i] < min) ? tab[i] : min;
	return (min);
}

int	val_where_break(t_pile apile)
{
	int i;

	i = 0;
	while (i < apile.len)
	{
		if (apile.vals[i] > apile.vals[i + 1])
			return (apile.vals[i + 1]);
		i++;
	}
	return (0);
}

void push_keep_max(t_pile *apile, t_pile *bpile)
{
	int wb;
	int i;
	int first;
	int br;
	int max;

	max = ft_get_max(apile->vals, apile->len);
	br = 0;
	wb = val_where_break(*apile);
	first = (apile->vals)[0];
		rotate(apile);
	while ((apile->vals)[0] != wb)
	{
		rotate(apile);
	}
	push(apile, bpile);
	while ((apile->vals)[0] != first)
	{
		if ((apile->vals)[(apile->len - 1)] == max)
		{
			if ((apile->vals)[0] > first)
				push(apile, bpile);
			else
				rotate(apile);
		}
		if ((apile->vals)[0] < (apile->vals)[(apile->len - 1)])
			push(apile, bpile);
		else
			rotate(apile);
	}
}

int main(int argc, char **argv) {
	int	i;
 	t_pile apile;
	t_pile bpile;
	int max;
	int min;
	int tmp;

	if (argc < 2)
		return (1);
	argv++;
	i = 0;
	tmp = 0;
	apile = create_a(argv);
	bpile = create_b(apile.len);
	max = ft_get_max(apile.vals, apile.len);
	min = ft_get_min(apile.vals, apile.len);
	ft_putendl("Pile B");
	view_pile(bpile);
	ft_putendl("Pile A");
	view_pile(apile);
	ft_printf("Max %d , Min %d\n", max, min);
	push_keep_max(&apile, &bpile);
	ft_putendl("Pile B");
	view_pile(bpile);
	ft_putendl("Pile A");
	view_pile(apile);
	return (0);
}
