/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_herdoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrakik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 09:35:29 by hrakik            #+#    #+#             */
/*   Updated: 2023/03/20 09:35:30 by hrakik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	if_sp_char(char c)
{
	if (c == '<' || c == '>' || c == '|')
		return (1);
	return (0);
}

char	*expand_herdoc(char *a, char **env)
{
	int	j;
	int	i;

	i = 0;
	j = 0;
	if (ft_cherche(a, '$') == 1 && ft_cherche(a, '<') == 0)
	{
		j = count_dollar(a);
		a = expande_var(a, env, j, i);
	}
	return (a);
}

int	count_var_2(char *s, int index)
{
	int	c;

	c = 0;
	while (s[index] && (s[index] == '_' || s[index] == '?'))
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

int	helper_var_count_spt(char *s, int i)
{
	int	c;

	c = 0;
	c = count_var(s, i + 1);
	if (c == 0)
		c = count_var_2(s, i + 1);
	return (c);
}
