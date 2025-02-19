/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeschill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 14:05:42 by jeschill          #+#    #+#             */
/*   Updated: 2025/02/19 13:56:49 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTING_H
# define TESTING_H

# define CMD 0
# define TRUNC 1
# define APPEND 2
# define INPUT 3 
# define PIPE 4 
# define END 5

typedef struct s_node
{
	char			**cmd;
	int				token_type;
	struct s_node	*next;
	struct s_node	*prev;//added
}	t_node;

typedef struct	s_data
{
	t_node	*start;//cmd_list pointer in data 
//all below into 
	int		in;
	int		out;
	int		fd_in;
	int		fd_out;
	int		pipe_in;
	int		pipe_out;
	int		pid;
	int		is_parent;
	int		ret;
	int		no_exec;
}	t_data;

//cmd_exe.c
char	*ft_get_path(char *cmd);
void	ft_execvp(char **cmd, char **envp);
int		exec_bin(char **cmd, char **envp);
void	exec_cmd(t_data *data, t_node *node, char **envp);

// utils.c
void	ft_close(int fd);//
void	ft_freetabs(char **tabs);//Have in utils or something
int		type_id(t_node *node, int type);
t_node	*next_sep(t_node *origin);
t_node	*prev_sep(t_node *origin);

//executor.c
//char	**dup_cmd(char **cmd);
//t_node	*create_node(int tk_type, char **cmd);
void	executor(t_data *data, t_node *cmd, char **envp);//added arguments changed

//redir.c
void	redir(t_data *data, t_node *node, int token);//added
void	input(t_data *data, t_node *node, int token);//added
int		quick_pipe(t_data *data); //added

//builtins.c
int		is_it_builtin(char *cmd);//added
int		exec_builtins(char **cmd, t_data *data);//added




//void	ft_pipe_central(char ***cmd, char **envp);
//void	ft_parent_process(int *fd, int *fd_read);
//void	ft_child_process(char ***cmd, int *fd, int fd_read, char **envp);
//void	ft_execvp(char **cmd, char **envp);
//char	*ft_get_path(char *cmd);
//void	ft_freetabs(char **tabs);

#endif
