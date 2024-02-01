/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expande_helper_3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrakik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:33:01 by hrakik            #+#    #+#             */
/*   Updated: 2023/03/03 15:33:02 by hrakik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_search_exp(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_cherche(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_cherche_me(char *s, char c, char f)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c || s[i] == f)
			return (1);
		i++;
	}
	return (0);
}

int	find_vare_2(char *s, int index)
{
	while (s[index] && s[index] != '$')
		index++;
	return (index);
}

int	count_var(char *s, int index)
{
	int	c;

	c = 0;
	while (s[index] && (ft_isalpha(s[index]) == 1
			|| s[index] == '_' ))
	{
		index++;
		c++;
	}
	if (s[index] && (ft_isdigit(s[index]) == 1))
	{
		while (s[index] && (ft_isdigit(s[index]) == 1))
		{
			index++;
			c++;
		}
	}
	return (c);
}
