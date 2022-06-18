/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdi-noce <kdi-noce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 13:40:09 by kdi-noce          #+#    #+#             */
/*   Updated: 2022/06/18 20:23:39 by kdi-noce         ###   ########.fr       */
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

int		the_first_args(char *input);
void	ft_check(char *input, char **env, t_list *list);
void 	ft_echo(char *input);
void 	ft_echo_n(char *input, int i);
void	ft_env(t_list *list, char *input);
void	ft_pwd(char **env);
void	ft_printexp(t_list *list);
int 	ft_str_search(char *str, int i, int count);
t_list	*ft_unset(char *input, t_list **list);

/* BUILTIN_EXPORT */

t_list	*ft_export(char *input, t_list **list);
int		check_list(char **str, t_list *list);
char	**order_list(t_list *list, char *input);
void	print_list(char **str, t_list **list);
// void	print_list(char **str);

/* BUILTIN_EXPORT */

int		check_if_similar(char **str, int count);
void	stock_args_in_list(char **str, t_list **list);
int		check_alpha(char *s1, char *s2);
char	**search_args(char *input, t_list **list, int i);

/* ft_FCT_ANNEXE */

int		ft_boucle(char *input, char c, int i);
void	bubble_sort(char **array);

/*	BUILTINS	*/

void 	ft_exit(void);

#endif