/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mul_pipe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khallal <khallal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 23:55:23 by khallal           #+#    #+#             */
/*   Updated: 2023/03/27 22:13:56 by khallal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "minishell.h"

void	g_exit_status1(int *k)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < 1)
	{
		waitpid(k[j], &i, 0);
		j++;
	}
	if (WIFEXITED(i))
		g_exit_status = WEXITSTATUS(i);
	else if (WIFSIGNALED(i))
		g_exit_status = WTERMSIG(i) + 128;
}

void	ft_helper(t_minishell *mini, t_data *tmp, t_list1 **m, t_list1 **export)
{
	close(mini->fdp[0]);
	mini->j = 0;
	open_outfile(mini, &tmp);
	open_infile_multiple(mini, &tmp, &(mini->x));
	if (mini->fd != -1)
		dup2(mini->fd, 0);
	else
		dup2(mini->track, 0);
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

void	ft_1(t_minishell *mini, t_data **tmp, t_list1 **m, t_list1 **export)
{
	while ((*tmp)->next)
	{
		if (pipe(mini->fdp) == -1)
			(perror(""), exit(1));
		mini->i = fork();
		if (mini->i == 0)
			ft_helper(mini, (*tmp), m, export);
		else
		{
			close(mini->fdp[1]);
			close(mini->track);
			mini->track = mini->fdp[0];
			if (check_heredoc((*tmp)->infile, 0))
			{
				free(mini->x);
				mini->x = mini->x->next;
			}
			(*tmp) = (*tmp)->next;
		}
	}
}

void	ft_helper2(t_minishell *mini)
{
	close(mini->track);
	close(mini->fdp[1]);
	close(mini->fdp[0]);
	g_exit_status1(mini->exits);
	free(mini->exits);
	while (waitpid(-1, NULL, 0) != -1)
		;
}

void	mul_pipe(t_data **data, t_minishell *mini, t_list1 **m,
		t_list1 **export)
{
	t_data	*tmp;

	tmp = *data;
	mini->exits = malloc(sizeof(int) * 1);
	pipe(mini->fdp);
	mini->i = fork();
	if (mini->i == 0)
		first_command(mini, &tmp, m, export);
	else
	{
		if (check_heredoc(tmp->infile, 0))
		{
			free(mini->x);
			mini->x = mini->x->next;
		}
		tmp = tmp->next;
		close(mini->fdp[1]);
		mini->track = mini->fdp[0];
		ft_1(mini, &tmp, m, export);
		mini->i = fork();
		mini->exits[0] = mini->i;
		if (mini->i == 0)
			last_command(mini, &tmp, m, export);
	}
	ft_helper2(mini);
}
