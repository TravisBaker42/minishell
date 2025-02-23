/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 11:55:44 by tbaker            #+#    #+#             */
/*   Updated: 2025/02/23 15:13:10 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	MINISHELL_H
#define	MINISHELL_H

#include "../libft/libft.h"

/* ************************************************************************** */
/*								MACROS										  */
/* ************************************************************************** */
# define EXIT_SUCCESS 0
# define EXIT_FAILURE 1
# define SUCCESS 0
# define FAILURE 1

/* ************************************************************************** */
/*								ENUMS										  */
/* ************************************************************************** */

//we gotta rename these bad boys to what they do. Mainly Greater_Greater down to LESSER.
typedef enum e_token {
	PIPE = 1,
	TRUNC,//>
	APPEND,//>>
	LESSER_LESSER,//<< still needs function built
	INPUT,//<
	WORD,
	SPACE,
	TOKEN_EOF,
} t_token;

/* ************************************************************************** */
/*								STRUCTS										  */
/* ************************************************************************** */

typedef struct	s_token_list
{
	t_token				token_type;
	char				*token_value;
	struct s_token_list	*next;
} t_token_list;

typedef struct	s_cmd_list
{
	char				**cmds;
	t_token				token_type;
	struct s_cmd_list	*next;
	struct s_cmd_list	*prev;
} t_cmd_list;

typedef struct	s_env_lst
{
	char				*env_var;
	struct s_env_lst	*next;
}	t_env_lst;

// not sure if still relevant
typedef struct s_lvl_lst
{
	int					lvl;
	t_env_lst			*env_lst;
	struct s_lvl_lst	*next;
}	t_lvl_lst;

//need to init the int in down for the data struct
typedef struct	s_data
{
	t_token_list	*token;
	t_cmd_list		*cmd_list;
	t_lvl_lst		*lvl_lst;
	char			**envp;
	int	in;
	int	out;
	int	fd_in;
	int fd_out;
	int	pipe_in;
	int pipe_out;
	int	pid;
	int	is_parent;
	int ret;
	int	no_exec;
} t_data;

/* ************************************************************************** */
/*						   FUNCTION PROTOTYPES								  */
/* ************************************************************************** */

// minishell.c //will move into utils or something
void			ft_free_malloc(t_data *data);
void			ft_init_data(t_data *data, char **envp);

// ft_env_lst.c
void			ft_free_env_lst(t_env_lst **env_token);
t_env_lst		*ft_new_env_lst(char *env_var);
void			ft_env_lst_add_back(t_env_lst **head_env, t_env_lst *new_node);
void			ft_new_env_node(t_env_lst **mini_env_lst, char *env_var);
t_env_lst		*ft_env_lst(char **envp);

// ft_init_env.c //one too many function need to move one for norm 
void			ft_init_env(t_data *data);
void			ft_init_lvl(t_data *data, t_lvl_lst **head_lvl);
t_env_lst		*ft_copy_env_lst(t_env_lst *new_lst);
void			ft_new_lvl_node(t_lvl_lst **head_lvl, int lvl, t_env_lst *env_lst);
void			ft_lvl_lst_add_start(t_lvl_lst **head_lvl, t_lvl_lst *new_node);
t_lvl_lst		*ft_new_lvl_lst(int lvl, t_env_lst *env_lst);

// parser.c
void			ft_init_cmd_list(t_data *data, t_token_list **token_start, t_token_list *token_current, int len);
char			**ft_copy_token_value(t_data *data, t_token_list **token_start, int len);
void			ft_create_cmds_arrays(t_data *data, t_token_list *token_start, t_token_list *token_current);
void			ft_parser(t_data *data);

// parser_utils.c
void			ft_new_cmd_token_node(t_cmd_list **cmd_list, char **cmds, t_token token_type);
void			ft_cmd_list_add_back(t_cmd_list **head_cmd, t_cmd_list *new_node);
t_cmd_list		*ft_new_cmd_list(char **cmds, t_token token_typed);
void			ft_free_cmd_list(t_cmd_list **head_cmd);

// lexer.c
t_token_list	*ft_lexer(const char *input);
void			ft_tokenizer(t_token_list **head_list, const char *input);

// lexer_utils.c <----------------remove test function
t_token_list	*ft_new_token(t_token token_type, char *token_value);
void			ft_token_list_add_back(t_token_list **head_token, t_token_list *new_node);
void			ft_new_token_node(t_token_list **head_token, t_token token_type, char *token_value);
void			ft_test_print_list(t_token_list **head_token); // <<-----------------------remove only 4 testing
void			ft_free_token_list(t_token_list **tokens);

// lexer_token_functions_1.c
int				ft_pipe(t_token_list **head_token, char *token_value);
int				ft_word(t_token_list **head_token, const char *input, int i);
int				ft_space(t_token_list **head_token, const char *input, int i);
int				ft_greater_lesser(t_token_list **head_token, const char *input, int i);
char			*ft_return_word(const char *input, int start, int end);

// lexer_token_functions_2.c
int				ft_d_quotes(t_token_list **head_token, const char *input, int i);
char			*ft_return_d_quotes(const char *input, int start, int end);
int				ft_s_quotes(t_token_list **head_token, const char *input, int i);
char			*ft_return_s_quotes(const char *input, int start, int end);
int				ft_quotes(t_token_list **head_token, const char *input, int i);

// utils.c
void			ft_freetabs(char **tab);
void			ft_close(int fd);

//excutor.c
int				ft_type_id(t_cmd_list *node, t_token token);
t_cmd_list		*ft_next_sep(t_cmd_list *origin);
t_cmd_list		*ft_prev_sep(t_cmd_list *origin);
void			ft_executor(t_data *data, t_cmd_list *cmd, char **envp);

//redir.c
void			ft_redir(t_data *data, t_cmd_list *node, int token);
void			ft_input(t_data *data, t_cmd_list *node, int token);
int				ft_quick_pipe(t_data *data);

//builtins.c
int				ft_is_it_builtin(char *cmd);
int				ft_exec_builtins(char **cmd, t_data *data);

//cmd_exe.c
char			*ft_get_path(char *cmd);
void			ft_execvp(char **cmd, char **envp);
int				ft_exec_bin(char **cmd, char **envp);
void			ft_exec_cmd(t_data *data, t_cmd_list *node, char **envp);//may change cmd_list back to node



/*
// ft_pipe_central.c
char			*ft_get_path(char *cmd);
void			ft_execvp(char **cmd, char **envp);
void			ft_child_process(t_cmd_list **cmd_list, int *fd, int fd_read, char **envp);
void			ft_parent_process(int *fd, int *fd_read);
void			ft_pipe_central(t_cmd_list *cmd_list, char **envp);

// ft_executor.c
void			ft_executor(t_data *data);
*/

/*
void			ft_pipe_central(char ***cmd, char **envp);
void			ft_parent_process(int *fd, int *fd_read);
void			ft_child_process(char ***cmd, int *fd, int *fd_read, char **envp);
void			ft_execvp(char **cmd, char **envp);
char			*get_path(char *cmd);
*/


// Buitins:
//int				ft_pwd(void);

#endif
