/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdi-noce <kdi-noce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 18:29:16 by kdi-noce          #+#    #+#             */
/*   Updated: 2022/06/18 20:42:39 by kdi-noce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	ft_env(t_list *list, char *input)
{
	order_list(list, input);
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

void 	ft_echo_n(char *input, int i)
{
	while (input[i] == ' ')
		i++;
	while (input[i])
	{
		printf("%c", input[i]);
		i++;
	}
}

void 	ft_echo(char *input)
{
	int	i;
	int j;

	i = 5;
	j = 0;
	while (input[i] != ' ' && input[i])
		i++;
	if (ft_strncmp("-n", input, i))
		ft_echo_n(input, i);
	else
	{	
		while (input[i])
		{
			if (input[i] == '\n')
				printf("\n");
			printf("%c", input[i]);
			i++;
		}
		printf("\n");
	}
}

void 	ft_exit(void)
{
	exit(1);
}

t_list	*ft_unset(char *input, t_list **list)
{
	int		i;
	int		x;
	char 	**str;
	char	**search;

	i = 0;
	while (input[i])
		i++;
	search = search_args(input, list, i);
	str = order_list(*list, input);
	i = 0;
	x = 1;
	while (str[i])
	{
		// printf("%s\n", str[i]);
		printf("unset = %s\n", search[x]);
		if (str[i] == search[x])
		{
			printf("unset = %s\n", str[i]);
			x++;
		}
		i++;
	}
	i = 0;
	while (str[i])
		printf("%s\n", str[i++]);
	return (NULL);
}