/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_max_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schmurz <schmurz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 08:31:23 by schmurz           #+#    #+#             */
/*   Updated: 2018/03/17 20:52:38 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_j(int *x, int *m, int l, int i)
{
	int j;
	int ret;

	j = 1;
	ret = 0;
	while (j <= l)
	{
		if (x[m[j]] < x[i] && j > ret)
			ret = j;
		j++;
	}
	return (ret);
}

static int	fill_m_and_p(t_pile *m, t_pile *p, int *x, int n)
{
	int i;
	int l;
	int j;

	i = 0;
	l = 0;
	j = 0;
	while (i < n)
	{
		j = find_j(x, m->vals, l, i);
		p->len = i + 1;
		p->vals[i] = m->vals[j];
		if (j == l || x[i] < x[m->vals[j + 1]])
		{
			l = (l > j + 1) ? l : (j + 1);
			m->len = l + 1;
			m->vals[j + 1] = i;
		}
		i++;
	}
	return (l);
}

static void	fill_ret(t_pile *ret, t_pile m, t_pile p, int *x)
{
	int i;
	int j;

	i = 0;
	j = m.vals[ret->len];
	while (i < ret->len)
	{
		ret->vals[i] = x[j];
		j = p.vals[j];
		i++;
	}
}

t_pile		max_order_in_tab(int *x, int n)
{
	t_pile m;
	t_pile p;
	t_pile ret;

	m.len = 1;
	if (!(m.vals = (int*)malloc(sizeof(int) * n)))
		exit(EXIT_FAILURE);
	p.len = 1;
	if (!(p.vals = (int*)malloc(sizeof(int) * n)))
		exit(EXIT_FAILURE);
	ret.len = 1;
	if (!(ret.vals = (int*)malloc(sizeof(int) * n)))
		exit(EXIT_FAILURE);
	m.vals[0] = 0;
	ret.len = fill_m_and_p(&m, &p, x, n);
	fill_ret(&ret, m, p, x);
	free(m.vals);
	free(p.vals);
	ft_intarr_rev(&(ret.vals), ret.len);
	return (ret);
}

t_pile		pile_max_order(t_pile apile)
{
	int		k;
	int		j;
	t_pile	tmppile;
	t_pile	keeppile;

	j = 0;
	k = 0;
	tmppile.len = 0;
	keeppile.len = 0;
	keeppile.vals = 0;
	while (j <= apile.len)
	{
		tmppile = max_order_in_tab(apile.vals, apile.len);
		if (tmppile.len > k)
		{
			k = tmppile.len;
			free(keeppile.vals);
			keeppile = tmppile;
		}
		else
			free(tmppile.vals);
		rotate_nc(apile);
		j++;
	}
	return (keeppile);
}
