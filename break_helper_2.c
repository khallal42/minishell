/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   break_helper_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrakik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 09:54:01 by hrakik            #+#    #+#             */
/*   Updated: 2023/02/25 09:54:02 by hrakik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_set(char *s, int i, char c)
{
	int	p;

	p = 0;
	i++;
	while (s[i])
	{
		if (s[i] == c)
			return (p);
		i++;
		p++;
	}
	return (-1);
}

int	ft_count_len(char *s, int index, char c)
{
	int	j;

	j = 1;
	index++;
	while (s[index])
	{
		if (s[index] == c)
			return (j);
		j++;
		index++;
	}
	return (-1);
}

int	ft_tokenss(char c)
{
	if (c == ' ' || c == '\t' || c == '|' || c == '<' || c == '>')
		return (1);
	return (0);
}

int	ft_strlen_sp(char *s, int index)
{
	int	q;

	q = 0;
	index = ft_skip(s, index);
	if (ft_tokenss(s[index]) == 0)
	{
		while (s[index] && ft_tokenss(s[index]) == 0)
		{
			if (s[index] == '\'' || s[index] == '\"')
			{
				q += ft_count_len(s, index, s[index]) + 1;
				index = find_set(s, index, s[index]) + 1;
			}
			else
			{
				index++;
				q++;
			}
		}
	}
	else if (ft_herdoc(s, index) == 1)
		q = 2;
	else if (ft_tokenss(s[index]) == 1)
		q++;
	return (q);
}
