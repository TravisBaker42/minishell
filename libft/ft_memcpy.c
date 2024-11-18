/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 15:36:15 by tbaker            #+#    #+#             */
/*   Updated: 2023/08/01 17:01:50 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const unsigned char	*src1;
	unsigned char		*dest1;
	size_t				i;

	if (dest == NULL && src == NULL)
		return (NULL);
	i = 0;
	src1 = (unsigned char *)src;
	dest1 = (unsigned char *)dest;
	while (i < n)
	{
		dest1[i] = src1[i];
		i++;
	}
	return (dest1);
}
/*
int main(void)
{
	char src[5] = { 's', 'a', '\0', 'c', 'h'};
	char dest[5];
	char dest1[5];
	int	i = 0;
	ft_memcpy(dest, src, 5);
	while (i < 5)
	{
		printf("%c\n", dest[i]);
		i++;
	}
	printf("----------------------");
	printf("\n");
	memcpy(dest1, src, 5);
	i = 0;
	while (i < 5)
	{
		printf("%c\n", dest1[i]);
		i++;
	}
	return (0);
}*/
