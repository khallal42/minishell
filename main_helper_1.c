/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_helper_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrakik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 21:41:38 by hrakik            #+#    #+#             */
/*   Updated: 2023/03/21 21:41:39 by hrakik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_last(t_here_doc **her)
{
	t_here_doc	*tmp;

	if (*her == NULL)
		return (-1);
	tmp = *her;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp->x);
}

int	ft_check_empt(char *s)
{
	int	i;

	i = 0;
	if (s && s[i] != '\0' && s[i] != '\n')
		return (1);
	g_exit_status = 0;
	return (0);
}

void	init(t_minishell *mini)
{
	mini->a = NULL;
	mini->fd = -1;
	mini->fd1 = -1;
	mini->h = -2;
	mini->j = 0;
	mini->her = 1;
	mini->fail_open = 0;
	mini->q = 0;
	mini->track = 0;
	mini->k = NULL;
	mini->cmd = NULL;
	mini->x = NULL;
	mini->cmds_redline = NULL;
}

void	envcpy_helper(char **env, t_list1 **m, t_list1 **export)
{
	envcpy(env, m);
	envcpy(env, export);
}
