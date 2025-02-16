/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 15:43:49 by tbaker            #+#    #+#             */
/*   Updated: 2023/08/26 19:41:36 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	str2len;

	i = 0;
	str2len = ft_strlen(str2);
	if (str2 == NULL)
		return ((char *)str1);
	if (str2len == 0)
		return ((char *)str1);
	while (str1[i] != '\0' && i <= n)
	{
		j = 0;
		while (str1[i + j] == str2[j] && i + j < n)
		{
			if (str2[j + 1] == '\0')
				return ((char *)&str1[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
	char *str10 = "world";
	char *str11 = "xxxxxxxxxxx";
	char *str20 = "Hello World";
	char *str21 = "";
	char *str22 = "hello world";
	char *s= "wotld";
	size_t n = 11;

	printf("My test 1 = %s\n", ft_strnstr(str10, s, n));
	printf("C's test 1 = %s\n", strnstr(str10, s, n));
	printf("My test 2 = %s\n", ft_strnstr(str11, s, n));
	printf("C's test 2 = %s\n", strnstr(str11, s, n));
	printf("My test 3 = %s\n", ft_strnstr(str20, s, n));
	printf("C's test 3 = %s\n", strnstr(str20, s, n));
	printf("My test 4 = %s\n", ft_strnstr(str21, s, n));
	printf("C's test 4 = %s\n", strnstr(str21, s, n));
	printf("My test 5 = %s\n", ft_strnstr(str22, s, n));
	printf("C's test 5 = %s\n", strnstr(str22, s, n));
	return (0);
}*/
