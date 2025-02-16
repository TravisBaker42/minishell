/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 17:14:28 by tbaker            #+#    #+#             */
/*   Updated: 2023/07/26 17:14:33 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*scopy;

	scopy = malloc(nitems * size);
	if (scopy == NULL)
		return (NULL);
	ft_bzero(scopy, nitems * size);
	return (scopy);
}
