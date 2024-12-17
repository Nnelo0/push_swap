/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebroudic <ebroudic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 09:57:01 by ebroudic          #+#    #+#             */
/*   Updated: 2024/12/17 10:25:02 by ebroudic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft/libft.h"
# include "libft/printf/ft_printf.h"
# include <limits.h>

/*			error_utils			*/

int		nb_cmp(char *s1, char *s2);
int		is_sign(char c);
int		print_error(void);
void	ft_free_split(char **split_arg);
int		ft_in_int(const char *nptr);

/*			error				*/

int		error(int argc, char **argv);

/*			swap				*/

void	do_sa(t_list **a);
void	do_sb(t_list **b);
void	do_ss(t_list **a, t_list **b);

/*			push				*/

void	do_pb(t_list **a, t_list **b);
void	do_pa(t_list **a, t_list **b);

/*			rotate				*/

void	do_ra(t_list **a);
void	do_rb(t_list **b);
void	do_rr(t_list **a, t_list **b);

/*			reverse_rotate		*/

void	do_rrr(t_list **a, t_list **b);
void	do_rrb(t_list **b);
void	do_rra(t_list **a);

/*			sort_utils			*/

int		is_sorted(t_list *a);
int		ft_min(t_list *a);
int		ft_max(t_list *a);
int		do_better_b(t_list *a, t_list *b);

/*			sort				*/

void	mini_sort(t_list **a);
void	sort(t_list **a, t_list **b);
void	large_sort(t_list **a, t_list **b);
void	sort_b(t_list **a, t_list **b, int max, int min);
int		find_the_cheapest(t_list **stack_a, t_list **stack_b);
void	value_on_top(t_list **a, int value);
void	value_on_top_b(t_list **b, int value);
int		find_closest_upper(t_list **stack_a, t_list **stack_b);
int		can_push(t_list **stack_a, int value);
int		get_steps_to_value(t_list **b, int value);
#endif
