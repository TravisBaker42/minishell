/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeschill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 14:05:42 by jeschill          #+#    #+#             */
/*   Updated: 2024/12/21 15:23:19 by jeschill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTING_H
# define TESTING_H

void	ft_pipe_central(char ***cmd, char **envp);
void	ft_parent_process(int *fd, int *fd_read);
void	ft_child_process(char ***cmd, int *fd, int fd_read, char **envp);
void	ft_execvp(char **cmd, char **envp);
char	*ft_get_path(char *cmd);
void	ft_freetabs(char **tabs);

#endif
