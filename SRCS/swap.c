/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebroudic <ebroudic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 09:11:01 by ebroudic          #+#    #+#             */
/*   Updated: 2024/11/20 10:01:04 by ebroudic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	swap(t_list *swap)
{
	int	tmp;

	if (swap == NULL || swap->next == NULL)
		return ;
	tmp = swap->content;
	swap->content = swap->next->content;
	swap->next->content = tmp;
}

void	do_sa(t_list **a)
{
	swap(*a);
	ft_printf("sa\n");
}

void	do_sb(t_list **b)
{
	swap(*b);
	ft_printf("sb\n");
}

void	do_ss(t_list **a, t_list **b)
{
	swap(*a);
	swap(*b);
	ft_printf("ss\n");
}
