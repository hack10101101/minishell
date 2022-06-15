/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdi-noce <kdi-noce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:32:12 by kdi-noce          #+#    #+#             */
/*   Updated: 2022/06/15 19:09:21 by kdi-noce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	check_alpha(char *s1, char *s2)
{
	int	count;
	int	i;
	int	j;

	i = 0;
	count = 0;
	while (s2[count])
		count++;
	while (s1[i])
	{
		j = 0;
		while(s2[j])
		{
			if (s2[j] == s1[i])
			{
				count--;
				break ;
			}
			j++;
		}
		i++;
	}
	if (count != 0)
		return (1);
	else
		return (0);
}

int	check_list(char **str, t_list *list)
{
	int h;
	int	len;
	char *s;

	while (list)
	{
		h = 1;
		len = ft_strlen((char *)list->content);
		s = (char *)ft_calloc(len, sizeof(char *));
		s = (char *)list->content;
		while (str[h])
		{
			if (check_alpha(str[h], s) == 0)
			{
				return (1);
				free(s);
				break ;
			}	
			h++;
		}
		list = list->next;
	}
	return (0);
}

void	stock_args_in_list(char **str, t_list **list)
{
	int	h;
	
	h = 1;
	printf("%d\n", check_list(str, *list));
	if (check_list(str, *list) == 0)
	{
		while (str[h])
		{
			ft_lstadd_back(list, ft_lstnew(str[h]));
			h++;
		}
	}
}

int	check_if_similar(char **str, int count)
{
	char	*s;
	int		i;

	i = 1;
	s = NULL;
	s = (char *)ft_calloc(count, sizeof(char *));
	while (str[i] && str[i + 1] && count > 1)
	{
		s = str[i];
		if (check_alpha(s, str[i + 1]) != 0)
			i++;
		else if (check_alpha(s, str[i + 1]) == 0)
		{
			return (1);
			break ;
		}
	}
	free(s);
	return (0);
}

void	search_args(char *input, t_list **list, int i)
{
	char **str;
	int h;
	int l;
	int	count;

	h = 0;
	l = 0;
	count = 0;
	count = ft_str_search(input, i, count);
	str = ft_split(input, ' ');
	if (check_if_similar(str, count) == 1)
		printf("\n");
	stock_args_in_list(str, list);
	// h = 0;
	// while(str[h])
	// 	free(str[h]);
}

int	check_first_ltr(char *str, int len_str)
{
	int	i;
	int rank;

	i = 0;
	rank = 0;

	while (i < len_str)
	{
		rank += 127 - str[i];
		i++;
	}
	printf("%d\n", rank);
	return (rank);
}

void	print_list(char **str, int len_list, int temp)
{
	char	**str_sub;
	char	temp;
	int		len_str;
	int		h;
	int		i;

	h = 0;
	i = 0;
	len_str = 0;
	str_sub = ft_calloc(len_list + 1, sizeof(char *));
	while (str[h])
	{
		len_str = ft_strlen(str[h]);
		str_sub[h] = ft_calloc(len_str + 1, sizeof(char));
		str_sub[h] = str[h];
		h++;
	}
	h = 0;
	while (str_sub[h])
	{
		if (str_sub[h][0] >= 65 && str_sub[h][0] <= 90)
		{
			i = 0;
			while (str_sub[i])
			{
				if (str_sub[i][0] < str_sub[i + 1][0])
					str_sub[i]
			}
		}
	}
}

void	order_list(t_list *list)
{
	char	**str;
	// int		count;
	int		len_str;
	int		len_list;
	int		h;
	int		temp;

	// count = 0;
	len_str = 0;
	len_list = 0;
	h = 0;
	str = NULL;

	len_list = ft_lstsize(list);
	str = ft_calloc(len_list + 1, sizeof(char *));
	while (list)
	{
		len_str = ft_strlen((char *)list->content);
		str[h] = ft_calloc(len_str + 1, sizeof(char));
		str[h] = (char *)list->content;
		printf("%s\n", str[h]);
		list = list->next;
		h++;
	}
	temp = h;
	print_list(str, len_list, temp);
}

t_list	*ft_export(char *input, t_list **list)
{
	int		i;

	i = 0;
	while (input[i])
		i++;
	if (i == 6)
	{
		order_list(*list);
		// ft_printexp(*list);
	}
	else
		search_args(input, list, i);

	return (NULL);
}