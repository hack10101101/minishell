/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdi-noce <kdi-noce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 17:40:24 by kdi-noce          #+#    #+#             */
/*   Updated: 2022/06/13 11:18:56 by kdi-noce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstnew(void *content)
{
	t_list	*new_content;

	// new_content = NULL;
	new_content = (t_list *)malloc(sizeof(t_list));
	new_content->content = ft_strdup(content);
	new_content->next = NULL;

	return (new_content);
}