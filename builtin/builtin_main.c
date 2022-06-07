/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdi-noce <kdi-noce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 17:36:05 by kdi-noce          #+#    #+#             */
/*   Updated: 2022/06/07 17:10:23 by kdi-noce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	ft_printexp(t_list *list)
{
	while (list)
	{
		printf("list: %s\n", list->content);
		list = list->next;
	}
}

void	ft_lstenv(char **env, t_list **list)
{
	int		args;

	args = 0;
	while (env[args])
	{
		ft_lstadd_back(list, ft_lstnew(env[args]));
		args++;
	}
}

void	ft_print_error(int idx_error, char **av)
{
	if (idx_error == 0)
	{
		printf("%s : %s: No such file or directory\n", av[1], av[2]);
		exit(1);
	}
}

void	ft_condition_error(int ac, char **av)
{
	if (ft_strcmp("env", av[1]) == 0 && ac != 2)
		ft_print_error(0, av);
}

void ft_check(int ac, char **av, char **env, t_list *list)
{
	ft_condition_error(ac, av);
	if (ft_strcmp("echo", av[1]) == 0)
	{
		if (ft_strcmp("-n", av[2]) == 0)
			ft_echo_n(av);
		else
			ft_echo(av);
	}
	if (ft_strcmp("env", av[1]) == 0)
		ft_env(list);
	if (ft_strcmp("pwd", av[1]) == 0)
		ft_pwd(env);
	if (ft_strcmp("export", av[1]) == 0)
	{
		ft_export(ac, av, &list);
	}
}

int	main(int argc, char **argv, char **env)
{
	t_list	*list;
	char	*input;
	(void)	argc;
	(void)	argv;	

	list = NULL;
	ft_lstenv(env, &list);	
	while(1)
	{
		input = readline("minishell ˜ ");
		// if (argc < 2)
		// 	return (1);
		// ft_check(argc, argv, env, list);
	}
	return (0);
}
