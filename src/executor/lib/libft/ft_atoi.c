/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 18:32:13 by tbaker            #+#    #+#             */
/*   Updated: 2023/08/26 19:53:37 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	result;
	int	isneg;

	isneg = 1;
	result = 0;
	while ((*str == 32) || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			isneg = -isneg;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * isneg);
}
/*
int	main(void)
{
	const char *str1 = "1234567";
	const char *str2 = "    34a567";
	const char *str3 = "+34  567";
	const char *str4 = "+++1234567";
	printf("My ft_atoi = %d\n", ft_atoi(str1));
	printf("C's ft_atoi = %d\n", atoi(str1));
	printf("My ft_atoi = %d\n", ft_atoi(str2));
	printf("C's ft_atoi = %d\n", atoi(str2));
	printf("My ft_atoi = %d\n", ft_atoi(str3));
	printf("C's ft_atoi = %d\n", atoi(str3));
	printf("My ft_atoi = %d\n", ft_atoi(str4));
	printf("C's ft_atoi = %d\n", atoi(str4));
	return(0);
}*/
