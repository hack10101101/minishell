/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdi-noce <kdi-noce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 17:36:05 by kdi-noce          #+#    #+#             */
/*   Updated: 2022/05/30 16:10:56 by kdi-noce         ###   ########.fr       */
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
	if (ft_strncmp("env", av[1], 3) == 0 && ac != 2)
		ft_print_error(0, av);
}

void ft_check(int ac, char **av, char **env, t_list *list)
{
	t_list *temp;

	temp = NULL;
	ft_condition_error(ac, av);
	if (ft_strncmp("echo", av[1], 4) == 0)
	{
		if (ft_strncmp("-n", av[2], 2) == 0)
			ft_echo_n(av);
		else
			ft_echo(av);
	}
	if (ft_strncmp("env", av[1], 3) == 0)
		ft_env(list);
	if (ft_strncmp("pwd", av[1], 3) == 0)
		ft_pwd(env);
	if (ft_strncmp("export", av[1], 7) == 0)
	{
		ft_export(ac, av, list, temp); 
	}
}

int	main(int argc, char **argv, char **env)
{
	t_list	*list;
	
	list = NULL;
	ft_lstenv(env, &list);
	if (argc < 2)
		return (1);
	ft_check(argc, argv, env, list);
	return (0);
}

// void	ft_lstenv(char **env, t_list **pile)
// {
// 	// t_list *temp;
// 	t_list	*exp;
// 	int		i;
	
// 	i = 1;
// 	exp = malloc(sizeof(t_list*));
// 	exp->content = env[0];
// 	exp->prev = *pile;
// 	*pile = exp;

// 	// while (env[i] < 0)
// 	// {
// 	// 	printf("%s\n", exp->content);
// 	// 	ft_lstadd_back(&exp, ft_lstnew(env[i]));
// 	// 	exp = exp->next;
// 	// 	i++;
// 	// }
// 	// exp = NULL;
// 	// while (exp->next)
// 	// {
// 	// 	printf("%s\n", exp->content);
// 	// 	exp = exp->next;
// 	// }
// }