/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expande_helper_5.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khallal <khallal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 16:11:14 by hrakik            #+#    #+#             */
/*   Updated: 2023/03/17 18:07:25 by khallal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*split_str_vers(char *s, int index)
{
	int		j;
	int		p;
	char	*str;

	j = 0;
	p = count_var(s, (index + 1));
	if (p == 0)
		p = count_var_2(s, (index + 1));
	str = ft_calloc(p + 2, sizeof(char));
	while (j <= p && s[index])
	{
		str[j] = s[index];
		j++;
		index++;
	}
	return (str);
}

char	**split_with_dol(char *s, int nb)
{
	int		i;
	int		j;
	int		p;
	char	**str;

	i = 0;
	p = 0;
	j = 0;
	str = ft_calloc(nb + 2, sizeof(char *));
	while (nb > 0)
	{
		p = find_vare_2(s, p);
		str[j] = split_str_vers(s, p);
		p++;
		nb--;
		j++;
	}
	return (str);
}

int	check_the_env(char *s1, char *s2, int df)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (s1[i] == s2[j] && j <= df)
	{
		i++;
		j++;
	}
	if (i == df && s1[i] == '=')
		return (1);
	return (0);
}

char	*change_string(char *cmd, char *s, int count)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	j = 0;
	new = ft_calloc(ft_strlen(s) - count, sizeof(char));
	while (s[i])
	{
		if (ft_strncmp(s, cmd, count, i) == 0)
		{
			while (s[i] && count >= 0)
			{
				i++;
				count--;
			}
		}
		if (!s[i])
			break ;
		new[j] = s[i];
		i++;
		j++;
	}
	free(s);
	return (new);
}

char	*linke_str(t_expnd *exp)
{
	exp->y = 0;
	exp->m = 0;
	exp->t = 0;
	exp->all = ft_strlen(exp->cmd) + ft_strlen(exp->str) - exp->size;
	exp->iren = ft_calloc(exp->all + 1, sizeof(char));
	while (exp->all > 0)
	{
		if (exp->str[exp->m] == '$' && exp->m == exp->pos)
		{
			while (exp->cmd[exp->t])
			{
				exp->iren[exp->y] = exp->cmd[exp->t];
				exp->t++;
				exp->y++;
				exp->all--;
			}
			exp->m += exp->size + 1;
		}
		exp->iren[exp->y] = exp->str[exp->m];
		exp->y++;
		exp->m++;
		exp->all--;
	}
	free(exp->str);
	return (exp->iren);
}
