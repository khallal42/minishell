/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khallal <khallal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 15:41:36 by hrakik            #+#    #+#             */
/*   Updated: 2023/03/25 16:33:46 by khallal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	enable_sig(void)
{
	struct termios	a2;

	tcgetattr(0, &a2);
	a2.c_lflag |= ECHOCTL;
	a2.c_cc[VQUIT] = 28;
	tcsetattr(0, TCSANOW, &a2);
}

void	init_signals(void)
{
	signal(SIGINT, handle_global_signal);
	signal(SIGQUIT, handle_global_signal_2);
}

void	helper_main_vers_2(t_minishell *mini, t_list1 **m,
			t_list1 **export, t_data *data)
{
	int				i;

	i = 0;
	mini->env = list_tabl(m);
	divide_input_2(mini->a, &data, mini->env);
	count_heredoc(&data);
	i = here_doc_open(&data, mini);
	enable_sig();
	if (i == 0)
	{
		if (l_lstsize(data) == 1)
			one_command(&data, mini, m, export);
		if (l_lstsize(data) >= 2)
			mul_pipe(&data, mini, m, export);
	}
	else
		g_exit_status = 1;
	ft_free(mini->env);
	close_heredoc(&(mini->x));
	free(mini->x);
	ft_freema(&data);
	free(data);
}

void	init2(t_list1 **m, t_list1 **export, t_data	**data)
{
	(*m) = NULL;
	(*export) = NULL;
	(*data) = NULL;
}

int	main(int ac, char **av, char **env)
{
	t_minishell	*mini;
	t_list1		*m;
	t_data		*data;
	t_list1		*export;

	init2(&m, &export, &data);
	envcpy_helper(env, &m, &export);
	while (ac && av)
	{
		mini = malloc(sizeof(t_minishell));
		(init(mini), init_signals());
		mini->cmds_redline = handle_global_signal_1();
		if (mini->cmds_redline == NULL)
			end_of_pg();
		if (ft_check_empt(mini->cmds_redline) == 1)
		{
			add_history(mini->cmds_redline);
			mini->a = break_cmd(mini->cmds_redline);
			if (mini->a && check_argument(mini->a) == 1)
				helper_main_vers_2(mini, &m, &export, data);
			ft_free(mini->a);
		}
		(free(mini->cmds_redline), free(mini));
	}
}
