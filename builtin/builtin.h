/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdi-noce <kdi-noce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 13:40:09 by kdi-noce          #+#    #+#             */
/*   Updated: 2022/06/07 15:33:50 by kdi-noce         ###   ########.fr       */
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

void	ft_check(int ac, char **av, char **env, t_list *list);
void 	ft_echo(char **av);
void 	ft_echo_n(char **av);
void	ft_env(t_list *list);
void	ft_pwd(char **env);
t_list	*ft_export(int ac, char **av, t_list **list);
void	ft_printexp(t_list *list);
int 	ft_str_search(char *str, char c);

#endif