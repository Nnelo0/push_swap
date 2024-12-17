/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebroudic <ebroudic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:39:23 by ebroudic          #+#    #+#             */
/*   Updated: 2024/12/17 10:04:22 by ebroudic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_steps_to_value(t_list **b, int value)
{
	t_list	*b_temp;
	int		count;

	if (!b || !*b)
		return (0);
	b_temp = *b;
	count = 0;
	while (b_temp)
	{
		if (b_temp->content == value)
			break ;
		count++;
		b_temp = b_temp->next;
	}
	return (count);
}

void	value_on_top(t_list **a, int value)
{
	int	size;
	int	steps;

	steps = 0;
	size = ft_lstsize(*a);
	steps = get_steps_to_value(a, value);
	if (steps <= size / 2)
	{
		while (steps--)
			do_ra(a);
	}
	else
	{
		while (steps++ < size)
			do_rra(a);
	}
}

void	value_on_top_b(t_list **b, int value)
{
	int	size;
	int	steps;

	steps = 0;
	size = ft_lstsize(*b);
	steps = get_steps_to_value(b, value);
	if (steps <= size / 2)
	{
		while (steps--)
			do_rb(b);
	}
	else
	{
		while (steps++ < size)
			do_rrb(b);
	}
}

int	find_closest_upper(t_list **stack_a, t_list **stack_b)
{
	int		first;
	t_list	*current;
	int		closest_upper;

	first = (*stack_b)->content;
	current = *stack_a;
	closest_upper = INT_MAX;
	while (current)
	{
		if (current->content > first && current->content < closest_upper)
			closest_upper = current->content;
		current = current->next;
	}
	if (closest_upper == INT_MAX)
		return (ft_min(*stack_a));
	return (closest_upper);
}

int	can_push(t_list **stack_a, int value)
{
	if (value == (*stack_a)->content)
		return (1);
	return (0);
}
