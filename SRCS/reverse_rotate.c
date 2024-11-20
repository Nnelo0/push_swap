/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebroudic <ebroudic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:05:23 by ebroudic          #+#    #+#             */
/*   Updated: 2024/11/20 11:38:19 by ebroudic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	reverse_rotate(t_list **z)
{
	t_list	*tmp;
	t_list	*z2;

	if (!z || !(*z) || !(*z)->next)
		return ;
	z2 = *z;
	while (z2->next && z2->next->next)
	{
		z2 = z2->next;
	}
	tmp = z2->next;
	z2->next = NULL;
	ft_lstadd_front(z, tmp);
}

void	do_rra(t_list **a)
{
	reverse_rotate(a);
	ft_printf("rra\n");
}

void	do_rrb(t_list **b)
{
	reverse_rotate(b);
	ft_printf("rrb\n");
}

void	do_rrr(t_list **a, t_list **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_printf("rrr\n");
}
