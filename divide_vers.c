/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_vers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khallal <khallal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:28:25 by hrakik            #+#    #+#             */
/*   Updated: 2023/03/18 18:10:59 by khallal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	create_node(t_data **data, t_divide *div)
{
	l_lstadd_back(data, l_lstnew(div));
}

char	*fill_cmd(char *s)
{
	int		j;
	int		len;
	char	*cmd;

	j = 0;
	len = ft_strlen(s);
	cmd = ft_calloc(len + 1, sizeof(char));
	while (s[j] && j < len)
	{
		cmd[j] = s[j];
		j++;
	}
	return (cmd);
}

int	count_cmd(char **av, int b, int y)
{
	int	j;
	int	c;

	c = 0;
	j = 0;
	while (av[b] && b < y)
	{
		if (ft_cherche_new(av[b]) == 0)
		{
			c++;
			b++;
		}
		else
			b += 2;
	}
	return (c);
}

char	**check_cmd(char **av, int b, int y)
{
	int		p;
	int		len;
	char	**cmd;

	p = 0;
	len = count_cmd(av, b, y);
	cmd = ft_calloc(len + 1, sizeof(char *));
	while (av[b] && b < y)
	{
		if (ft_cherche_new(av[b]) == 1)
			b += 2;
		else
		{
			cmd[p] = fill_cmd(av[b]);
			p++;
			b++;
		}
	}
	return (cmd);
}

void	divide_input_2(char **av, t_data **data, char **env)
{
	int			i;
	int			y;
	int			b;
	t_divide	div;

	y = 0;
	b = 0;
	i = count_pipe(av);
	while (i > 0)
	{
		div.out_open = 0;
		b = y;
		y = find_first_node(av, b);
		div.out_open = count_inf_open(av, b, y);
		div.infile = check_infile(av, b, y);
		div.infile = expand_path_2(div.infile, env);
		div.outfile = check_outfile(av, b, y);
		div.outfile = expand_path_2(div.outfile, env);
		div.full_cmd = check_cmd(av, b, y);
		div.full_cmd = expand_path_2(div.full_cmd, env);
		create_node(data, &div);
		y++;
		i--;
	}
}
