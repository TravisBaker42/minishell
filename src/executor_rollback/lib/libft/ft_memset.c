/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 13:53:48 by tbaker            #+#    #+#             */
/*   Updated: 2023/07/12 15:06:41 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)str)[i] = c;
		i++;
	}
	return (str);
}
/*
int	main(void)
{
	char input[20]= "hello world again";
	printf("%s\n", (char*)ft_memset(input, '$', 7));
	printf("%s\n", (char*)memset(input, '$', 7));
	return (0);
}*/
