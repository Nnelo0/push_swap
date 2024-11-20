/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebroudic <ebroudic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 10:21:59 by ebroudic          #+#    #+#             */
/*   Updated: 2024/11/20 11:38:49 by ebroudic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate(t_list **z)
{
	t_list	*tmp;

	if (!z || !(*z) || !(*z)->next)
		return ;
	tmp = *z;
	*z = (*z)->next;
	tmp->next = NULL;
	ft_lstadd_back(z, tmp);
}

void	do_ra(t_list **a)
{
	rotate(a);
	ft_printf("ra\n");
}

void	do_rb(t_list **b)
{
	rotate(b);
	ft_printf("rb\n");
}

void	do_rr(t_list **a, t_list **b)
{
	rotate(b);
	rotate(a);
	ft_printf("rr\n");
}
