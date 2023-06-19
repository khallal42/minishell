/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_vers_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khallal <khallal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 17:49:03 by hrakik            #+#    #+#             */
/*   Updated: 2023/03/17 16:35:10 by khallal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_if_ambiguous(char **s, char **env)
{
	int		i;
	int		x;
	char	*cmd;

	i = 0;
	x = 0;
	while (s[i])
	{
		if (ft_cherche(s[i], '$') == 1 && ft_check_quots(s[i]))
		{
			cmd = expande_var(s[i], env, 1, x);
			cmd = ft_strtrim(cmd, "\"\'");
			if (ft_isalpha(cmd[0]) == 1 || ft_isdigit(cmd[0]) == 1
				|| cmd[0] == '/')
				printf("%s : Is a directory \n", cmd);
			else if (!cmd[0])
				printf("ambiguous redirect \n");
		}
		i++;
	}
}

int	helper_count_pipe(char **av, int i, int j)
{
	if (av[i][j] == '\'')
		j = find_set(av[i], j, '\'');
	else if (av[i][j] == '\"')
		j = find_set(av[i], j, '\"');
	return (j);
}

int	count_pipe(char **av)
{
	int	i;
	int	c;
	int	j;

	c = 0;
	i = 0;
	while (av && av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] == '\'' || av[i][j] == '\"')
				j = helper_count_pipe(av, i, j);
			if (av[i][j] == '|' && c == 0)
				c += 2;
			else if (av[i][j] == '|' && c >= 1)
				c++;
			j++;
		}
		i++;
	}
	if (c == 0)
		c = 1;
	return (c);
}

int	find_first_node(char **av, int b)
{
	int	j;

	j = 0;
	while (av[b])
	{
		j = 0;
		while (av[b][j])
		{
			if (av[b][j] == '\'' || av[b][j] == '\"')
			{
				if (av[b][j] == '\'')
					j = find_set(av[b], j, '\'');
				else if (av[b][j] == '\"')
					j = find_set(av[b], j, '\"');
			}
			if (av[b][j] == '|')
				return (b);
			if (!av[b][j])
				break ;
			j++;
		}
		b++;
	}
	return (b);
}

int	check_if_in_out(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\'')
			i = find_set(s, i, '\'') + 1;
		if (s[i] == '\"')
			i = find_set(s, i, '\"') + 1;
		if (s[i] == '>' || s[i] == '<')
			return (0);
		if (!s[i])
			break ;
		i++;
	}
	return (1);
}
