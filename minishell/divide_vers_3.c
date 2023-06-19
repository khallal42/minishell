/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_vers_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrakik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 17:49:09 by hrakik            #+#    #+#             */
/*   Updated: 2023/03/12 17:49:10 by hrakik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**check_outfile(char **av, int b, int y)
{
	int		p;
	char	**out;
	int		red;

	p = count_inf_out(av, b, y, '>');
	out = ft_calloc(p + 1, sizeof(char *));
	p = 0;
	while (av[b] && b < y)
	{
		if (av[b][0] == '>' && av[b][1] == '>')
		{
			red = 2;
			out[p] = fill_inf_out(av[b + 1], out[p], red);
			p++;
		}
		else if (av[b][0] == '>')
		{
			red = 0;
			out[p] = fill_inf_out(av[b + 1], out[p], red);
			p++;
		}
		b++;
	}
	return (out);
}

char	**check_infile(char **av, int b, int y)
{
	int		p;
	char	**inf;
	int		red;

	p = count_inf_out(av, b, y, '<');
	inf = ft_calloc(p + 1, sizeof(char *));
	p = 0;
	while (av[b] && b < y)
	{
		if (ft_strncmp1(av[b], "<<", 2) == 0)
		{
			red = 1;
			inf[p] = fill_inf_out(av[b + 1], inf[p], red);
			p++;
		}
		else if (av[b][0] == '<')
		{
			red = 0;
			inf[p] = fill_inf_out(av[b + 1], inf[p], red);
			p++;
		}
		b++;
	}
	return (inf);
}

int	ft_cherche_new(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\'')
			i = find_set(s, i, '\'');
		else if (s[i] == '\"')
			i = find_set(s, i, '\"');
		else if (s[i] == '<' || s[i] == '>')
			return (1);
		i++;
	}
	return (0);
}
