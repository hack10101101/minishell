/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdi-noce <kdi-noce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:32:12 by kdi-noce          #+#    #+#             */
/*   Updated: 2022/05/30 16:49:15 by kdi-noce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	ft_env(t_list *list)
{
	ft_printexp(list);
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

void	ft_export(int ac, char **av, t_list *list, t_list *temp)
{
	(void)	temp;
	int		i;

	i = 2;
	if (ft_strncmp("export", av[1], 7) == 0 && ac > 2)
	{
		while (av[i])
		{
			printf("%s\n", av[i]);
			printf("%s\n", av[i + 1]);
			if (ft_strncmp("=", av[i], 2) == 0 && av[i + 1] == NULL)
			{
				printf("1\n");
				ft_lstadd_back(&list, ft_lstnew(av[i]));
			}
			i++;
		}
	}
	else
		ft_printexp(list);
}

void 	ft_echo(char **av)
{
	int	i;
	int j;

	i = 2;
	j = 0;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] == '\n')
				printf("\n");
			j++;
		}
		printf("%s", av[i]);
		if (av[i + 1] == NULL)
			break;
		printf(" ");
		i++;
	}
	// printf("%s", str);
}
