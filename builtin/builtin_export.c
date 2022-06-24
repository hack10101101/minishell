/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dino <dino@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:32:12 by kdi-noce          #+#    #+#             */
/*   Updated: 2022/06/23 08:13:27 by dino             ###   ########.fr       */
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
			printf("manage b = %c\n", s1[i]);
			i++;
			s1[i] = '"';
			printf("manage b = %c\n", s1[i]);
			i++;
			j++;
		
		}
		printf("manage b = %c\n", s1[i]);
		s1[i] = s2[j];
		if (i == l)
			s1[i] = '"';
		printf("manage b = %c\n", s1[i]);
		i++;
		j++;
	}
	return (s1);
}

int		height_str(char **str)
{	
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
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

//char	*add_first_cotation(char **s1, char **s2, int h)
//{
//	int	i;
//	int	j;
//	int	k;

//	i = 0;
//	j = 0;
//	k = 0;
//	while (i < h)
//	{
//		while (s1[i][k])
//		{
//			if (i == 0)
//			{
//				s2[i][j] = s1[i][k];
//				j++;
//				s2[i] = '"';
//				j++;
//				k++;
//			}
//			s2[i][j] = s1[i][k];
//			if (i == l)
//				s2[i] = '"';
//			i++;
//			j++;
//		}
//	}
//}

void	add_quotation(char **temp)
{
	char	**str;
	int	i;
	int	l;
	int	j;
	int h;

	i = 1;
	j = 0;
	h = height_str(temp);
	printf("add : h = %d\n", h);
	str = ft_calloc(h, sizeof(char *));
	while (i < h)
	{
		l = ft_strlen(temp[i]);
		printf("add : l = %d\n", l);
		str[i] = ft_calloc(l + 2, sizeof(char *));
		str[i] = temp[i];
		printf("str = [%s]\n", str[i]);
		temp[i] = manage_b_and_end_quotation(temp[i], str[i], l);
		printf("str = [%s]\n", temp[i]);
		i++;
	}
	//add_first_quotation(str, temp, h);
}

char	**return_equal(char **str)
{
	int	i;
	int h;

	i = -1;
	h = height_str(str);
	printf("h = %d\n", h);
	i = 0;
	while (++i < h)
		str[i] = ft_strchr(str[i], '=');
	return (str);
}

void	manage_quotation(char **str)
{
	char **temp;
	int	l;
	int i;

	l = 0;
	i = 0;
	temp = return_equal(str);
	add_quotation(temp);
	//printf("str = [%s]\n", temp[1]);
	// ret_str = str[1];
	// ret_str = ft_strchr(str[1], '=');
	// printf("str > '%c'\n", ret_str[l]);
	// l = ft_strlen(ret_str);
	// printf("l > '%d'\n", l);
	// temp = calloc(l, sizeof(char *));
	// ft_strlcat(temp, ret_str, l + 3);
	// temp = manage_end_str(temp, l);
	// printf("temp > '%s'\n", temp);
	// while (temp[i])
	// {
	// 	ret_str[i] = temp[i];
	// 	i++;
	// }
	// i = 0;
	// l = 0;
	// printf("str[%s]\n", ret_str);
	// while (str[1][i] != '=')
	// 	i++;
	// while (str[1][i])
	// 	str[1][i++] = ret_str[l++];
	// printf("str > '%s'\n", str[1]);
	// // return (str);
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