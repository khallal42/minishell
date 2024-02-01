/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mi_utils3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khallal <khallal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 00:39:17 by khallal           #+#    #+#             */
/*   Updated: 2023/03/21 00:46:00 by khallal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	here_doc_norm(t_minishell *mini)
{
	close_heredoc(&(mini->x));
	return (1);
}

int	here_doc_open(t_data **data, t_minishell *mini)
{
	t_data	*tmp;

	tmp = *data;
	while (tmp)
	{
		mini->j = 0;
		while (check_heredoc(tmp->infile, mini->j))
		{
			if (!ft_strncmp1(tmp->infile[mini->j], "<<", 2))
			{
				mini->h != -2 && close(mini->h);
				mini->h = here_doc(tmp->infile[mini->j], mini->env);
				if (mini->h == 1200)
					return (here_doc_norm(mini));
			}
			else
				here_doc_open1(tmp, mini);
			mini->j++;
		}
		mini->h = her_norm(mini, mini->h);
		tmp = tmp->next;
	}
	return (0);
}

void	first_command(t_minishell *mini, t_data **data, t_list1 **m
				, t_list1 **export)
{
	t_data	*tmp;

	tmp = *data;
	mini->j = 0;
	open_outfile(mini, &tmp);
	open_infile_multiple(mini, &tmp, &(mini->x));
	close(mini->fdp[0]);
	mini->fd != -1 && dup2(mini->fd, 0);
	if (mini->fd1 != -1)
		dup2(mini->fd1, 1);
	else
		dup2(mini->fdp[1], 1);
	if (tmp->full_cmd[0])
	{
		mini->k = split_path(mini->env);
		mini->cmd = ft_access(mini->k, tmp->full_cmd[0]);
		if (is_builtin(tmp->full_cmd[0]))
			g_exit_status = builtin(tmp, m, export, mini);
		else
		{
			if (execve(mini->cmd, tmp->full_cmd, mini->env) == -1)
				(write(2, ": command not found\n", 21), exit(127));
		}
	}
	exit(g_exit_status);
}

void	last_command(t_minishell *mini, t_data **data, t_list1 **m
			, t_list1 **export)
{
	t_data	*tmp;

	tmp = *data;
	open_outfile(mini, &tmp);
	if (mini->fd1 != -1)
		dup2(mini->fd1, 1);
	close(mini->fdp[1]);
	open_infile_multiple(mini, &tmp, &(mini->x));
	if (mini->fd != -1)
		dup2(mini->fd, 0);
	else
		dup2(mini->fdp[0], 0);
	if (tmp->full_cmd[0])
	{
		mini->k = split_path(mini->env);
		mini->cmd = ft_access(mini->k, tmp->full_cmd[0]);
		if (is_builtin(tmp->full_cmd[0]))
			g_exit_status = builtin(tmp, m, export, mini);
		else
		{
			if (execve(mini->cmd, tmp->full_cmd, mini->env) == -1)
				(write(2, ": command not found\n", 21), exit(127));
		}
	}
	exit(g_exit_status);
}

void	ft_here(struct termios a2, char **env, char *lim, int fdp)
{
	a2.c_cc[VQUIT] = _POSIX_VDISABLE;
	a2.c_lflag &= ~ECHOCTL;
	(tcsetattr(0, TCSANOW, &a2), signal(SIGINT, doc));
	(here_doc1(env, lim, fdp), exit(0));
}
