/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdi-noce <kdi-noce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:12:06 by kdi-noce          #+#    #+#             */
/*   Updated: 2022/05/02 15:44:21 by kdi-noce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst)
	{
		(*del)(lst->content);
		free(lst);
	}
}

// int main (void)
// {
// 	t_list *test;
// 	t_list *add;

// 	test = ft_lstnew("test");
// 	add = ft_lstnew("add");
// 	ft_lstdelone(&test, add);
	
// 	printf("test: %s\n", test->content);

// 	return (0);
// }
