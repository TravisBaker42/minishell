/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 17:46:59 by tbaker            #+#    #+#             */
/*   Updated: 2023/07/30 19:23:33 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}
/*
void	f(unsigned int i, char *s)
{
	printf("Look up %s you died x %d times!\n", s, i);
	if (i == 15)
		printf("Your brown bread\n");
}

int	main(void)
{
	char	*s = "death from above";
	
	ft_striteri(s, f);
	return (0);
}*/
