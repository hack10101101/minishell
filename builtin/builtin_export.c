/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dino <dino@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:32:12 by kdi-noce          #+#    #+#             */
/*   Updated: 2022/06/22 07:36:00 by dino             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

// void	print_list(char **str)
// {
// 	int	i;

// 	i = 0;
// 	bubble_sort(str);
// 	while (str[i])
// 	{
// 		printf("declare -x %s\n", str[i]);
// 		i++;
// 	}
// }

void	print_list(char **str, t_list **list)
{
	int	h;

	h = 0;
	bubble_sort(str);
	if (*str && !*list)
		printf("1\n");
	while (str[h] && *list)
	{
		(*list)->content = str[h];
		printf("declare -x %s\n", (char *)(*list)->content);
		*list = (*list)->next;
		h++;
	}
}

void	print_tab(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		printf("str[%d] = %s\n", i, str[i]);
		i++;
	}
}

char	*manage_b_and_end_quotation(char *s1, char *s2, int l)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i <= l)
	{
		if (i == 0)
		{
			s1[i] = s2[j];
			i++;
			s1[i] = '"';
			i++;
			j++;
		}
		s1[i] = s2[j];
		if (i == l)
			s1[i] = '"';
		i++;
		j++;
	}
	return (s1);
}

char	*manage_end_str(char *str, int len)
{
	char	*temp;
	int		l;
	int		i;

	i = 0;
	l = len + 1;
	temp = calloc(len + 1, sizeof(char *));
	temp = manage_b_and_end_quotation(temp, str, l);
	i = 0;
	while (temp[i])
	{
		str[i] = temp[i];
		i++;
	}
	free(temp);
	return (str);
}

void	manage_quotation(char **str)
{
	int	l;
	int i;
	char *temp;

	l = 0;
	i = 0;
	str[1] = ft_strchr(str[1], '=');
	printf("str > '%c'\n", str[1][l]);
	l = ft_strlen(str[1]);
	printf("l > '%d'\n", l);
	temp = calloc(l, sizeof(char *));
	ft_strlcat(temp, str[1], l + 3);
	temp = manage_end_str(temp, l);
	printf("temp > '%s'\n", temp);
	while (temp[i])
	{
		str[1][i] = temp[i];
		i++;
	}
	printf("str[%s]\n", str[1]);
}

char	**search_args(char *input, t_list **list, int i)
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
	// if (check_if_similar(str, count) == 1)
	// 	printf("\n");
	manage_quotation(str);
	// if (the_first_args(input) == 1)
	// 	stock_args_in_list(str, list);
	// if (the_first_args(input) == 2)
	// 	return (str);
	// print_tab(str);
	return (NULL);
}

char	**order_list(t_list *list, char *input)
{
	char	**str;
	int		len_str;
	int		len_list;
	int		h;
	t_list	*nlst = list;

	len_str = 0;
	h = 0;
	str = NULL;
	len_list = ft_lstsize(list);
	str = ft_calloc(len_list + 1, sizeof(char *));
	while (list)
	{
		len_str = ft_strlen((char *)list->content);
		str[h] = ft_calloc(len_str + 1, sizeof(char));
		str[h] = (char *)list->content;
		list = list->next;
		h++;
	}
	if (the_first_args(input) == 0 || the_first_args(input) == 1)
		print_list(str, &nlst);
	if (the_first_args(input) == 2)
		return (str);
	return (NULL);
}

t_list	*ft_export(char *input, t_list **list)
{
	int		i;

	i = 0;
	while (input[i])
		i++;
	if (i == 6)
		order_list(*list, input);
	else
		search_args(input, list, i);

	return (NULL);
}