/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebroudic <ebroudic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 08:56:18 by ebroudic          #+#    #+#             */
/*   Updated: 2024/12/19 08:45:52 by ebroudic         ###   ########.fr       */
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
	int	cheapest;
	int	closest;

	min = ft_min(*a);
	max = ft_max(*a);
	while (ft_lstsize(*a) > 3 && !is_sorted(*a))
		sort_b(a, b, max, min);
	if (!is_sorted(*a))
		mini_sort(a);
	while (*b)
	{
		cheapest = find_the_cheapest(a, b);
		value_on_top_b(b, cheapest);
		closest = find_closest_upper(a, b);
		if (!can_push(a, closest))
			value_on_top(a, closest);
		do_pa(a, b);
	}
	if (!is_sorted(*a))
		value_on_top(a, ft_min(*a));
}

void	sort_b(t_list **a, t_list **b, int max, int min)
{
	(void)min;
	if ((*a)->content < max)
	{
		if (*b)
		{
			while (do_better_b(*a, *b))
				do_rb(b);
		}
		do_pb(a, b);
	}
	else
		do_ra(a);
}
