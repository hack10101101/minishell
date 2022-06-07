/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdi-noce <kdi-noce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:32:12 by kdi-noce          #+#    #+#             */
/*   Updated: 2022/06/07 17:18:14 by kdi-noce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int ft_str_search(char *str, char c)
{
	int	i;

	i = 0;
	if (str[i] != c)
	{
		while (str[i] != c && str[i])
		{
			printf("%c\n", str[i]);
			if (str[i] != c)
				i++;
			else
				break;
		}
		if (str[i] != c)
			return (1);
	}
	return (0);
}

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

t_list	*ft_export(int ac, char **av, t_list **list)
{
	int		i;

	i = 2;
	if (ft_strncmp("export", av[1], 7) == 0 && ac > 2)
	{
		while (av[i])
		{
			printf("%d\n", ft_lstsize(*list));
			if (ft_str_search(av[i], '=') == 0)
			{
				ft_lstadd_back(list, ft_lstnew(av[i]));
				return (*list);
			}
			i++;
		}
	}
	return (NULL);
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
