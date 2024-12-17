/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebroudic <ebroudic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 08:55:00 by ebroudic          #+#    #+#             */
/*   Updated: 2024/12/17 10:01:41 by ebroudic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	is_num(char *argv)
{
	int	i;

	i = 0;
	if (is_sign(argv[i]) && argv[i + 1] != '\0')
		i++;
	while (argv[i])
	{
		if (!ft_isdigit(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	is_double(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (nb_cmp(argv[i], argv[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	arg_is_zero(char *argv)
{
	int	i;

	i = 0;
	if (is_sign(argv[i]))
		i++;
	while (argv[i] && argv[i] == '0')
		i++;
	if (argv[i] != '\0')
		return (0);
	return (1);
}

static int	correct_input(char **argv)
{
	int	i;
	int	nb_zeros;

	nb_zeros = 0;
	i = 0;
	while (argv[i])
	{
		if (!is_num(argv[i]))
			return (1);
		if (ft_in_int(argv[i]))
			return (1);
		nb_zeros += arg_is_zero(argv[i]);
		i++;
	}
	if (nb_zeros > 1)
		return (1);
	if (is_double(argv))
		return (1);
	return (0);
}

int	error(int argc, char **argv)
{
	char	**split_arg;

	if (argc < 2)
		return (0);
	split_arg = ft_split(argv[1], ' ');
	if (!split_arg)
		print_error();
	if (argc == 2)
	{
		if (correct_input(split_arg))
		{
			ft_free_split(split_arg);
			print_error();
		}
	}
	else
	{
		if (correct_input(argv + 1))
		{
			ft_free_split(split_arg);
			print_error();
		}
	}
	ft_free_split(split_arg);
	return (0);
}
