/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 14:34:34 by dsaadia           #+#    #+#             */
/*   Updated: 2018/02/27 17:36:43 by schmurz          ###   ########.fr       */
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
void rotate_nc(t_pile pile);
void rev_rotate_nc(t_pile pile);
t_pile  max_order_in_tab(int *x, int n);
int ft_is_sort(int *tab, int len);
int pile_is_sort(t_pile pile);
int	good_to_push(t_pile apile, int num, t_pile kpile);

t_list *g_ops;

#endif
