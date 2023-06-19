/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expande_helper_4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrakik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 16:11:09 by hrakik            #+#    #+#             */
/*   Updated: 2023/03/13 16:11:11 by hrakik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_count_var(char *yum)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (yum[i])
	{
		if (yum[i] == '=')
		{
			i++;
			while (yum[i])
			{
				i++;
				c++;
			}
			break ;
		}
		i++;
	}
	return (c);
}

char	*skip_var(char *yum)
{
	int		i;
	int		j;
	int		c;
	int		h;
	char	*new;

	j = 0;
	i = 0;
	h = 0;
	c = ft_count_var(yum);
	new = ft_calloc(c + 1, sizeof(char));
	while (yum[i])
	{
		if (yum[i] == '=')
			break ;
		i++;
	}
	i++;
	while (yum[i])
	{
		new[h] = yum[i];
		i++;
		h++;
	}
	return (new);
}
