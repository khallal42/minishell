/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_vers_4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrakik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 17:49:15 by hrakik            #+#    #+#             */
/*   Updated: 2023/03/12 17:49:16 by hrakik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_inf_out(char **av, int b, int y, char r)
{
	int	j;
	int	c;

	j = 0;
	c = 0;
	while (av[b] && b < y)
	{
		j = 0;
		while (av[b][j])
		{
			if (av[b][j] == '\'')
				j = find_set(av[b], j, '\'');
			else if (av[b][j] == '\"')
				j = find_set(av[b], j, '\"');
			else if (av[b][j] == r)
				c++;
			if (!av[b][j])
				break ;
			j++;
		}
		b++;
	}
	return (c);
}

char	*fill_inf_out_helper(char *av, char *cmd, int her, char c)
{
	int	i;
	int	len;
	int	j;

	i = 0;
	j = 0;
	len = ft_strlen(av) + 2;
	cmd = ft_calloc(len + 1, sizeof(char));
	if (her > 0)
	{
		her = 2;
		while (her > 0)
		{
			cmd[i++] = c;
			her--;
		}
	}
	while (av[j])
		cmd[i++] = av[j++];
	return (cmd);
}

char	*fill_inf_out(char *av, char *cmd, int her)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (av != NULL)
	{
		if (her == 1)
		{
			cmd = fill_inf_out_helper(av, cmd, her, '<');
		}
		else if (her == 2)
		{
			cmd = fill_inf_out_helper(av, cmd, her, '>');
		}
		else if (her == 0)
		{
			cmd = fill_inf_out_helper(av, cmd, her, ' ');
		}
	}
	return (cmd);
}

int	ft_search(char *s, char c)
{
	if (s[0] && s[0] == c)
		return (1);
	return (-1);
}
