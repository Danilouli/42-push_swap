/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 12:30:58 by dsaadia           #+#    #+#             */
/*   Updated: 2018/02/16 16:17:08 by schmurz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv) {
	int	i;
	char *line;
	t_pile apile;
	t_pile bpile;

	if (argc < 2)
		return (1);
	argv++;
	apile = create_a(argv);
	bpile = create_b(apile.len);
	ft_putendl("Pile B");
	view_pile(bpile);
	ft_putendl("Pile A");
	view_pile(apile);
	while (get_next_line(1, &line))
	{
		ft_printf("\n------\nCommande : %s\n",line);
		if (ft_strequ(line, "sa"))
			swap(&apile);
		else if (ft_strequ(line, "sb"))
			swap(&bpile);
		else if (ft_strequ(line, "ss"))
			sswap(&apile, &bpile);
		else if (ft_strequ(line, "pa"))
			push(&bpile, &apile);
		else if (ft_strequ(line, "pb"))
			push(&apile, &bpile);
		else if (ft_strequ(line, "ra"))
			rotate(&apile);
		else if (ft_strequ(line, "rb"))
			rotate(&bpile);
		else if (ft_strequ(line, "rr"))
			rrotate(&apile, &bpile);
		else if (ft_strequ(line, "rra"))
			rev_rotate(&apile);
		else if (ft_strequ(line, "rrb"))
			rev_rotate(&bpile);
		else if (ft_strequ(line, "rrr"))
			rrev_rotate(&apile, &bpile);
		else
		{
			ft_printf("Usage : sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr. Grrrrrr !\n");
			break ;
		}
		ft_putendl("\n***Pile A***");
		view_pile(apile);
		ft_putendl("\n***Pile B***");
		view_pile(bpile);
	}
	return (0);
}
