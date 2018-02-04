/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 14:43:54 by dsaadia           #+#    #+#             */
/*   Updated: 2018/02/04 15:48:42 by dsaadia          ###   ########.fr       */
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

int *create_a(char **nums, int *len)
{
	int *ret;
	int i;

	if ((*len = get_a_len(nums)) == -1)
	 	return (NULL);
	if (!(ret = (int*)malloc(*len * sizeof(int))))
		return (NULL);
	i = 0;
	while (*nums)
	{
		ret[i] = (int)ft_atoi(*nums);
		nums++;
		i++;
	}
	return (ret);
}
