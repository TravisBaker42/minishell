/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 16:47:54 by tbaker            #+#    #+#             */
/*   Updated: 2023/09/24 16:55:57 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcpy(const char *str, char *str1)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		str1[i] = str[i];
		i++;
	}
	str1[i] = '\0';
	return (str1);
}

char	*ft_strdup(const char *src)
{
	int		len;
	char	*scopy;

	len = ft_strlen(src);
	scopy = (char *) malloc(sizeof(char) * len + 1);
	if (scopy == NULL)
		return (NULL);
	ft_strcpy(src, scopy);
	return (scopy);
}
/*int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		printf("%s\n", argv[1]);
		printf("%s\n", ft_strdup(argv[1]));
		return (1);
	}
	else 
		return (0);
}*/
