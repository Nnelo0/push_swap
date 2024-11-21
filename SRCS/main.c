/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebroudic <ebroudic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:28:01 by ebroudic          #+#    #+#             */
/*   Updated: 2024/11/21 09:12:15 by ebroudic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_node_content(int content)
{
	ft_printf("%d\n", content);
}

int	add_content(t_list **z, char *arg)
{
	t_list	*new_node;

	new_node = ft_lstnew(ft_atoi(arg));
	if (!new_node)
		return (ft_lstclear(z), 1);
	ft_lstadd_back(z, new_node);
	return (0);
}

int	add_list(t_list **a, int argc, char **argv)
{
	int		i;
	char	**split_argv;

	i = 0;
	if (argc == 2)
	{
		split_argv = ft_split(argv[1], ' ');
		if (!split_argv)
			return (1);
		i = -1;
		while (split_argv[++i])
			add_content(a, split_argv[i]);
		ft_free_split(split_argv);
	}
	else
	{
		while (++i < argc)
			add_content(a, argv[i]);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	error(argc, argv);
	add_list(&a, argc, argv);
	ft_printf("Contenu de la liste 'a':\n");
	ft_lstiter(a, print_node_content);
	ft_printf("Contenu de la liste 'b':\n");
	ft_lstiter(b, print_node_content);
	if (is_sorted(a))
		return (0);
	mini_sort(&a);
	ft_printf("Contenu de la liste 'a':\n");
	ft_lstiter(a, print_node_content);
	ft_lstclear(&a);
	ft_lstclear(&b);
	return (0);
}
