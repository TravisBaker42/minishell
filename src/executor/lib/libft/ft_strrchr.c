/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 17:17:41 by tbaker            #+#    #+#             */
/*   Updated: 2023/07/26 17:17:44 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	len;

	len = ft_strlen(str);
	while (len > 0)
	{
		if (str[len] == (unsigned char)c)
			return ((char *)&str[len]);
		len--;
	}
	if (str[len] == (unsigned char)c)
		return ((char *)&str[len]);
	return (NULL);
}
/*
int   main(void)
{
        char *str = "hello world";
        char c = 'o';

        printf("%s\n", ft_strrchr(str, c));
        printf("%s\n", strrchr(str, c));

        return (0);
}*/
