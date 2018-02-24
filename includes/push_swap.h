/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 14:34:34 by dsaadia           #+#    #+#             */
/*   Updated: 2018/02/24 19:08:59 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define LPE(Pile,Offset) (Pile).vals[(Pile).len - Offset]

#include "libft.h"

typedef struct		s_pile
{
	int			len;
	int			*vals;
	char		name;
}					t_pile;

t_pile create_a(char **nums);
t_pile create_b(int blen);
void swap(t_pile *pile, int wr);
void sswap(t_pile *apile, t_pile *bpile, int wr);
void rotate(t_pile *pile, int wr);
void rrotate(t_pile *apile, t_pile *bpile, int wr);
void rev_rotate(t_pile *pile, int wr);
void rrev_rotate(t_pile *apile, t_pile *bpile, int wr);
void push(t_pile *from_pile, t_pile *to_pile, int wr);
void view_pile(t_pile pile);

t_list *g_ops;

#endif
