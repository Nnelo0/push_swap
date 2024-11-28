/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebroudic <ebroudic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:45:40 by ebroudic          #+#    #+#             */
/*   Updated: 2024/11/28 13:45:36 by ebroudic         ###   ########.fr       */
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

int	ft_min(t_list *a)
{
	int		min;
	t_list	*tmp;

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
	int		high;
	t_list	*tmp;

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

int	do_better_a(t_list *a, t_list *b)
{
	int	max;
	int	i;

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

	if (!a)
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
