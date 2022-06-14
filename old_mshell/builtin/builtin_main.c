/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dino <dino@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 17:36:05 by kdi-noce          #+#    #+#             */
/*   Updated: 2022/06/09 18:06:02 by dino             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	ft_printexp(t_list *list, t_list *first_chain)
{
	list = first_chain;
	printf("3\n");
	while (list)
	{
		printf("list: %s\n", (char *)list->content);
		list = list->next;
	}
	printf("4\n");
}

void	ft_lstenv(char **env, t_list **list)
{
	int		i;

	i = 1;
	printf("1\n");
	while (env[i])
	{
		ft_lstadd_back(list, ft_lstnew(env[i], ft_strlen(env[i])));
		*list = (*list)->next;
		i++;
	}
	printf("2\n");
}

//void	ft_print_error(int idx_error, char *input)
//{
//	if (idx_error == 0)
//	{
//		printf("error : %s\n", input);
//		//printf("%s : %s: No such file or directory\n", input, av[2]);
//		exit(1);
//	}
//}

//void	ft_condition_error(char *input)
//{
//	if (ft_strcmp("env", input) == 0 && count_words(input, ' ') != 1)
//		ft_print_error(0, input);
//}

//void	ft_check(char *input, char **env, t_list *list, t_list *first_chain)
//{
//	ft_condition_error(input);
//	if (ft_strcmp("echo", input) == 0)
//	{
//		if (ft_strcmp("-n", input) == 0)
//			ft_echo_n(input);
//		else
//			ft_echo(input);
//	}
//	if (ft_strcmp("env", input) == 0)
//		ft_env(list, first_chain);
//	if (ft_strcmp("pwd", input) == 0)
//		ft_pwd(env);
//	if (ft_strcmp("export", input) == 0)
//	{
//		ft_export(input, &list);
//	}
//}

int	main(int argc, char **argv, char **env)
{
	t_list	*list;
	t_list	**first_chain;
	//t_args	*arg;
	//char	*input;

	list = ft_lstnew(env[0], ft_strlen(env[0]));
	first_chain = list;
	ft_lstenv(env, &list);
	ft_printexp(list, first_chain);
	printf("5\n");
	//while(1)
	//{
	//	input = readline("minishell ˜ ");
	//	printf("%s\n", input);
	//	//if (argc < 1)
	//	//	return (1);
	//	ft_check(input, env, list);
	//}
	free(list);
	free(first_chain);
	return (0);
}
