/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 15:16:51 by dsaadia           #+#    #+#             */
/*   Updated: 2018/02/28 20:26:39 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int valid_input(char **argv)
{
	int verb;
	int i;

	i = 1;
	verb = (ft_strequ(argv[1],"-v")) ? 1 : 0;
	i = (verb) ? (i + 1) : i;
	if (!(argv[i]))
		return (0);
	while (argv[i])
	{
		if (!ft_isnumstr(argv[i]) || ft_atoi(argv[i]) < -2147483648
		|| ft_atoi(argv[i]) > 2147483647)
			return (0);
		i++;
	}
	return (1);
}

char **valid_one_input(char *av1)
{
	int verb;
	char **args;
	int i;

	if (!(args = ft_strsplit(av1, ' ')))
		return (0);
	i = 0;
	verb = (ft_strequ(args[0],"-v")) ? 1 : 0;
	i = (verb) ? (i + 1) : i;
	if (!(args[i]))
	{
		ft_free_strtab(args);
		return (0);
	}
	while (args[i])
	{
		if (!ft_isnumstr(args[i]) || ft_atoi(args[i]) < -2147483648
		|| ft_atoi(args[i]) > 2147483647)
		{
			ft_free_strtab(args);
			return (0);
		}
		i++;
	}
	return (args);
}

t_pile get_ps_apile(char **argv, int argc)
{
	char **one;
	t_pile apile;
	int i;
	int verb;

	i = -1;
	if ((verb = 0) >= 0 && argc == 2 && (one = valid_one_input(argv[1])))
	{
		verb = (ft_strequ(one[0],"-v")) ? 1 : 0;
		apile = create_a(((verb) ? (one + 1) : one));
		ft_free_strtab(one);
	}
	else if ((argc < 2 || !(valid_input(argv))) && (apile.len = -1))
		apile.vals = 0;
	else
	{
		argv++;
		verb = (ft_strequ(*argv,"-v")) ? 1 : 0;
		argv = (verb) ? (argv + 1) : argv;
		apile = create_a(argv);
	}
	return (apile);
}

void print_delete_g_ops(t_list *lst)
{
	t_list *k;

	k = 0;
	while (lst)
	{
		ft_putendl((char*)(lst->content));
		lst = lst->next;
	}
	while (k)
	{
		lst = k;
		k = k->next;
		free(lst->content);
		free(lst);
	}
}
