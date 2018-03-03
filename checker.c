/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 12:30:58 by dsaadia           #+#    #+#             */
/*   Updated: 2018/03/03 11:46:03 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	if_forest(t_pile *apile, t_pile *bpile, char *line)
{
	if (ft_strequ(line, "sa"))
		swap(apile, 0);
	else if (ft_strequ(line, "sb"))
		swap(bpile, 0);
	else if (ft_strequ(line, "ss"))
		sswap(apile, bpile, 0);
	else if (ft_strequ(line, "pa"))
		push(bpile, apile, 0);
	else if (ft_strequ(line, "pb"))
		push(apile, bpile, 0);
	else if (ft_strequ(line, "ra"))
		rotate(apile, 0);
	else if (ft_strequ(line, "rb"))
		rotate(bpile, 0);
	else if (ft_strequ(line, "rr"))
		rrotate(apile, bpile, 0);
	else if (ft_strequ(line, "rra"))
		rev_rotate(apile, 0);
	else if (ft_strequ(line, "rrb"))
		rev_rotate(bpile, 0);
	else if (ft_strequ(line, "rrr"))
		rrev_rotate(apile, bpile, 0);
}

static int	bad_command(char *line)
{
	return (!ft_strequ(line, "sa") && !ft_strequ(line, "sb")
	&& !ft_strequ(line, "ss") && !ft_strequ(line, "pa")
	&& !ft_strequ(line, "pb") && !ft_strequ(line, "ra")
	&& !ft_strequ(line, "rb") && !ft_strequ(line, "rr")
	&& !ft_strequ(line, "rra") && !ft_strequ(line, "rrb")
	&& !ft_strequ(line, "rrr"));
}

static void	checker(t_pile *apile, t_pile *bpile, int verb)
{
	char *line;

	(verb) ? ft_putendl("On commence le checker :") : (verb = verb * 1);
	(verb) ? view_piles(*apile, *bpile) : (verb = verb * 1);
	while (get_next_line(0, &line))
	{
		(verb) ? ft_printf("\n--\nCommande : %s\n", line) : (verb = verb * 1);
		if_forest(apile, bpile, line);
		if (bad_command(line))
		{
			ft_putendl_fd("Error", 2);
			free(line);
			exit(EXIT_SUCCESS);
		}
		free(line);
		(verb) ? view_piles(*apile, *bpile) : (verb = verb * 1);
	}
}

t_pile		get_apile(char **argv, int *verb, int argc)
{
	char	**one;
	t_pile	apile;
	int		i;

	i = -1;
	if (argc == 2 && (one = valid_one_input(argv[1])))
	{
		*verb = (ft_strequ(one[0], "-v")) ? 1 : 0;
		apile = create_a(((*verb) ? (one + 1) : one));
		ft_free_strtab(one);
	}
	else if ((argc < 2 || !(valid_input(argv))) && (apile.len = -1))
		apile.vals = 0;
	else
	{
		argv++;
		*verb = (ft_strequ(*argv, "-v")) ? 1 : 0;
		argv = (*verb) ? (argv + 1) : argv;
		apile = create_a(argv);
	}
	return (apile);
}

int			main(int argc, char **argv)
{
	t_pile	apile;
	t_pile	bpile;
	int		flen;
	int		verb;

	apile = get_apile(argv, &verb, argc);
	if (apile.len == -1)
	{
		ft_putendl_fd("Error", 2);
		return (1);
	}
	bpile = create_b(apile.len);
	flen = apile.len;
	checker(&apile, &bpile, verb);
	(arr_sort_asc(apile.vals, apile.len) && apile.len == flen) ?
	ft_putendl("OK") : ft_putendl("KO");
	(verb) ? ft_putendl("Resultat :") : (verb = verb * 1);
	(verb) ? view_piles(apile, bpile) : (verb = verb * 1);
	free(apile.vals);
	free(bpile.vals);
	return (0);
}
