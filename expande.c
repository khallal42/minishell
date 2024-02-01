/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expande.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khallal <khallal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:59:30 by hrakik            #+#    #+#             */
/*   Updated: 2023/03/18 18:12:03 by khallal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_not_sp_chr(char c)
{
	if (c == '\'' || c == '\"')
		return (0);
	return (1);
}

char	*hold_var_env(char *s, int i)
{
	int		j;
	int		p;
	char	*env;

	j = 0;
	p = count_var(s, (i + 1));
	if (p == 0)
		p = count_var_2(s, (i + 1));
	p++;
	env = ft_calloc(p + 1, sizeof(char));
	while (s[i] && j < p)
	{
		env[j] = s[i];
		j++;
		i++;
	}
	return (env);
}

char	*hold_sin_quots(char *s, int i, char c)
{
	int		j;
	int		l;
	char	*str;

	j = 0;
	l = 0;
	j = count_set(s, i, c) + 1;
	str = ft_calloc(j + 2, sizeof(char));
	while (s[i] && l <= j)
	{
		str[l] = s[i];
		l++;
		i++;
	}
	return (str);
}

char	*helper_exp(char *s)
{
	char	*new;
	char	**ko;
	int		x;
	int		y;
	int		j;

	j = 0;
	x = 0;
	y = 0;
	new = ft_calloc(1, sizeof(char));
	ko = split_str(s, x, y);
	while (ko[j])
	{
		ko[j] = ft_strtrim(ko[j], "\"\'");
		new = ft_strjoin0(new, ko[j]);
		j++;
	}
	ft_free(ko);
	free(s);
	return (new);
}

char	**expand_path_2(char **a, char **env)
{
	int		i;
	int		j;
	int		x;
	int		y;
	char	**ko;

	i = 0;
	x = 0;
	y = 0;
	while (a[i])
	{
		j = 0;
		if (ft_cherche(a[i], '$') == 1 && ft_cherche(a[i], '<') == 0)
		{
			ko = split_str(a[i], x, y);
			free(a[i]);
			a[i] = env_var_2(ko, env);
			ft_free(ko);
		}
		else
			a[i] = helper_exp(a[i]);
		i++;
	}
	return (a);
}
