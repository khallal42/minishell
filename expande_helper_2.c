/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expande_helper_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khallal <khallal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:32:55 by hrakik            #+#    #+#             */
/*   Updated: 2023/03/17 18:08:01 by khallal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_expnd	helper_initial(char *cmd, char *s, int i, int j)
{
	t_expnd	tmp;

	tmp.cmd = cmd;
	tmp.str = s;
	tmp.pos = i;
	tmp.size = j;
	return (tmp);
}

char	*helpe_exit_st(char *cmd, char *s, int i, int j)
{
	t_expnd	exp;

	cmd = ft_itoa(g_exit_status);
	exp = helper_initial(cmd, s, i, j);
	s = linke_str(&exp);
	free(cmd);
	return (s);
}

char	*helpe_fun_check(char **env, char *cmd, char *s, int i)
{
	t_expnd	exp;
	int		c;
	int		j;

	c = 0;
	j = ft_strlen(cmd) - 1;
	while (env[c])
	{
		if (check_the_env(env[c], cmd, j) == 1)
		{
			cmd = env[c];
			cmd = skip_var(cmd);
			exp = helper_initial(cmd, s, i, j);
			s = linke_str(&exp);
			break ;
		}
		c++;
	}
	if (!env[c])
		s = change_string(cmd, s, j);
	else
		free(cmd);
	return (s);
}

char	*expande_var(char *s, char **env, int nb, int i)
{
	int		j;
	int		e;
	char	**cmd;

	cmd = split_with_dol(s, nb);
	e = 0;
	while (nb > 0)
	{
		i = find_vare_2(s, i);
		j = ft_strlen(cmd[e]) - 1;
		if (ft_strncmp(cmd[e], "?", 1, 1) == 0 && ft_cherche(cmd[e], '$') == 1)
			s = helpe_exit_st(cmd[e], s, i, j);
		else
		{
			if (j > 0)
				s = helpe_fun_check(env, cmd[e], s, i);
			else
				i++;
		}
		nb--;
		e++;
	}
	ft_free(cmd);
	return (s);
}
