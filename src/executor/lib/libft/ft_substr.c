/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 17:18:25 by tbaker            #+#    #+#             */
/*   Updated: 2023/08/26 20:40:53 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	size_t	i;

	i = 0;
	if (start > ft_strlen(s))
	{
		subs = (char *)malloc(1);
		if (subs == NULL)
			return (NULL);
		subs[0] = '\0';
		return (subs);
	}
	if (len > (ft_strlen(s) - start))
		len = (ft_strlen(s) - start);
	subs = (char *)malloc(sizeof(char) * (len +1));
	if (subs == NULL)
		return (NULL);
	while (i < len)
	{
		subs[i] = s[start + i];
		i++;
	}
	subs[i] = '\0';
	return (subs);
}
/*
int	main(void)
{
	const char *s = "hello world";
	unsigned int start = 1;
	size_t len = 11;

	printf("test 1 = %s\n", ft_substr(s, start, len));
	free(
	return (0);
}*/
