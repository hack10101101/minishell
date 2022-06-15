/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fctannexe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdi-noce <kdi-noce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 15:26:02 by kdi-noce          #+#    #+#             */
/*   Updated: 2022/06/15 19:05:47 by kdi-noce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int ft_str_search(char *str, int i, int count)
{
	while(i >= 0)
	{
		if (str[i] == '=')
			count++;
		i--;
	}
	return (count);
}

int	ft_boucle(char *input, char c, int i)
{	
	while (input[i] == c)
		i++;
	return (i);
}

void	manage_rb(t_data *global)
{
	int	x;
	int	y;
	int	temp;

	temp = 0;
	x = 0;
	y = 0;
	if (!(global->tab[0]))
		ft_exit(global, 1);
	while (x < global->len_a)
	{
		if (x == 0)
		{
			temp = global->tab[0][0];
			global->tab[0][0] = global->tab[0][1];
			x++;
		}
		if (x == global->len_a - 1)
			global->tab[0][x] = temp;
		else
			global->tab[0][x] = global->tab[0][x + 1];
		x++;
	}
}