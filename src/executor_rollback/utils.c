/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeschill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 14:03:24 by jeschill          #+#    #+#             */
/*   Updated: 2025/02/16 00:06:22 by jeschill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testing.h"
#include "../../libft/libft.h"

///@Brief:	Used to close fds.
///@To_do:	
///@Notes:	We do this because on first run we have the potential of closing STDIN.
void	ft_close(int fd)
{
	if (fd > 0)
		close(fd);
}

void	ft_freetabs(char **tabs)
{
	size_t	i;

	i = 0;
	while (tabs[i])
	{
		free(tabs[i]);
		i++;
	}
	free(tabs);
}

int	type_id(t_node *node, int type)
{
	if (node && node->token_type == type)
		return (1);
	else
		return (0);
}

t_node	*next_sep(t_node *origin);
{
	while (origin && origin->token_type == 0)//1 and above are seperators;
		origin = origin->next;
	return(origin);
}

t_node	*prev_sep();
{
	while (origin && origin->token_type == 0)//1 and above are seperators;
		origin = origin->prev;
	return(origin);
}

