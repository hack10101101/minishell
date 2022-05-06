/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdi-noce <kdi-noce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:32:12 by kdi-noce          #+#    #+#             */
/*   Updated: 2022/05/05 18:27:01 by kdi-noce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	ft_env(char **env)
{
	while (*env)
	{
		printf("%s\n", *env++);
	}
}

void	ft_pwd(char **env)
{
	while (*env)
	{
		if (ft_strncmp("PWD", *env, 3) == 0)
			printf("%s\n", *env + 4);
		env++;
	}
}

void 	ft_echo_n(char **av)
{
	int	i;
	char *str;

	i = 3;
	while (av[i])
	{
		str = ft_strjoin(str, av[i]);
		if (av[i + 1])
			str = ft_strjoin(str, " ");
		str++;
		i++;
	}
	printf("%s", str);
}

void 	ft_echo(char **av)
{
	int	i;
	char *str;

	i = 2;
	while (av[i])
	{
		// str = ft_strdup(av[i]);
		str = ft_strjoin(str, av[i]);
		if (av[i + 1])
			str = ft_strjoin(str, " ");
		str++;
		i++;
	}
	printf("%s\n", str);
}
