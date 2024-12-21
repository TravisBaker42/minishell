/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 17:14:52 by tbaker            #+#    #+#             */
/*   Updated: 2023/07/26 17:14:56 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	const unsigned char	*str1;
	size_t				i;

	str1 = (const unsigned char *) str;
	i = 0;
	while (i < n)
	{
		if (str1[i] == (unsigned char)c)
			return ((void *)&str1[i]);
		i++;
	}
	return (NULL);
}
/*
int main(void)
{
	char *str = "hello world";
	int c = 'l';
	size_t n = 11;
	int	tab[7] = {-49, 1, -1, 0, -2, 2};
	printf("warmachine C's test = %s\n", (char *)ft_memchr(tab, -1, 7));
	printf("warmachine My test = %s\n", (char *)memchr(tab, -1, 7));

	printf("My ft_memcmp = %s\n", (char *)ft_memchr(str, c, n));
	printf("C's memcmp = %s\n", (char *)memchr(str, c, n));
	return(0);
}*/
