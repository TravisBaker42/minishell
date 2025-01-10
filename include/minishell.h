/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 11:55:44 by tbaker            #+#    #+#             */
/*   Updated: 2025/01/10 18:48:28 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	MINISHELL_H
#define	MINISHELL_H

/* ************************************************************************** */
/*								MACROS										  */
/* ************************************************************************** */
#define EXIT_SUCCESS 0;
#define EXIT_FAILURE 1;

/* ************************************************************************** */
/*								ENUMS										  */
/* ************************************************************************** */
typedef enum e_token {
	PIPE = 1,
	GREATER_GREATER,
	GREATER,
	LESSER_LESSER,
	LESSER,
	D_QUOTE,
	S_QUOTE,
	O_BRACKET,
	C_BRACKET,
	WORD,
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
} t_cmd_list;

typedef struct	s_data
{
	struct t_token_list	*token;
	struct t_cmd_list	*cmd_list;
	char				**envp;
} t_data;

/* ************************************************************************** */
/*						   FUNCTION PROTOTYPES								  */
/* ************************************************************************** */
// test.c <---- remove function and file.
int ft_test_libft(const char *str);

// lexer.c
t_token_list	*ft_lexer(const char *input);
void			ft_tokenizer(t_token_list **head_list, const char *input);

// lexer_utils.c <----------------remove test function
t_token_list	*ft_new_token(t_token token_type, char *token_value);
void			ft_token_list_add_back(t_token_list **head_token, t_token_list *new_node);
void			ft_new_token_node(t_token_list **head_token, t_token token_type, char *token_value);
void			ft_test_print_list(t_token_list **head_token); // <<-----------------------remove only 4 testing
void			ft_free(t_token_list **tokens);

// lexer_token_functions.c
int				ft_pipe(t_token_list **head_token, char *token_value);
int				ft_word(t_token_list **head_token, const char *input, int i);
int				ft_brackets(t_token_list **head_token, const char *input, int i);
int				ft_greater_lesser(t_token_list **head_token, const char *input, int i);
char			*ft_return_word(const char *input, int start, int end);

// lexer_token_functions.c
int				ft_d_qoutes(t_token_list **head_token, const char *input, int i);
char			*ft_return_d_qoutes(const char *input, int start, int end);

// utils.c
int				ft_iterates_space(const char *input, int i);
void			ft_freetabs(char **tab);

//executors/
/*
void			ft_pipe_central(char ***cmd, char **envp);
void			ft_parent_process(int *fd, int *fd_read);
void			ft_child_process(char ***cmd, int *fd, int *fd_read, char **envp);
void			ft_execvp(char **cmd, char **envp);
char			*get_path(char *cmd);
*/

#endif
