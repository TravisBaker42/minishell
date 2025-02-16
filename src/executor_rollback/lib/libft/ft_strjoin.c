/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 16:24:40 by tbaker            #+#    #+#             */
/*   Updated: 2023/09/17 15:12:48 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft_catcopy(char const *s1, char const *s2, 
		char *scopy, size_t tlen)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	while (s1[i] != '\0' && j < tlen)
	{
		scopy[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2[i] != '\0' && j < tlen)
	{
		scopy[j] = s2[i];
		i++;
		j++;
	}
	scopy[j] = '\0';
	return (scopy);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*scopy;
	size_t	s1len;
	size_t	s2len;
	size_t	tlen;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	tlen = s1len + s2len;
	scopy = (char *)malloc(sizeof(char) * (tlen + 1));
	if (scopy == NULL)
		return (NULL);
	ft_catcopy(s1, s2, scopy, tlen);
	return (scopy);
}
/*
int	main(void)
{
	char const *s1 = "Please be nice";
	char const *s2 = " or no cake for you!";
	printf("my result = %s\n", ft_strjoin(s1, s2));
	return (0);
}*/
