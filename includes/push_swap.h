/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 14:34:34 by dsaadia           #+#    #+#             */
/*   Updated: 2018/02/14 22:51:00 by schmurz          ###   ########.fr       */
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
}					t_pile;

t_pile create_a(char **nums);
t_pile create_b(int blen);
void swap(t_pile *pile);
void sswap(t_pile *apile, t_pile *bpile);
void rotate(t_pile *pile);
void rrotate(t_pile *apile, t_pile *bpile);
void rev_rotate(t_pile *pile);
void rrev_rotate(t_pile *apile, t_pile *bpile);
void push(t_pile *from_pile, t_pile *to_pile);
void view_pile(t_pile pile);

#endif
