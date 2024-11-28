/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebroudic <ebroudic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 09:35:31 by ebroudic          #+#    #+#             */
/*   Updated: 2024/11/28 16:26:30 by ebroudic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	better_sort_b(t_list *b)
{
	int min;
	int max;
	int i;
	t_list *tmp;

	tmp = b;
	max = ft_max(b);
	min = ft_min(b);
	if (!b)
		return (0);
	i = ft_lstsize(b);
	while (i != 1)
	{
		b = b->next;
		i--;
	}
	if (b->content > tmp->content && (b->content != max || b->content != min))
		return (1);
	return (0);
}

int	reverse_sort_b(t_list *b)
{
	int min;
	int max;
	int i;
	t_list *tmp;
	
	if (!b || !b->next || !b->next->next)
		return (0);
	max = ft_max(b);
	min = ft_min(b);
	i = ft_lstsize(b);
	tmp = b;
	b = b->next;
	if (tmp->content < b->content)
		return(1);
	return (0);
}