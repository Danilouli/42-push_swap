/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itows.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 13:46:16 by dsaadia           #+#    #+#             */
/*   Updated: 2018/01/30 18:32:28 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t	*ft_itows(int nb)
{
	wchar_t *wstr;

	if (!nb)
		return (ft_wstrdup(L"\0"));
	if (!(wstr = ft_wstrnew(2)))
		return (0);
	wstr[0] = (wchar_t)nb;
	wstr[1] = 0;
	return (wstr);
}
