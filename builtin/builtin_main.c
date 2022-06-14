/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdi-noce <kdi-noce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 17:36:05 by kdi-noce          #+#    #+#             */
/*   Updated: 2022/06/13 15:28:42 by kdi-noce         ###   ########.fr       */
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

int	the_first_args(char *input)
{
	int	i;

	i = 0;
	while (input[i] != ' ' && input[i])
		i++;
	if (ft_strncmp("export", input, i) == 0)
		return (1);
	return (0);
}

void ft_check(char	*input, char **env, t_list *list)
{
	(void) env;
	if (the_first_args(input) == 1)
		ft_export(input, &list);
}

int	main(int argc, char **argv, char **env)
{
	// t_list	*first = NULL;
	t_list	*list;
	char	*input;

	(void)	argc;
	(void)	argv;
	ft_lstenv(env, &list);
	while(1)
	{
		input = readline("minishell ˜ ");
		ft_check(input, env, list);
	}
	return (0);
}
