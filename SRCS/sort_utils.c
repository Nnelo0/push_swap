/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebroudic <ebroudic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:45:40 by ebroudic          #+#    #+#             */
/*   Updated: 2024/11/26 16:57:07 by ebroudic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_sorted(t_list *a)
{
	while (a && a->next)
	{
		if (a->content > a->next->content)
			return (0);
		a = a->next;
	}
	return (1);
}

void	mini_sort(t_list **a)
{
	if (ft_lstsize(*a) == 2)
		do_sa(a);
	else if (ft_lstsize(*a) == 3)
	{
		if ((*a)->content > (*a)->next->content
			&& (*a)->next->content > (*a)->next->next->content)
		{
			do_sa(a);
			do_rra(a);
		}
		else if ((*a)->content > (*a)->next->content
			&& (*a)->content > (*a)->next->next->content)
			do_ra(a);
		else if ((*a)->next->content > (*a)->next->next->content
			&& (*a)->content < (*a)->next->next->content)
		{
			do_sa(a);
			do_ra(a);
		}
		else if ((*a)->content > (*a)->next->content)
			do_sa(a);
		else if ((*a)->content < (*a)->next->content
			&& (*a)->next->content > (*a)->next->next->content)
			do_rra(a);
	}
}
int	ft_min(t_list *a)
{
	int min;
	t_list *tmp;
	
	min = a->content;
	tmp = a;
	while (tmp)
	{
		if (tmp->content < min)
			min = tmp->content;
		tmp = tmp->next;
	}
	return ((min));
}
int	ft_max(t_list *a)
{
	int high;
	t_list *tmp;

	high = a->content;
	tmp = a;
	while (tmp)
	{
		if (tmp->content > high)
			high = tmp->content;
		tmp = tmp->next;
	}
	return ((high));
}

int do_better_a(t_list *a, t_list *b)
{
	int max;
	int i;
	
	if (!a)
		return (0);
	i = ft_lstsize(a);
	max = ft_max(a);
	while (i != 1)
	{
		a = a->next;
		i--;
	}
	if (a->content > b->content && a->content != max)
		return (1);
	return (0);
}

int do_better_b(t_list *a, t_list *b)
{
	int min;
	int i;

	if (!b)
		return (0);
	i = ft_lstsize(b);
	min = ft_min(b);
	while (i != 1)
	{
		b = b->next;
		i--;
	}
	if (a->content < b->content && b->content != min)
		return (1);
	return (0);
}

void	sort(t_list **a, t_list **b)
{
	int	max;
	int min;

	min = ft_min(*a);
	//ft_printf("min %d\n", min);
	
	if (is_sorted(*a))
			return ;
	if (ft_lstsize(*a) <= 3)
		return (mini_sort(a));
	if (ft_lstsize(*a) > 3)
	{
		max = ft_max(*a);
	//	ft_printf("pivot %d\n", pivot);
		while (ft_lstsize(*a) > 3)
		{
			if ((*a)->content < (max))
			{
				if (*b)
				{
					while (do_better_b(*a, *b))
						do_rb(b);
					/* while (ft_min(*b) != (*b)->content)
						do_rrb(b); */
				}
				do_pb(a, b);
			}
			else
				do_ra(a);
		}
	}
	if (!is_sorted(*a))
		mini_sort(a);
	while (*b)
	{
		if ((*a)->content > (*b)->content)
		{
			while (do_better_a(*a, *b))
				do_rra(a);
			do_pa(a, b);
		}
		else if ((*a)->content < (*b)->content)
			do_ra(a);
	}
	while (!is_sorted(*a))
	{
		if ((*a)->content > min)
			do_rra(a);
		else
			break;
	}
}
