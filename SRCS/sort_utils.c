/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebroudic <ebroudic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:45:40 by ebroudic          #+#    #+#             */
/*   Updated: 2024/11/21 09:17:38 by ebroudic         ###   ########.fr       */
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
