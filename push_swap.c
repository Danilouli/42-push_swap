/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 16:15:48 by dsaadia           #+#    #+#             */
/*   Updated: 2018/02/12 16:54:33 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv) {
	int	i;
	int alen;
	int *atab;
	int sst;
	int *nbsst;
	int k;
	int nt;
	int *nbnt;

	piv = 0;
	if (argc < 2)
		return (1);
	argv++;
	i = 0;
	atab = create_a(argv, &alen);
	while (i < alen)
	{
		ft_printf("%d\n",atab[i]);
		i++;
	}
	i = 0;
	sst = find_sst(atab, &nbsst); //find_sst doit trouver la plus longue sous suite triee a quelques swaps pres en retournant la longueur du tru
	nt = find_nt(atab, sst, nbsst, &nbnt); //find_nt trouvera l index du reste, et sa longueur
	set_sst_aside(&atab, sst, nbsst); // set_sst_aside va mettre sst a droite de la pile
	push_nt_to_b(&atab, &btab, nt, nbsst); // on push nt dans b
	make_it(&atab, &btab); // et on termine
	return (0);
}
