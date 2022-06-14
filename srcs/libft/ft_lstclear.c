/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdi-noce <kdi-noce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 15:09:05 by kdi-noce          #+#    #+#             */
/*   Updated: 2022/05/02 15:44:23 by kdi-noce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	if (lst)
	{
		if (*lst)
		{
			while (*lst)
			{
				tmp = *lst;
				*lst = tmp->next;
				ft_lstdelone(*lst, del);
			}
		}
	}
}
