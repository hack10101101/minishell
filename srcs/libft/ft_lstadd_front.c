/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdi-noce <kdi-noce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 17:50:50 by kdi-noce          #+#    #+#             */
/*   Updated: 2022/05/30 13:54:44 by kdi-noce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstadd_front(t_list **lst, t_list *new)
{
	if (*lst == NULL)
		*lst = new;
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}

// int main (void)
// {
// 	t_list *test;
// 	t_list *add;

// 	test = ft_lstnew("test");
// 	add = ft_lstnew("add");
// 	ft_lstadd_front(&test, add);
	
// 	printf("test: %s\n", test->content);

// 	return (0);
// }
