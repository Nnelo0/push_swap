/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheapest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebroudic <ebroudic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:14:38 by ebroudic          #+#    #+#             */
/*   Updated: 2024/12/17 10:04:16 by ebroudic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	find_position_in_b(t_list **stack_b, int value)
{
	t_list	*current;
	int		pos;

	current = *stack_b;
	pos = 0;
	while (current)
	{
		if (current->content > value)
			break ;
		pos++;
		current = current->next;
	}
	return (pos);
}

static int	calculate_cost(int pos_a, int pos_b, int size_a, int size_b)
{
	int	cost_a;
	int	cost_b;

	cost_a = pos_a;
	if (pos_a > size_a / 2)
		cost_a = size_a - pos_a;
	cost_b = pos_b;
	if (pos_b > size_b / 2)
		cost_b = size_b - pos_b;
	return (cost_a + cost_b);
}

int	find_the_cheapest(t_list **stack_a, t_list **stack_b)
{
	t_list	*current;
	int		best_value;
	int		pos_a;
	int		min_cost;
	int		cost;

	current = *stack_a;
	best_value = current->content;
	pos_a = 0;
	min_cost = 2147483647;
	while (current)
	{
		cost = calculate_cost(pos_a,
				find_position_in_b(stack_b, current->content),
				ft_lstsize(*stack_a), ft_lstsize(*stack_b));
		if (cost < min_cost)
		{
			min_cost = cost;
			best_value = current->content;
		}
		current = current->next;
		pos_a++;
	}
	return (best_value);
}
