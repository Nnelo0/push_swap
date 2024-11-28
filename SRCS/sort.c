/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebroudic <ebroudic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 08:56:18 by ebroudic          #+#    #+#             */
/*   Updated: 2024/11/28 16:37:11 by ebroudic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

void	sort(t_list **a, t_list **b)
{
	if (is_sorted(*a))
		return ;
	if (ft_lstsize(*a) <= 3)
		return (mini_sort(a));
	if (ft_lstsize(*a) > 3)
		return (large_sort(a, b));
}

void	large_sort(t_list **a, t_list **b)
{
	int	max;
	int	min;

	min = ft_min(*a);
	max = ft_max(*a);
	while (ft_lstsize(*a) > 3)
		sort_b(a, b, max, min);
	if (!is_sorted(*a))
		mini_sort(a);
	while (*b)
		sort_a(a, b);
	while (!is_sorted(*a))
	{
		if ((*a)->content > min)
			do_rra(a);
		else
			break ;
	}
}

void	sort_a(t_list **a, t_list **b)
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

void	sort_b(t_list **a, t_list **b, int max, int min)
{
	(void)min;
	if ((*a)->content < max)
	{
		if (*b)
		{
			
			while (do_better_b(*a, *b) && (*b)->content != min)
				do_rrb(b);
			while (better_sort_b(*b))
				do_rb(b);
			while (reverse_sort_b(*b))
				do_rb(b);
		}
		do_pb(a, b);
	}
	else
		do_ra(a);
}
