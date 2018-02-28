/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 16:15:48 by dsaadia           #+#    #+#             */
/*   Updated: 2018/02/28 12:30:49 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int min_dist(int n1, int n2, int n3, int n4) {
    int min;

		min = n1;
		if (n2 < n1)
			min = n2;
		if (n3 < n2)
			min = n3;
		if (n4 < n3)
			min = n4;
		return (min);
}

int find_just_above(int num, t_pile keeppile)
{
	int i;
	int jabove;
	int k;

	k = num;
	jabove = num;
	i = 0;
	while (i < keeppile.len)
	{
		if (num < keeppile.vals[i])
		{
			k = keeppile.vals[i];
			if (k < jabove || jabove == num)
				jabove = keeppile.vals[i];
		}
		i++;
	}
	return (jabove);
}

int find_just_under(int num, t_pile keeppile)
{
	int i;
	int junder;
	int k;

	k = num;
	junder = num;
	i = 0;
	while (i < keeppile.len)
	{
		if (num > keeppile.vals[i])
		{
			k = keeppile.vals[i];
			if (k > junder || junder == num)
				junder = keeppile.vals[i];
		}
		i++;
	}
	return (junder);
}

t_pile copy_pile(t_pile pile)
{
	t_pile simpile;

	simpile.len = pile.len;
	simpile.name = pile.name;
	simpile.vals = (int*)malloc(sizeof(int)*(simpile.len));
	simpile.vals = ft_int_tab_cpy(simpile.vals, pile.vals, simpile.len);
	return (simpile);
}

int dist_rotating_a(t_pile apile, t_pile bpile, t_pile keeppile)
{
	int i;
	t_pile asimpile;
	t_pile bsimpile;

	asimpile = copy_pile(apile);
	bsimpile = copy_pile(bpile);
	i = 0;
	while (!(good_to_push(asimpile, bsimpile.vals[0], keeppile)) && i <= apile.len)
	{
		rotate_nc(asimpile);
		i++;
	}
	free(asimpile.vals);
	free(bsimpile.vals);
	return(i);
}

int dist_rev_rotating_a(t_pile apile, t_pile bpile, t_pile keeppile)
{
	int i;
	t_pile asimpile;
	t_pile bsimpile;

	asimpile = copy_pile(apile);
	bsimpile = copy_pile(bpile);
	i = 0;
	while (!(good_to_push(asimpile, bsimpile.vals[0], keeppile)) && i <= apile.len)
	{
		rev_rotate_nc(asimpile);
		i++;
	}
	free(asimpile.vals);
	free(bsimpile.vals);
	return(i);
}

int dist_rotating_b(t_pile apile, t_pile bpile, t_pile keeppile)
{
	int i;
	t_pile simpile;

	simpile = copy_pile(bpile);
	i = 0;
	while (!(good_to_push(apile, simpile.vals[0], keeppile)) && i <= apile.len)
	{
		rotate_nc(simpile);
		i++;
	}
	free(simpile.vals);
	return(i);
}

int dist_rev_rotating_b(t_pile apile, t_pile bpile, t_pile keeppile)
{
	int i;
	t_pile simpile;

	simpile = copy_pile(bpile);
	i = 0;
	while (!(good_to_push(apile, simpile.vals[0], keeppile)) && i <= apile.len)
	{
		rev_rotate_nc(simpile);
		i++;
	}
	free(simpile.vals);
	return(i);
}

int dist_rrotating(t_pile apile, t_pile bpile, t_pile keeppile)
{
	int i;

	t_pile asimpile;
	t_pile bsimpile;

	asimpile = copy_pile(apile);
	bsimpile = copy_pile(bpile);
	i = 0;
	while (!(good_to_push(asimpile, bsimpile.vals[0], keeppile)) && i <= apile.len)
	{
		rrotate(&asimpile, &bsimpile, 0);
		i++;
	}
	free(bsimpile.vals);
	free(asimpile.vals);
	return(i);
}

int dist_rrev_rotating(t_pile apile, t_pile bpile, t_pile keeppile)
{
	int i;
	t_pile asimpile;
	t_pile bsimpile;

	asimpile = copy_pile(apile);
	bsimpile = copy_pile(bpile);
	i = 0;
	while (!(good_to_push(asimpile, bsimpile.vals[0], keeppile)) && i <= apile.len)
	{
		rrev_rotate(&asimpile, &bsimpile, 0);
		i++;
	}
	free(bsimpile.vals);
	free(asimpile.vals);
	return(i);
}

int min_dist_to_push(t_pile apile, t_pile bpile, t_pile keeppile)
{
	return (
		min_dist(
			dist_rotating_a(apile, bpile, keeppile),
			dist_rev_rotating_a(apile, bpile, keeppile),
			dist_rotating_b(apile, bpile, keeppile),
			dist_rev_rotating_b(apile, bpile, keeppile)
		)
	);
}

void push_max_order(t_pile *apile, t_pile *bpile, t_pile *keeppile)
{
	int min;
	int max;
	int min_dist;
	int final_len;
	int lasta;
	int ra;
	int rra;
	int rb;
	int rrb;
	int rr;
	int rrr;
	int is_sort;

	final_len = apile->len;
	min_dist = 0;
	lasta = 0;
	min = ft_intarr_min(apile->vals, apile->len);
	max = ft_intarr_max(apile->vals, apile->len);
	is_sort = pile_is_sort(*apile);
	while (!(is_sort && apile->len == final_len))
	{
		if (!ft_in_array((apile->vals)[0], keeppile->vals, keeppile->len) && good_to_push(*apile, apile->vals[0], *keeppile))
		{
			keeppile->vals[keeppile->len] = apile->vals[0];
			(keeppile->len)++;
		}
		else if (!ft_in_array((apile->vals)[0], keeppile->vals, keeppile->len) && ft_in_array((apile->vals)[1], keeppile->vals, keeppile->len)
					&& (apile->vals)[0] > (apile->vals)[1] && find_just_above((apile->vals)[0], *keeppile) == find_just_above((apile->vals)[1], *keeppile))
		{
			keeppile->vals[keeppile->len] = apile->vals[0];
			swap(apile, 1);
			(keeppile->len)++;
		}
		else if (ft_in_array((apile->vals)[0], keeppile->vals, keeppile->len) && !ft_in_array((apile->vals)[1], keeppile->vals, keeppile->len)
						&& (apile->vals)[0] > (apile->vals)[1] && find_just_under((apile->vals)[0], *keeppile) == find_just_under((apile->vals)[1], *keeppile))
		{
			keeppile->vals[keeppile->len] = apile->vals[1];
			swap(apile, 1);
			(keeppile->len)++;
		}
		else if (bpile->len > 0 && good_to_push(*apile, (bpile->vals)[0], *keeppile))
		{
			keeppile->vals[keeppile->len] = bpile->vals[0];
			push(bpile, apile, 1);
			(keeppile->len)++;
			lasta = 0;
		}
		else if (!ft_in_array((apile->vals)[0], keeppile->vals, keeppile->len))
		{
				push(apile, bpile, 1);
		}
		else if (bpile->len > 0 && is_sort)
		{
				// ft_printf("calcul de min dist\n");
				min_dist = min_dist_to_push(*apile, *bpile, *keeppile);
				// ft_printf("min dist %d\n",min_dist);
				rr = dist_rrotating(*apile, *bpile, *keeppile);
				rrr = dist_rrev_rotating(*apile, *bpile, *keeppile);
				ra = dist_rotating_a(*apile, *bpile, *keeppile);
				rra =  dist_rev_rotating_a(*apile, *bpile, *keeppile);
				rb = dist_rotating_b(*apile, *bpile, *keeppile);
				rrb = dist_rev_rotating_b(*apile, *bpile, *keeppile);
				//ft_printf("min %d rr %d rrr %d ra %d rra %d rb %d rrb %d\n",ft_min_nums(6, rr, rrr, ra, rra, rb, rrb), rr, rrr, ra, rra, rb, rrb);
				if (0 < rr && rr < ft_min_nums(6, rr, rrr, ra, rra, rb, rrb) && lasta != 2)
				{
					//ft_putendl("rr");
					rrotate(apile, bpile, 1);
					lasta = 1;
				}
				else if (0 < rrr && rrr <= ft_min_nums(5, rrr, ra, rra, rb, rrb) && lasta != 1)
				{
					//ft_putendl("rrr");
					rrev_rotate(apile, bpile, 1);
					lasta = 2;
				}
				else if (ra <= ft_min_nums(4, ra, rra, rb, rrb) && lasta != 4)
				{
					//ft_putendl("ra");
					rotate(apile, 1);
					lasta = 3;
				}
				else if (rra <= ft_min_nums(3, rra, rb, rrb) && lasta != 3)
				{
					//ft_putendl("rra");
					rev_rotate(apile, 1);
					lasta = 4;
				}
				else if (rb <= ft_min_nums(2, rb, rrb) && lasta != 6)
				{
					//ft_putendl("rb");
					rotate(bpile, 1);
					lasta = 5;
				}
				else if (lasta != 5)
				{
					//ft_putendl("rrb");
					rev_rotate(bpile, 1);
					lasta = 6;
				}
		}
		else if (ft_in_array((apile->vals)[0], keeppile->vals, keeppile->len))
		{
			rotate(apile, 1);
		}
		if (!is_sort)
			is_sort = pile_is_sort(*apile);
		// ft_putendl("----Pile A DANS LE MACHIN----");
		// view_pile(*apile);
		// ft_putendl("----Pile B DANS LE MACHIN----");
		// view_pile(*bpile);
		// ft_putendl("dans keeptab");
		// j = 0;
		// while (j < keeppile->len)
		// {
		// 	ft_printf("%d ,", keeppile->vals[j]);
		// 	j++;
		// }
		// ft_putchar('\n');
	}
}

void rotate_finish(t_pile *apile)
{
	int min;

	min = ft_intarr_min(apile->vals, apile->len);
	if (min <= (apile->len) / 2)
	{
		while ((apile->vals)[0] != min)
			rotate(apile, 1);
	}
	else
	{
		while ((apile->vals)[0] != min)
			rev_rotate(apile, 1);
	}
}

t_pile pile_max_order(t_pile apile)
{
	int k;
	int j;
	t_pile tmppile;
	t_pile keeppile;

	j = 0;
	k = 0;
	tmppile.len = 0;
	tmppile.vals = 0;
	keeppile.len = 0;
	keeppile.vals = 0;
	while (j <= apile.len)
	{
		tmppile = max_order_in_tab(apile.vals, apile.len);
		if (tmppile.len > k)
		{
			k = tmppile.len;
			free(keeppile.vals);
			keeppile = tmppile;
		}
		rotate_nc(apile);
		j++;
	}
	return (keeppile);
}

int main(int argc, char **argv) {
	int	i;
 	t_pile apile;
	t_pile bpile;
	t_pile keeppile;
	t_pile simpile;

	if (argc < 2)
		return (1);
	argv++;
	// i = ft_min_nums(3, 1, -4, 3);
	ft_printf("min %d\n",i);
	apile = create_a(argv);
	simpile = copy_pile(apile);
	bpile = create_b(apile.len);
	ft_putendl("Pile B");
	view_pile(bpile);
	ft_putendl("Pile A");
	view_pile(apile);
	keeppile = pile_max_order(simpile);
	ft_putendl("Extraite");
	ft_printf("extraite len %d\n", keeppile.len);
	view_pile(keeppile);
	// int t = find_just_under(28, keeppile);
	// ft_printf("junder %d\n",t);
	push_max_order(&apile, &bpile, &keeppile);
	ft_putendl("Pile A apres que tri");
	view_pile(apile);
	ft_putendl("Pile B reste que tri");
	view_pile(bpile);
	rotate_finish(&apile);
	ft_putendl("Pile A apres rotate_finish");
	view_pile(apile);
	ft_putendl("Pile B apres rotate_finish");
	view_pile(bpile);
	ft_lstreverse(&g_ops);
	i = 0;
	while (g_ops)
	{
		i++;
		// ft_putendl((char*)(g_ops->content));
		g_ops = g_ops->next;
	}
	ft_printf("%d operations \n",i);
	return (0);
}
