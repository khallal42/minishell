/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_commande.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khallal <khallal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:44:53 by khallal           #+#    #+#             */
/*   Updated: 2023/03/27 22:12:51 by khallal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	one_command1(t_data **data, t_minishell *mini)
{
	t_data	*tmp;

	tmp = *data;
	if (mini->i == 0)
	{
		signal(SIGQUIT, SIG_DFL);
		open_outfile(mini, data);
		open_infile_multiple(mini, data, &(mini->x));
		if (mini->fd != -1)
			dup2(mini->fd, 0);
		else if ((mini->x) && (mini->x)->x != -1)
			dup2(mini->x->x, 0);
		if (mini->fd1 != -1)
			dup2(mini->fd1, 1);
		if (tmp->full_cmd[0])
		{
			mini->k = split_path(mini->env);
			mini->cmd = ft_access(mini->k, tmp->full_cmd[0]);
			if (execve(mini->cmd, tmp->full_cmd, mini->env) == -1)
				(write(2, ": command not found\n", 21), exit(127));
		}
		else
			exit(0);
	}
}

void	one_command(t_data **data, t_minishell *mini, t_list1 **m,
		t_list1 **export)
{
	int		i;
	t_data	*tmp;

	i = 0;
	tmp = *data;
	if (is_builtin(tmp->full_cmd[0]))
		g_exit_status = builtin(*data, m, export, mini);
	else
	{
		mini->i = fork();
		if (mini->i == 0)
			one_command1(data, mini);
		else
		{
			waitpid(mini->i, &i, 0);
			close(mini->fd1);
			if (WIFEXITED(i))
				g_exit_status = WEXITSTATUS(i);
			else if (WIFSIGNALED(i))
				g_exit_status = WTERMSIG(i) + 128;
		}
	}
}
