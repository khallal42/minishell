/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expande_helper_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrakik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:32:48 by hrakik            #+#    #+#             */
/*   Updated: 2023/03/03 15:32:49 by hrakik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_check_quots(char *s)
{
	int	i;
	int	y;
	int	x;

	i = 0;
	y = 0;
	x = 0;
	if (ft_cherche_me(s, '\'', '\"') == 0)
		return (1);
	while (s[i])
	{
		if (s[i] == '\'')
		{
			i = find_set(s, i, '\'') + 1;
			y++;
		}
		else if (s[i] == '\"')
		{
			i = find_set(s, i, '\"') + 1;
			x++;
		}
	}
	if (y >= x)
		return (0);
	return (1);
}

int	count_dollar(char *s)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (s[i])
	{
		if (s[i] == '$')
			c++;
		i++;
	}
	return (c);
}

char	*helper_env_var_2(char **k)
{
	int		i;
	char	*new;

	new = ft_calloc(1, sizeof(char));
	i = 0;
	while (k[i])
	{
		k[i] = ft_strtrim(k[i], "\"\'");
		if (ft_strcmp_1(k[i], "") != 0)
			new = ft_strjoin0(new, k[i]);
		i++;
	}
	return (new);
}

char	*env_var_2(char **k, char **env)
{
	int		i;
	int		x;
	int		c;
	char	*new;

	i = 0;
	x = 0;
	c = 0;
	while (k[i])
	{
		if (ft_cherche(k[i], '$') == 1)
		{
			c = count_dollar(k[i]);
			if (ft_check_quots(k[i]) == 1)
			{
				k[i] = expande_var(k[i], env, c, x);
				if (!k[i])
					k[i] = ft_strdup("");
			}
		}
		i++;
	}
	new = helper_env_var_2(k);
	return (new);
}
