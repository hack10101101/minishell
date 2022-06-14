/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdi-noce <kdi-noce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 18:44:46 by kdi-noce          #+#    #+#             */
/*   Updated: 2022/05/02 15:44:24 by kdi-noce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstlast(t_list *lst)
{
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return(lst);
}

// int main(void)
// {
// 	t_list *test;
// 	// t_list *str;

// 	test = ft_lstnew("essai");
// 	// str = ft_lstnew("str");
// 	ft_last(test);
// 	printf ("%s\n", test->content);
// 	return (0);
// }