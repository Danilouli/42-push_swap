/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 16:15:48 by dsaadia           #+#    #+#             */
/*   Updated: 2018/02/16 17:54:21 by schmurz          ###   ########.fr       */
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

int ind_where_max_order(t_pile apile)
{
	int i;
	int j;
	int order;
	int where_order;
	int k;
	int val1;
	int val2;

	i = 0;
	j = 0;
	k = 0;
	order = 0;
	while (i < apile.len)
	{
		j = 0;
		k = i;
		val1 = ((i >= (apile.len)) ? apile.vals[i - apile.len] : apile.vals[i]);
		val2 = (((i + 1) >= (apile.len)) ? apile.vals[i + 1 - apile.len] : apile.vals[i + 1]);
		while (val1 < val2)
		{
			j++;
			i++;
			val1 = ((i >= (apile.len)) ? apile.vals[i - apile.len] : apile.vals[i]);
			val2 = (((i + 1) >= (apile.len)) ? apile.vals[i + 1 - apile.len] : apile.vals[i + 1]);
		}
		i++;
		if (j > order)
		{
			order = j;
			where_order = k;
		}
	}
	return (where_order);
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
	int ind;
	int maxpassed;
	int old_first;
	int firstmaxpassed;

	maxpassed = 0;
	old_first = 0;
	max = ft_get_max(apile->vals, apile->len);
	br = 0;
	wb = val_where_break(*apile);
	ind = ind_where_max_order(*apile);
	i = -1;
	while (++i < ind)
		rotate(apile);
	ft_putendl("apres ind rot");
	view_pile(*apile);
	first = (apile->vals)[0];
	wb = val_where_break(*apile);
	ft_printf("First %d WB %d\n",first, wb);
	while ((apile->vals)[0] != wb)
	{
		rotate(apile);
	}
	push(apile, bpile);
	ft_putendl("apres excl wb");
	view_pile(*apile);
	while ((apile->vals)[0] != first)
	{
		ft_printf("tete %d\n",(apile->vals)[0]);
		if ((apile->vals)[(apile->len - 1)] == max)
		{
			ft_putendl("cas max !");
			if (!maxpassed && (apile->vals)[0] < first)
			{
				ft_putendl("premier ok max");
				old_first = first;
				first = (apile->vals)[0];
				rotate(apile);
				maxpassed = 1;
			}
			else if (maxpassed && (apile->vals)[0] > first && (apile->vals)[0] < old_first)
			{
				ft_putendl("post ok max");
				first = (apile->vals)[0];
				rotate(apile);
			}
			else
			{
				ft_putendl("pas ok max");
				push(apile, bpile);
			}
			ft_putendl("APILE");
			view_pile(*apile);
			ft_putendl("BPILE");
			view_pile(*bpile);
		}
		else if ((apile->vals)[0] < (apile->vals)[(apile->len - 1)])
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
	int ind;

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
	ind = ind_where_max_order(apile);
	ft_printf("Ind %d\n",ind);
	push_keep_max(&apile, &bpile);
	ft_putendl("Pile B");
	view_pile(bpile);
	ft_putendl("Pile A");
	view_pile(apile);
	return (0);
}
