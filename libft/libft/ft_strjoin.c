/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebroudic <ebroudic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 13:05:24 by ebroudic          #+#    #+#             */
/*   Updated: 2024/11/19 12:42:31 by ebroudic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char* s2)
{
	char	*dsa;

	dsa = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (dsa == NULL)
		return (NULL);
	ft_strcpy(dsa, (char *)s1);
	ft_strcpy(dsa + ft_strlen(s1), (char *)s2);
	return (dsa);
}
/* int main()
{
	printf("%s\n",ft_strjoin("hello"," world"));
	return (0);
} */