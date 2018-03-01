/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intarr_avg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schmurz <schmurz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 19:22:02 by schmurz           #+#    #+#             */
/*   Updated: 2018/03/01 19:23:58 by schmurz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_intarr_avg(int *tab, int len)
{
  int i;
  int avg;

  i = 0;
  avg = 0;
  while (i < len)
  {
    avg = avg + tab[i];
    i++;
  }
  avg = avg / len;
  return (avg);
}
