/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min_nums.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schmurz <schmurz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 14:08:16 by schmurz           #+#    #+#             */
/*   Updated: 2018/02/27 19:09:08 by schmurz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_min_nums(int arg_count, ...)
{
    int i;
    int min;
    int a;

    i = 1;
    va_list ap;
    va_start(ap, arg_count);
    min = va_arg(ap, int);
    while (i < arg_count)
    {
      if ((a = va_arg(ap, int)) < min)
          min = a;
      i++;
    }
    va_end(ap);
    return min;
}
