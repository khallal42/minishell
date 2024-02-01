/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_helper_6.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khallal <khallal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 18:22:13 by hrakik            #+#    #+#             */
/*   Updated: 2023/03/27 22:05:37 by khallal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*hold_string(char *s, int i)
{
	int		j;
	int		p;
	char	*str;

	j = 0;
	p = i;
	while (s[i] && ft_not_sp_chr(s[i]) == 1 && ft_isascii(s[i]) == 1)
	{
		i++;
		j++;
	}
	i = 0;
	if (j > 0)
	{
		str = ft_calloc(j + 1, sizeof(char));
		while (s[p] && i < j)
		{
			str[i] = s[p];
			i++;
			p++;
		}
		return (str);
	}
	return (NULL);
}

int	ft_split_count_str(char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == '\'' || s[i] == '\"')
			i = find_set(s, i, s[i]);
		else if (s[i] == '$')
			i += helper_var_count_spt(s, i);
		else if (ft_not_sp_chr(s[i]) == 1)
		{
			while (s[i] && ft_not_sp_chr(s[i + 1]) == 1)
				i++;
		}
		count++;
		if (!s[i])
			break ;
		i++;
	}
	return (count);
}

int	helper_variable(char *s, int i)
{
	int	l;

	l = 0;
	l = count_var(s, i + 1);
	if (l == 0)
		l = count_var_2(s, i + 1);
	i = i + l + 1;
	return (i);
}

int	helper_not_sp_chr(char *s, int i)
{
	while (s[i] && ft_not_sp_chr(s[i]) == 1)
		i++;
	return (i);
}

char	**split_str(char *s, int i, int j)
{
	int		count;
	char	**all;

	count = ft_split_count_str(s);
	all = ft_calloc(count + 1, sizeof(char *));
	while (s[i])
	{
		if (s[i] == '\'' || s[i] == '\"')
		{
			all[j] = hold_sin_quots(s, i, s[i]);
			i = find_set(s, i, s[i]) + 1;
		}
		else if (s[i] == '$')
		{
			all[j] = hold_var_env(s, i);
			i = helper_variable(s, i);
		}
		else if (ft_not_sp_chr(s[i]) == 1)
		{
			all[j] = hold_string(s, i);
			i = helper_not_sp_chr(s, i);
		}
		j++;
	}
	return (all);
}
