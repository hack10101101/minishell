/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdi-noce <kdi-noce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:32:12 by kdi-noce          #+#    #+#             */
/*   Updated: 2022/06/25 14:58:55 by kdi-noce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

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

char	*manage_b_and_end_quotation(char *s1, char *s2, int len)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	if (s2[0] == 0)
		return (NULL);
	s1[0] = s2[0];
	while (i < len)
	{
		if (i == 1)
		{
			s1[i] = '"';
			i++;
		}
		s1[i] = s2[j];
		if (i == len - 1)
			s1[i] = '"';
		i++;
		j++;
	}
	s1[i] = 0;
	return (s1);
}

void	free_them_all(char **str, int h)
{
	int	i;

	i = 0;
	while (i < h)
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
}

void	print_str(char *note1, char *str, char c, int i, char *note2)
{
	if (c == 0)
		printf("%d: %s[%s]	note -> '%s'\n", i, note1, str, note2);
	else if (c != 0)
		printf("%d: %s[%s]	'%c' note -> '%s'\n", i, note1, str, c, note2);
}

char	*fulling_str(char *str, char *temp, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		str[i] = temp[i];
		i++;
	}
	return (str);
}

void	realloc_str(char *s1, int len, int h, int i)
{
	char	*s2;

	s2 = NULL;
	s2 = (char *)ft_calloc(len + 2, sizeof(char *));
	s2 = &s1[i];
	s1[i] = *(char *)ft_calloc(len + 2, sizeof(char *));
	s1[i] = *fulling_str(&s1[i], s2, len + 2);
	free(s2);
}

void	concat_the_string(char **str, char **temp, int h)
{
	int		quote;
	int 	len;
	int		s1_h;
	int		s2_h;
	int 	s1_l;
	int 	s2_l;

	s1_h = 1;
	s2_h = 1;
	s1_l = 0;
	s2_l = 0;
	len = 0;
	while (s1_h < h)
	{
		len = ft_strlen(str[s1_h]);
		s1_l = 0;
		s2_l = 0;
		quote = 0;
		while (s1_l < len + 2)
		{
			if (quote == 0)
			{				
				while (str[s1_h][s1_l] != '=' && s1_l < len + 1)
					s1_l++;
				quote = 1;
			}
			str[s1_h][s1_l] = temp[s2_h][s2_l];
			s1_l++;
			s2_l++;
		}
		s1_h++;
		s2_h++;
	}
	free_them_all(temp, h);
}

void	add_quotation(char **temp, int h)
{
	char	**str;
	int	i;
	int	l;
	int	j;

	i = 1;
	j = 0;
	printf("%d\n", h);
	str = ft_calloc(h, sizeof(char *));
	while (i < h)
	{
		l = ft_strlen(temp[i]);
		str[i] = ft_calloc(l + 3, sizeof(char *));
		temp[i] = manage_b_and_end_quotation(str[i], temp[i], l + 2);
		i++;
	}
	// free_them_all(str, h);
	//add_first_quotation(str, temp, h);
}

char	**return_equal(char **str, int h)
{
	char	**temp;
	int		i;
	int		l;

	i = 1;
	l = 0;
	temp = ft_calloc(h, sizeof(char *));
	while (i < h)
	{
		l = ft_strlen(str[i]);
		temp[i]= ft_calloc(l + 3, sizeof(char *));
		temp[i] = ft_strchr(str[i], '=');
		i++;
	}
	return (temp);
}

int		height_str(char **str)
{	
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	manage_quotation(char **str)
{
	char **temp;
	int	l;
	int i;
	int h;

	l = 0;
	i = 0;
	h = height_str(str);
	temp = return_equal(str, h);
	add_quotation(temp, h);
	concat_the_string(str, temp, h);
}

char	**search_args(char *input, t_list **list, int i)
{
	char **str;
	int h;
	int l;
	int	count;

	h = 0;
	l = 0;
	i = 1;
	count = 0;
	count = ft_str_search(input, i, count);
	str = ft_split(input, ' ');
	h = height_str(str);
	if (check_if_similar(str, count) == 1)
		printf("\n");
	manage_quotation(str);	
	if (the_first_args(input) == 1)
		stock_args_in_list(str, list);
	if (the_first_args(input) == 2)
		return (str);
	print_tab(str);
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