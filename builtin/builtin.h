/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdi-noce <kdi-noce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 13:40:09 by kdi-noce          #+#    #+#             */
/*   Updated: 2022/05/05 18:28:31 by kdi-noce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include <stdio.h>
# include "../srcs/libft/libft.h"

typedef struct s_args
{
	int		ac;
	char	**av;
	int		av_len;
}			t_args;

void	ft_check(char **av, char **env);
void 	ft_echo(char **av);
void 	ft_echo_n(char **av);
void	ft_env(char **env);
void	ft_pwd(char **env);

#endif