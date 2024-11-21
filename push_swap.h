/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebroudic <ebroudic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 09:57:01 by ebroudic          #+#    #+#             */
/*   Updated: 2024/11/20 15:04:36 by ebroudic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft/libft.h"
# include "libft/printf/ft_printf.h"

/*			error_utils			*/

int		nb_cmp(char *s1, char *s2);
int		is_sign(char c);
int		print_error(void);
void	ft_free_split(char **split_arg);

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

/*			reverse_rotate				*/

void	do_rrr(t_list **a, t_list **b);
void	do_rrb(t_list **b);
void	do_rra(t_list **a);

/*			sort				*/

int		is_sorted(t_list *a);
void	mini_sort(t_list **a);

#endif
