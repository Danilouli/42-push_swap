/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keeper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 16:15:48 by dsaadia           #+#    #+#             */
/*   Updated: 2018/02/28 17:21:54 by dsaadia          ###   ########.fr       */
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

int (int *tab, int len)
{
	int i;

	i = 0;
	while (i < len - 1)
	{
		if (tab[i] > tab[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int pile_is_sort(t_pile pile)
{
	int i;
	t_pile simpile;

	simpile.len = pile.len;
	simpile.name = pile.name;
	simpile.vals = (int*)malloc(sizeof(int)*(simpile.len));
	ft_int_tab_cpy(simpile.vals, pile.vals, simpile.len);
	i = 0;
	while (i <= simpile.len)
	{
		if ((simpile.vals, simpile.len))
		{
			free(simpile.vals);
			return (1);
		}
		rotate_nc(simpile);
		i++;
	}
	free(simpile.vals);
	return (0);
}

int	ft_get_max(int *tab, int len)
{
	int i;
	int max;

	i = -1;
	max = tab[0];
	while (++i < len)
		max = (tab[i] > max) ? tab[i] : max;
	return (max);
}

int	ft_get_min(int *tab, int len)
{
	int i;
	int min;

	i = -1;
	min = tab[0];
	while (++i < len)
		min = (tab[i] < min) ? tab[i] : min;
	return (min);
}

int* max_order_in_tab(int *tab, int len, int *reslen, t_pile *swap_places)
{
	int *res;
	int i;
	int post_ct;
	int k;
	int j;
	int l;

	i = 0;
	j = 0;
	*reslen = 1;
	res = (int*)malloc(sizeof(int)*len);
	while (tab[i] < tab[i + 1] && (i < len - 1))
	{
		res[i] = tab[i];
		i++;
		if (tab[i] > tab[i + 1])
		{
			if (0 <= (i - 1) && (i + 2) <= (len - 1))
			{
				if (tab[i + 2] > tab[i] && tab[i + 1] > tab[i - 1])
				{
					(swap_places->vals)[swap_places->len] = tab[i];
					(swap_places->len)++;
					swap_ints(&(tab[i]), &(tab[i + 1]));
				}
			}
			else if (i + 2 >= len)
			{
				if (tab[i + 1] > tab[i - 1])
				{
					(swap_places->vals)[swap_places->len] = tab[i];
					(swap_places->len)++;
					swap_ints(&(tab[i]), &(tab[i + 1]));
				}
			}
		}
		(*reslen)++;
	}
	res[i] = tab[i];
	i++;
	while (i < len)
	{
		k = i;
		post_ct = 1;
		while (i < len - 1 && tab[i] < tab[i + 1])
		{
			post_ct++;
			i++;
		}
		if (res[0] < tab[k] && (*reslen <= post_ct || res[*reslen - post_ct] < tab[k]))
		{
			j = 1;
			while (res[*reslen - j] > tab[k])
			{
				j++;
			}
			l = 1;
			*reslen = (*reslen - j + 1 > 0) ? (*reslen - j + 1) : 1;
			while (l <= post_ct)
			{
				res[*reslen + l - 1] = tab[k + l - 1];
				l++;
			}
			*reslen = *reslen + post_ct;
		}
		else if (res[0] < tab[k] && (tab[k + post_ct - 1] < res[*reslen - 1] && tab[k] > res[*reslen - post_ct - 1]))
		{
			l = 0;
			while (l < post_ct)
			{
				res[*reslen - post_ct + l] = tab[k + l];
				l++;
			}
		}
		i = k + 1;
	}
	return (res);
}
int right_in_maxtab(t_pile apile, int *keeptab, int keeptab_len)
{
	int i;

	i = 0;
	while (!ft_in_array(apile.vals[i], keeptab, keeptab_len) && i < apile.len)
		i++;
	return(apile.vals[i]);
}

int left_in_maxtab(t_pile apile, int *keeptab, int keeptab_len)
{
	int i;

	i = apile.len - 1;
	while (!ft_in_array(apile.vals[i], keeptab, keeptab_len) && i >= 0)
		i--;
	return(apile.vals[i]);
}

int	good_to_push(t_pile apile, int num, int *maxtab, int maxtab_len)
{
	return (
		(left_in_maxtab(apile, maxtab, maxtab_len) < num && num < right_in_maxtab(apile, maxtab, maxtab_len))
		|| (num > ft_get_max(maxtab, maxtab_len) && left_in_maxtab(apile, maxtab, maxtab_len) == ft_get_max(maxtab, maxtab_len))
		|| (num < ft_get_min(maxtab, maxtab_len) && right_in_maxtab(apile, maxtab, maxtab_len) == ft_get_min(maxtab, maxtab_len))
	);
}

int dist_rotating_a(t_pile apile, int num, int *keeptab, int keeptab_len)
{
	int i;
	t_pile simpile;

	simpile.len = apile.len;
	simpile.name = apile.name;
	simpile.vals = (int*)malloc(sizeof(int)*(simpile.len));
	ft_int_tab_cpy(simpile.vals, apile.vals, simpile.len);
	i = 0;
	while (!(good_to_push(simpile, num, keeptab, keeptab_len)) && i <= apile.len)
	{
		rotate_nc(simpile);
		i++;
	}
	free(simpile.vals);
	return(i);
}

int dist_rev_rotating_a(t_pile apile, int num, int *keeptab, int keeptab_len)
{
	int i;

	t_pile simpile;

	simpile.len = apile.len;
	simpile.name = apile.name;
	simpile.vals = (int*)malloc(sizeof(int)*(simpile.len));
	ft_int_tab_cpy(simpile.vals, apile.vals, simpile.len);
	i = 0;
	while (!(good_to_push(simpile, num, keeptab, keeptab_len)) && i <= apile.len)
	{
		rev_rotate_nc(simpile);
		i++;
	}
	free(simpile.vals);
	return(i);
}

int dist_rotating_b(t_pile apile, t_pile bpile, int *keeptab, int keeptab_len)
{
	int i;

	t_pile simpile;

	simpile.len = bpile.len;
	simpile.name = bpile.name;
	simpile.vals = (int*)malloc(sizeof(int)*(simpile.len));
	ft_int_tab_cpy(simpile.vals, bpile.vals, simpile.len);
	i = 0;
	while (!(good_to_push(apile, simpile.vals[0], keeptab, keeptab_len)) && i <= apile.len)
	{
		rotate_nc(simpile);
		i++;
	}
	free(simpile.vals);
	return(i);
}

int dist_rev_rotating_b(t_pile apile, t_pile bpile, int *keeptab, int keeptab_len)
{
	int i;

	t_pile simpile;

	simpile.len = bpile.len;
	simpile.name = bpile.name;
	simpile.vals = (int*)malloc(sizeof(int)*(simpile.len));
	ft_int_tab_cpy(simpile.vals, bpile.vals, simpile.len);
	i = 0;
	while (!(good_to_push(apile, simpile.vals[0], keeptab, keeptab_len)) && i <= apile.len)
	{
		rev_rotate_nc(simpile);
		i++;
	}
	free(simpile.vals);
	return(i);
}

int min_dist_to_push(t_pile apile, t_pile bpile, int *keeptab, int keeptab_len)
{
	return (
		min_dist(
			dist_rotating_a(apile, bpile.vals[0], keeptab, keeptab_len),
			dist_rev_rotating_a(apile, bpile.vals[0], keeptab, keeptab_len),
			dist_rotating_b(apile, bpile, keeptab, keeptab_len),
			dist_rev_rotating_b(apile, bpile, keeptab, keeptab_len)
		)
	);
}

void push_max_order(t_pile *apile, t_pile *bpile, int *keeptab, int keeptab_len)
{
	int min;
	int max;
	int j;
	int final_len;
	int min_dist;

	min_dist = 0;
	final_len = apile->len;
	min = ft_get_min(apile->vals, apile->len);
	max = ft_get_max(apile->vals, apile->len);
	while (!(pile_is_sort(*apile) && apile->len == final_len))
	{
		if (bpile->len > 0 && good_to_push(*apile, (bpile->vals)[0], keeptab, keeptab_len))
		{
			keeptab[keeptab_len] = bpile->vals[0];
			push(bpile, apile, 1);
			keeptab_len++;
		}
		else if (!ft_in_array((apile->vals)[0], keeptab, keeptab_len))
		{
			// if (ft_in_array((apile->vals)[1], keeptab, keeptab_len) && (apile->vals)[0] > (apile->vals)[1])
			// {
			// 	ft_putendl("SWAP >");
			// 	swap(apile, 1);
			// 	rotate(apile, 1);
			// 	rotate(apile, 1);
			// 	if ((apile->vals)[0] < right_in_maxtab(*apile, keeptab, keeptab_len))
			// 	{
			// 		keeptab[keeptab_len] = (bpile->vals)[0];
			// 		keeptab_len++;
			// 	}
			// }
			// else
				push(apile, bpile, 1);
		}
		// else if (ft_in_array((apile->vals)[0], keeptab, keeptab_len) && !ft_in_array((apile->vals)[1], keeptab, keeptab_len)
		// 	&& (apile->vals)[1] < (apile->vals)[0])
		// {
		// 	ft_putendl("SWAP <");
		// 	swap(apile, 1);
		// 	if ((apile->vals)[0] > left_in_maxtab(*apile, keeptab, keeptab_len))
		// 	{
		// 		keeptab[keeptab_len] = (bpile->vals)[0];
		// 		keeptab_len++;
		// 	}
		// 	rotate(apile, 1);
		// 	rotate(apile, 1);
		// }
		else if (bpile->len > 0)
		{
				// ft_printf("calcul de min dist\n");
				min_dist = min_dist_to_push(*apile, *bpile, keeptab, keeptab_len);
				// ft_printf("min dist %d\n",min_dist);
				if (dist_rotating_a(*apile, (bpile->vals)[0], keeptab, keeptab_len) <= min_dist)
				{
					j = -1;
					// while (++j < min_dist)
						rotate(apile, 1);
					// push(bpile, apile, 1);
				}
				else if (dist_rev_rotating_a(*apile, (bpile->vals)[0], keeptab, keeptab_len) <= min_dist)
				{
					j = -1;
					// while (++j < min_dist)
						rev_rotate(apile, 1);
					// push(bpile, apile, 1);
				}
				else if (dist_rotating_b(*apile, *bpile, keeptab, keeptab_len) <= min_dist)
				{
					j = -1;
					// while (++j < min_dist)
						rotate(bpile, 1);
					// push(bpile, apile, 1);
				}
				else if (dist_rev_rotating_b(*apile, *bpile, keeptab, keeptab_len) <= min_dist)
				{
					j = -1;
					// while (++j < min_dist)
						rev_rotate(bpile, 1);
					// push(bpile, apile, 1);
				}
		}
		else
		{
			// min_dist = min_dist_to_push(*apile, *bpile, keeptab, keeptab_len);
			rotate(apile, 1);
		}
		// ft_putendl("----Pile A DANS LE MACHIN----");
		// view_pile(*apile);
		// ft_putendl("----Pile B DANS LE MACHIN----");
		// view_pile(*bpile);
		// ft_putendl("dans keeptab");
		// j = 0;
		// while (j < keeptab_len)
		// {
		// 	ft_printf("%d ,", keeptab[j]);
		// 	j++;
		// }
		// ft_putchar('\n');
		if ((apile->vals, apile->len) && apile->len >= final_len)
			break ;
	}
}

int find_just_above(t_pile apile, int num, int *place)
{
	int i;
	int max;
	int min;

	i = 0;
	*place = 0;
	max = ft_get_max(apile.vals, apile.len);
	min = ft_get_min(apile.vals, apile.len);
	while (i <= apile.len)
	{
		if ((num > max || num < min) && apile.vals[1] == min)
			break ;
		if (apile.vals[0] < num && num < apile.vals[1])
			return (apile.vals[1]);
		(*place)++;
		i++;
		rotate(&apile, 0);
	}
	return (min);
}

void re_push_good(t_pile *apile, t_pile *bpile)
{
	int jabove;
	int place;
	int i;

	i = 0;
	while (bpile->len > 0)
	{
		jabove = find_just_above(*apile, (bpile->vals)[0], &place);
		if (place <= (apile->len) / 2)
		{
			while ((apile->vals)[0] != jabove)
				rotate(apile, 1);
		}
		else
		{
			while ((apile->vals)[0] != jabove)
				rev_rotate(apile, 1);
		}
		push(bpile, apile, 1);
		i++;
	}
}

void rotate_finish(t_pile *apile)
{
	int min;

	min = ft_get_min(apile->vals, apile->len);
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

int* tab_max_order(t_pile apile, int *tablen)
{
	int k;
	int j;
	int *keeptab;
	int *tab;

	j = 0;
	k = 0;
	tab = 0;
	keeptab = 0;
	*tablen = 0;
	while (j < apile.len)
	{
		tab = max_order_in_tab(apile.vals, apile.len, tablen);
		if (*tablen > k)
		{
			k = *tablen;
			keeptab = tab;
		}
		rotate(&apile, 0);
		j++;
	}
	*tablen = k;
	return (keeptab);
}

int main(int argc, char **argv) {
	int	i;
 	t_pile apile;
	t_pile bpile;
	int ind;
	int *test;

	if (argc < 2)
		return (1);
	argv++;
	i = 0;
	apile = create_a(argv);
	bpile = create_b(apile.len);
	ft_putendl("Pile B");
	view_pile(bpile);
	ft_putendl("Pile A");
	view_pile(apile);
	test = tab_max_order(apile, &ind);
	i = 0;
	ft_putendl("sous suitre trie");
	while (i < ind)
	{
		ft_printf("%d ,",test[i]);
		i++;
	}
	ft_putchar('\n');
	push_max_order(&apile, &bpile, test, ind);
	ft_putendl("Pile A apres que tri");
	view_pile(apile);
	ft_putendl("Pile B reste que tri");
	view_pile(bpile);
	// re_push_good(&apile, &bpile);
	// ft_putendl("Pile A apres re_push_good");
	// view_pile(apile);
	// ft_putendl("Pile B apres re_push_good");
	// view_pile(bpile);
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

int dist_rota_rotb(t_pile apile, t_pile bpile, int *keeptab, int keeptab_len)
{
	int i;
	t_pile asimpile;
	t_pile bsimpile;

	asimpile = copy_pile(apile);
	bsimpile = copy_pile(bpile);
	i = 0;
	while (!(good_to_push(asimpile, bsimpile.vals[0], keeptab, keeptab_len)) && i <= apile.len)
	{
		rotate_nc(asimpile);
		i++;
		if (!(good_to_push(asimpile, bsimpile.vals[0], keeptab, keeptab_len)) & i++)
			rotate_nc(bsimpile);
	}
	free(asimpile.vals);
	free(bsimpile.vals);
	return(i);
}

int dist_reva_revb(t_pile apile, t_pile bpile, int *keeptab, int keeptab_len)
{
	int i;
	t_pile asimpile;
	t_pile bsimpile;
	char last;

	asimpile = copy_pile(apile);
	bsimpile = copy_pile(bpile);
	i = 0;
	last = 0;
	while (!(good_to_push(asimpile, bsimpile.vals[0], keeptab, keeptab_len)) && i <= apile.len)
	{
		rev_rotate_nc(asimpile);
		i++;
		last = 'a';
		if (!(good_to_push(asimpile, bsimpile.vals[0], keeptab, keeptab_len)) && (++i >= 0) && (last = 'b'))
			rev_rotate_nc(bsimpile);
	}
	free(asimpile.vals);
	free(bsimpile.vals);
	return(i);
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
		ft_putendl((char*)(g_ops->content));
		g_ops = g_ops->next;
	}
	ft_printf("%d operations \n",i);
	return (0);
}
