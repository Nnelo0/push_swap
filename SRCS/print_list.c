/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebroudic <ebroudic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:18:51 by ebroudic          #+#    #+#             */
/*   Updated: 2024/11/28 09:06:11 by ebroudic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	print_node_content(int content)
{
	ft_printf("%d\n", content);
}

void	print_list(t_list *a, t_list *b)
{
	ft_printf("Contenu de la liste 'a':\n");
	ft_lstiter(a, print_node_content);
	ft_printf("Contenu de la liste 'b':\n");
	ft_lstiter(b, print_node_content);
}
