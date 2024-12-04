/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 11:55:44 by tbaker            #+#    #+#             */
/*   Updated: 2024/11/23 11:56:05 by tbaker           ###   ########.fr       */
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
	WORD,
	EOF,

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
void			ft_test_print_list(t_token_list **head_token);
void			ft_free(t_token_list **tokens);

// lexer_token_functions.c
int				ft_pipe(t_token_list **head_token, char *token_value);
int				ft_word(t_token_list **head_token, const char *input, int i);
char			*ft_return_word(const char *input, int start, int end);

// utils.c
int				ft_iterates_space(const char *input, int i);

#endif
