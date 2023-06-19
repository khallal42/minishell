/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrakik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 21:42:54 by hrakik            #+#    #+#             */
/*   Updated: 2023/03/21 21:42:56 by hrakik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free(char **k)
{
	int	i;

	i = 0;
	while (k && k[i])
	{
		free(k[i]);
		i++;
	}
	if (k)
		free(k);
}

void	ft_free_her(t_here_doc *x)
{
	while (x != NULL)
	{
		free(x);
		x = x->next;
	}
	free(x);
}

void	ft_freema(t_data **data)
{
	t_data	*tmp;

	while ((*data))
	{
		tmp = (*data);
		ft_free((*data)->full_cmd);
		ft_free((*data)->infile);
		ft_free((*data)->outfile);
		(*data) = (*data)->next;
		free(tmp);
	}
}

void	close_heredoc(t_here_doc **x)
{
	t_here_doc	*tmp;

	tmp = *x;
	while (tmp)
	{
		close(tmp->x);
		tmp = tmp->next;
	}
}

void	count_heredoc(t_data **data)
{
	int		i;
	int		count;
	t_data	*tmp;

	tmp = *data;
	count = 0;
	while (tmp)
	{
		i = 0;
		while (tmp->infile[i])
		{
			if (!ft_strncmp1(tmp->infile[i], "<<", 2))
				count++;
			i++;
		}
		tmp = tmp->next;
	}
	if (count >= 16)
		exit(2);
}
