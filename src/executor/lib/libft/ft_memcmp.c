/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 17:15:20 by tbaker            #+#    #+#             */
/*   Updated: 2023/07/26 17:15:23 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t			i;
	unsigned char	*cstr1;
	unsigned char	*cstr2;

	cstr1 = (unsigned char *) str1;
	cstr2 = (unsigned char *) str2;
	i = 0;
	while (i < n)
	{
		if (cstr1[i] != cstr2[i])
			return (cstr1[i] - cstr2[i]);
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	char *str1 = "hello World";
	char *str2 = "hello WorlD";
	size_t n = 11;
	printf("My memcmp = %d\n", ft_memcmp(str1, str2, n));
	printf("C's memcmp = %d\n", memcmp(str1, str2, n));
	return (0);
}*/
