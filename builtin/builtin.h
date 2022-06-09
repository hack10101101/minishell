/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dino <dino@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 13:40:09 by kdi-noce          #+#    #+#             */
/*   Updated: 2022/06/09 14:46:29 by dino             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stddef.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../srcs/libft/libft.h"
# include "../srcs/printf/ft_printf.h"

typedef struct s_args
{
	int		ac;
	char	**av;
	int		av_len;
}			t_args;


void	ft_check(char *input, char **env, t_list *list, t_list *first_chain);
void	ft_printexp(t_list *list, t_list *first_chain);
void 	ft_echo(char *input);
void 	ft_echo_n(char *input);
void	ft_env(t_list *list, t_list *first_chain);
void	ft_pwd(char **env);
t_list	*ft_export(char *input, t_list **list);
int 	ft_str_search(char *str, char c);

#endif