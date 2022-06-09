/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dino <dino@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:32:12 by kdi-noce          #+#    #+#             */
/*   Updated: 2022/06/09 18:02:55 by dino             ###   ########.fr       */
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

void	ft_env(t_list *list, t_list *first_chain)
{
	ft_printexp(list, first_chain);
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

void 	ft_echo_n(char *input)
{
	int	i;
	char *str;

	i = 3;
	while (input[i])
	{
		str = ft_strjoin(str, input);
		if (input[i + 1])
			str = ft_strjoin(str, " ");
		str++;
		i++;
	}
	printf("%s", str);
}

t_list	*ft_export(char *input, t_list **list)
{
	int		i;

	i = 2;
	if (ft_strcmp("export", input) == 0 && count_words(input, ' ') > 1)
	{
		while (input[i])
		{
			printf("%d\n", ft_lstsize(*list));
			if (ft_str_search(input, '=') == 0)
			{
				ft_lstadd_back(list, ft_lstnew(input, 20));
				return (*list);
			}
			i++;
		}
	}
	return (NULL);
}

void 	ft_echo(char *input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (input[i] == '\n')
		{
			printf("\n");
			i++;
		}
		printf("%s", input);
		if (input[i + 1] == 0)
			break;
		printf(" ");
		i++;
	}
	// printf("%s", str);
}
