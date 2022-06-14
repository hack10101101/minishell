/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdi-noce <kdi-noce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:32:12 by kdi-noce          #+#    #+#             */
/*   Updated: 2022/06/13 17:14:49 by kdi-noce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int ft_str_search(char *str, int i)
{
	while(i >= 0)
	{
		if (str[i] == '=')
		{
			return (0);
			break ;
		}
		i--;
	}
	return (1);
}

void	ft_add_str(char *av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		printf("%c", av[i]);
		i++;
	}
}

int	check_args(char *input, int count, int i)
{
	if (ft_str_search(input, i) == 0)
		count++;
	printf("%d\n", count);
	return (count);
}

int	ft_boucle(char *input, char c, int i)
{	
	while (input[i] == c)
		i++;
	return (i);
}

void	stock_args(char *input, int count, t_list **list)
{
	int i;

	i = 7;
	i = ft_boucle(input, ' ', i);
	while (input[i])
		printf("%c\n", input[i++]);
	// ft_lstadd_back(list, input);
}

void	search_args(char *input, t_list **list)
{
	static int	count;
	int	i;

	i = 6;
	count = 0;
	i = ft_boucle(input, ' ', i);
	while (input[i])
	{
		if ((input[i] == ' ' && input[i + 1] != ' ') || input[i + 1] == 0)
		{	
			count = check_args(input, count, i);
			stock_args(input, count, list);
		}
		i++;
	}
}

t_list	*ft_export(char *input, t_list **list)
{
	int		i;

	i = 0;
	while (input[i])
		i++;
	if (i == 6)
		ft_printexp(*list);
	else
	{
		search_args(input, list);		
	}

	return (NULL);
}