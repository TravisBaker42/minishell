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
	GREATER,
	GREATER_GREATER,
	LESSER,
	LESSER_LESSER,

} t_token;

/* ************************************************************************** */
/*								STRUCTS										  */
/* ************************************************************************** */
typedef struct	s_token_list
{
	t_token			token_type;
	char			*token_value;
	struct s_token	*next;
} t_token_list

/* ************************************************************************** */
/*						   FUNCTION PROTOTYPES								  */
/* ************************************************************************** */
// test.c <---- remove function and file.
int ft_test_libft(const char *str);

// lexer.c
t_token_list	**ft_lexer(char *input);
void			check_for_token(t_token_list **head_list, char *input);

// lexer_utils.c <----------------remove test function
t_token_list	*ft_new_token(t_token token_type, char *token_value);
void			ft_token_list_add_back(t_token_list **head_token, t_token_list new_node);
void			ft_test_print_list(t_token_list **head_token);

#endif
