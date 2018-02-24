/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 14:43:54 by dsaadia           #+#    #+#             */
/*   Updated: 2018/02/24 19:09:31 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_a_len(char **nums)
{
	int ret;
	long long nb;

	ret = 0;
	while (*nums)
	{
		if (!ft_isnumstr(*nums))
			return (-1);
		nb = ft_atoi(*nums);
		if (nb > 2147483647 || nb < -2147483648)
			return (-1);
		nums++;
		ret++;
	}
	return (ret);
}

t_pile create_a(char **nums)
{
	t_pile ret;
	int *vals;
	int len;
	int i;

	if (((len = get_a_len(nums)) == -1) || !(vals = (int*)malloc(len * sizeof(int))))
	{
		ret.len = len;
		ret.vals = 0;
		return (ret);
	}
	i = 0;
	while (*nums)
	{
		vals[i] = (int)ft_atoi(*nums);
		nums++;
		i++;
	}
	ret.len = len;
	ret.vals = vals;
	ret.name = 'A';
	return (ret);
}

t_pile create_b(int blen)
{
	t_pile ret;
	int *vals;
	int i;

	if (!(vals = (int*)malloc(blen * sizeof(int))))
	{
		ret.len = 0;
		ret.vals = 0;
		return (ret);
	}
	i = 0;
	while (i < blen)
	{
		vals[i] = 0;
		i++;
	}
	ret.len = 0;
	ret.vals = vals;
	ret.name = 'B';
	return (ret);
}
