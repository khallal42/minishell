/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_in_out_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khallal <khallal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:47:51 by khallal           #+#    #+#             */
/*   Updated: 2023/03/27 22:50:55 by khallal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	open_outfile(t_minishell *mini, t_data **data)
{
	if ((*data)->outfile != NULL)
	{
		mini->j = 0;
		while ((*data)->outfile[mini->j] != NULL && (*data)->out_open != 0)
		{
			if ((*data)->outfile[mini->j][0] == '>'
				&& (*data)->outfile[mini->j][1] == '>')
			{
				mini->fd1 = open(ft_strtrim_1((*data)->outfile[mini->j], ">>"),
						O_RDWR | O_CREAT | O_APPEND,
						0644);
			}
			else
				mini->fd1 = open((*data)->outfile[mini->j],
						O_RDWR | O_CREAT | O_TRUNC,
						0644);
			if ((*data)->outfile[mini->j][0] == '\0' && (*data)->out_open != 0)
				(write(2, "ambiguous redirect\n", 20), exit(1));
			else if (mini->fd1 < 0)
				(perror("44"), exit(1));
			mini->j++;
			(*data)->out_open--;
		}
	}
}

void	open_infile_multiple(t_minishell *mini, t_data **data, t_here_doc **x)
{
	if (mini->fail_open == 1)
		(write(2, "  : no such file or directory1\n", 32), exit(1));
	if ((*data)->infile != NULL)
	{
		mini->j = 0;
		while ((*data)->infile[mini->j])
		{
			while ((*data)->infile[mini->j]
				&& (*data)->infile[mini->j][0] == '<'
				&& (*data)->infile[mini->j][1] == '<')
			{
				mini->fd = (*x)->x;
				mini->j++;
			}
			if ((*data)->infile[mini->j])
			{
				mini->fd = open((*data)->infile[mini->j], O_RDONLY);
				if (mini->fd == -1)
					(perror(""), exit(1));
				mini->j++;
			}
		}
	}
}

int	openbu(t_data **data, t_minishell *mini)
{
	if ((*data)->infile[mini->j])
	{
		mini->fd = open((*data)->infile[mini->j], O_RDONLY);
		if (mini->fd == -1)
		{
			perror("3");
			return (1);
		}
		mini->j++;
	}
	return (0);
}

int	open_infile_builtin(t_minishell *mini, t_data **data, t_here_doc **x)
{
	if (mini->fail_open == 1)
	{
		write(2, "  : no such file or directory1\n", 32);
		return (1);
	}
	if ((*data)->infile != NULL)
	{
		mini->j = 0;
		while ((*data)->infile[mini->j])
		{
			while ((*data)->infile[mini->j]
				&& (*data)->infile[mini->j][0] == '<'
				&& (*data)->infile[mini->j][1] == '<')
			{
				mini->fd = (*x)->x;
				mini->j++;
			}
			if (openbu(data, mini) == 1)
				return (1);
		}
	}
	return (0);
}
