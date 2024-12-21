/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 17:16:47 by tbaker            #+#    #+#             */
/*   Updated: 2023/07/30 18:45:22 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n) 
	{
		if (str1[i] != str2[i])
			return ((unsigned char) str1[i] - (unsigned char)str2[i]);
		if (str1[i] == '\0' && str2[i] == '\0')
			break ;
		i++;
	}
	return (0);
}
/*
int main(void)
{
	char str1[11] = "hello world";
	char str2[11] = "hello World";
	size_t n = 11;
	printf("My strncmp = %d\n", ft_strncmp(str1, str2, n));
	printf("C's strncmp = %d\n", ft_strncmp(str1, str2, n));
	return (0);
}*/
