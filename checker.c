/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 12:30:58 by dsaadia           #+#    #+#             */
/*   Updated: 2018/02/04 13:21:50 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int main(int argc, char **argv) {
	int fd;
	char *line;
	int ret;

	ret = 1;
	ft_printf("%s\n",argv[1]);
	fd = open(argv[1], O_RDONLY);
	ft_printf("%d\n",fd);
	while (get_next_line(fd, &line))
	{
		ft_printf("%d %s\n",ret, line);
	}
	return 0;
}
