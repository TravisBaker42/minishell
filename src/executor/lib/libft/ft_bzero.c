/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 15:07:07 by tbaker            #+#    #+#             */
/*   Updated: 2023/07/12 15:32:07 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *str, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)str)[i] = '\0';
		i++;
	}
}
/*
int main(void)
{
	char input[20] = "hello world again";
	char input2[20] = "hello world again";
	printf("%s\n", input);
	printf("%s\n", input2);
	ft_bzero(input, 3);
	bzero(input2, 3);
	printf("%s\n", input);
	printf("%s\n", input2);
	return (0);
}
*/
