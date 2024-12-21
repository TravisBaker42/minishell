/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 17:18:01 by tbaker            #+#    #+#             */
/*   Updated: 2023/08/27 21:38:21 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_trimstart(char const *s1, char const *set)
{
	size_t	trim;
	size_t	i;

	trim = 0;
	i = 0;
	if (s1 == NULL || set == NULL)
		return (0);
	while (set[i] != '\0' && s1[trim] != '\0')
	{
		if (s1[trim] == set[i])
		{
			trim++;
			i = 0;
		}
		else
			i++;
	}
	return (trim);
}

static	size_t	ft_trimend(char const *s1, char const *set, size_t len)
{
	size_t	trim;
	size_t	i;

	trim = 0;
	i = 0;
	if (s1 == NULL || set == NULL)
		return (0);
	while (set[i] != '\0' && len > 0)
	{
		if (s1[len - 1] == set[i])
		{
			trim++;
			len--;
			i = 0;
		}
		else
			i++;
	}
	return (trim);
}

static	char	*ft_mcopy(char const *s1, size_t start, size_t total)
{
	size_t	len;
	size_t	i;
	char	*scopy;

	len = ft_strlen(s1);
	scopy = (char *)malloc(sizeof(char) * (len - total + 1));
	if (scopy == NULL)
		return (NULL);
	i = 0;
	while (i < len - total)
	{
		scopy[i] = s1[start];
		i++;
		start++;
	}
	scopy[i] = '\0';
	return (scopy);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimstr;
	size_t	start;
	size_t	total;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = ft_trimstart(s1, set);
	total = start + ft_trimend(s1, set, ft_strlen(s1));
	if (start >= ft_strlen(s1))
		return (ft_strdup(""));
	trimstr = ft_mcopy(s1, start, total);
	return (trimstr);
}
/*
int	main(void)
{
	char const *s1_test1 = "|bhello worldcaba";
	char const *s1_test2 = "hello world$$$";
	char const *s1_test3 = "$$$hello world";
	char const *s1_test4 = "hello $$$ world$$$";
	char const *s1_test5 = "hello world";
	char const *set = "abc|";
//	printf("test 1 = %lu\n", ft_trimstart(s1_test1, set));
//	printf("test 1 = %lu\n", ft_trimend(s1_test1, set, ft_strlen(s1_test1)));
	printf("test 1 = %s\n", ft_strtrim(s1_test1, set));
	printf("test 2 = %s\n", ft_strtrim(s1_test2, set));
	printf("test 3 = %s\n", ft_strtrim(s1_test3, set));
	printf("test 4 = %s\n", ft_strtrim(s1_test4, set));
	printf("test 5 = %s\n", ft_strtrim(s1_test5, set));
	return (0);
}*/
