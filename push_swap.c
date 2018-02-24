/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 16:15:48 by dsaadia           #+#    #+#             */
/*   Updated: 2018/02/24 19:47:41 by dsaadia          ###   ########.fr       */
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

int* max_order_in_tab(int *tab, int len, int *reslen)
{
	int *res;
	int i;
	int post_ct;
	int k;
	int j;
	int l;

	i = 0;
	j = 0;
	*reslen = 1;
	res = (int*)malloc(sizeof(int)*len);
	while (tab[i] < tab[i + 1])
	{
		res[i] = tab[i];
		i++;
		(*reslen)++;
	}
	res[i] = tab[i];
	i++;
	while (i < len)
	{
		k = i;
		post_ct = 1;
		while (i < len - 1 && tab[i] < tab[i + 1])
		{
			post_ct++;
			i++;
		}
		if (res[0] < tab[k] && (*reslen < post_ct || res[*reslen - post_ct] < tab[k]))
		{
			j = 1;
			while (res[*reslen - j] > tab[k])
			{
				j++;
			}
			l = 1;
			*reslen = (*reslen - j + 1 > 0) ? (*reslen - j + 1) : 1;
			while (l <= post_ct)
			{
				res[*reslen + l - 1] = tab[k + l - 1];
				l++;
			}
			*reslen = *reslen + post_ct;
		}
		i = k + 1;
	}
	return (res);
}

void push_max_order(t_pile *apile, t_pile *bpile, int *maxtab, int maxtab_len)
{
	while (apile->len > maxtab_len)
	{
		if (!ft_in_array((apile->vals)[0], maxtab, maxtab_len))
			push(apile, bpile, 1);
		else
			rotate(apile, 1);
		if ((bpile->vals[0]) < (apile->vals[0]))
		{
			push(bpile, apile, 1);
			rotate(apile, 1);
		}
		ft_putendl("----Pile A DANS LE MACHIN----");
		view_pile(*apile);
	}
}

int find_just_above(t_pile apile, int num, int *place)
{
	int i;
	int max;
	int min;

	i = 0;
	*place = 0;
	max = ft_get_max(apile.vals, apile.len);
	min = ft_get_min(apile.vals, apile.len);
	while (i <= apile.len)
	{
		if ((num > max || num < min) && apile.vals[1] == min)
			break ;
		if (apile.vals[0] < num && num < apile.vals[1])
			return (apile.vals[1]);
		(*place)++;
		i++;
		rotate(&apile, 0);
	}
	return (min);
}

void re_push_good(t_pile *apile, t_pile *bpile)
{
	int jabove;
	int place;
	int i;

	i = 0;
	while (bpile->len > 0)
	{
		jabove = find_just_above(*apile, (bpile->vals)[0], &place);
		if (place <= (apile->len) / 2)
		{
			while ((apile->vals)[0] != jabove)
				rotate(apile, 1);
		}
		else
		{
			while ((apile->vals)[0] != jabove)
				rev_rotate(apile, 1);
		}
		push(bpile, apile, 1);
		i++;
	}
}

void rotate_finish(t_pile *apile)
{
	int min;

	min = ft_get_min(apile->vals, apile->len);
	if (min <= (apile->len) / 2)
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

int* tab_max_order(t_pile apile, int *tablen)
{
	int k;
	int j;
	int *keeptab;
	int *tab;

	j = 0;
	k = 0;
	tab = 0;
	keeptab = 0;
	*tablen = 0;
	while (j < apile.len)
	{
		tab = max_order_in_tab(apile.vals, apile.len, tablen);
		if (*tablen > k)
		{
			k = *tablen;
			keeptab = tab;
		}
		rotate(&apile, 0);
		j++;
	}
	*tablen = k;
	return (keeptab);
}

int main(int argc, char **argv) {
	int	i;
 	t_pile apile;
	t_pile bpile;
	int ind;
	int *test;

	if (argc < 2)
		return (1);
	argv++;
	i = 0;
	apile = create_a(argv);
	bpile = create_b(apile.len);
	ft_putendl("Pile B");
	view_pile(bpile);
	ft_putendl("Pile A");
	view_pile(apile);
	test = tab_max_order(apile, &ind);
	push_max_order(&apile, &bpile, test, ind);
	ft_putendl("Pile A apres que tri");
	view_pile(apile);
	ft_putendl("Pile B reste que tri");
	view_pile(bpile);
	re_push_good(&apile, &bpile);
	ft_putendl("Pile A apres re_push_good");
	view_pile(apile);
	ft_putendl("Pile B apres re_push_good");
	view_pile(bpile);
	rotate_finish(&apile);
	ft_putendl("Pile A apres rotate_finish");
	view_pile(apile);
	ft_putendl("Pile B apres rotate_finish");
	view_pile(bpile);
	ft_lstreverse(&g_ops);
	while (g_ops)
	{
		i++;
		// ft_putendl((char*)(g_ops->content));
		g_ops = g_ops->next;
	}
	ft_printf("%d operations \n",i);
	return (0);
}
