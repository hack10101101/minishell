/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdi-noce <kdi-noce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 17:36:05 by kdi-noce          #+#    #+#             */
/*   Updated: 2022/05/09 17:32:58 by kdi-noce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void ft_check(char **av, char **env)
{
	if (ft_strncmp("echo", av[1], 4) == 0)
	{
		if (ft_strncmp("-n", av[2], 2) == 0)
			ft_echo_n(av);
		else
			ft_echo(av);
	}
	if (ft_strncmp("env", av[1], 3) == 0)
		ft_env(env);
	if (ft_strncmp("pwd", av[1], 3) == 0)
		ft_pwd(env);
	if (ft_strncmp("export", av[1], 7) == 0)
		ft_export(env);
}

int	main(int ac, char **av, char **env)
{
	// t_args args;

	if (ac < 2)
		return (1);
	ft_check(av, env);
	
	return (0);
}