/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdi-noce <kdi-noce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:32:12 by kdi-noce          #+#    #+#             */
/*   Updated: 2022/05/09 17:49:12 by kdi-noce         ###   ########.fr       */
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
void	ft_boucle(char **env, t_list **exp)
{
	int i = 1;
	while (env[i])
	{
		ft_lstadd_front(exp, ft_lstnew(env[i]));
		++i;
	}
}
void	ft_export(char **env)
{
	t_list *exp;

	exp = ft_lstnew(env[0]);
	ft_boucle(env, &exp);
	while (exp)
	{
		printf("%s\n", (char *)exp->content);
		exp = exp->next;
	}
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
