/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mi_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khallal <khallal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:17:06 by khallal           #+#    #+#             */
/*   Updated: 2023/03/21 21:48:14 by khallal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strcmp1(char *tmp, char *mv)
{
	int	i;

	i = 0;
	while (tmp[i] || mv[i])
	{
		if (tmp[i] != mv[i])
			return (0);
		else
			i++;
	}
	return (1);
}

void	change_fdp(t_here_doc **x, int fdp)
{
	t_here_doc	*tmp;

	if (*x == NULL)
		*x = ft_lstnew0(fdp);
	else
	{
		tmp = *x;
		while (tmp->next)
			tmp = tmp->next;
		tmp->x = fdp;
	}
}

void	here_doc_open1(t_data *tmp, t_minishell *mini)
{
	mini->fd = open(tmp->infile[mini->j], O_RDONLY);
	if (mini->fd == -1)
		mini->fail_open = 1;
	mini->fd = -1;
}

int	her_norm(t_minishell *mini, int j)
{
	if (j != -2)
		ft_lstadd_back3(&(mini->x), ft_lstnew0(j));
	return (-2);
}

void	ft_hhh(t_list1 **m, t_list1 **export, char *s)
{
	ft_unset1(m, s);
	ft_unset1(export, s);
}
