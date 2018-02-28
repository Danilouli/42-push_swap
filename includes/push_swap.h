/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 14:34:34 by dsaadia           #+#    #+#             */
/*   Updated: 2018/02/28 20:28:01 by dsaadia          ###   ########.fr       */
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
int arr_sort_asc(int *tab, int len);
int pile_is_sort(t_pile pile);
int	good_to_push(t_pile apile, int num, t_pile kpile);
int good_to_swap(t_pile *apile, t_pile *keeppile);
int find_just_above(int num, t_pile keeppile);
int find_just_under(int num, t_pile keeppile);
int dist_rotating_a(t_pile apile, t_pile bpile, t_pile keeppile);
int dist_rev_rotating_a(t_pile apile, t_pile bpile, t_pile keeppile);
int dist_rotating_b(t_pile apile, t_pile bpile, t_pile keeppile);
int dist_rev_rotating_b(t_pile apile, t_pile bpile, t_pile keeppile);
int dist_rrotating(t_pile apile, t_pile bpile, t_pile keeppile);
int dist_rrev_rotating(t_pile apile, t_pile bpile, t_pile keeppile);
int find_just_above(int num, t_pile keeppile);
int find_just_under(int num, t_pile keeppile);
t_pile copy_pile(t_pile pile);
t_pile pile_max_order(t_pile apile);
void view_piles(t_pile apile, t_pile bpile);
int valid_input(char **argv);
char **valid_one_input(char *av1);
t_pile get_ps_apile(char **argv, int argc);
void print_delete_g_ops(t_list *lst);
t_list *g_ops;

#endif
