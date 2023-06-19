/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrakik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 21:27:17 by hrakik            #+#    #+#             */
/*   Updated: 2023/03/21 21:27:19 by hrakik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	signal_ctr(int sig)
{
	printf("\n");
	(void)sig;
}

char	*handle_global_signal_1(void)
{
	struct termios	term;
	struct termios	oldterm;
	char			*line;

	(void)signal;
	tcgetattr(0, &term);
	oldterm = term;
	term.c_cc[VQUIT] = _POSIX_VDISABLE;
	term.c_lflag &= ~ECHOCTL;
	tcsetattr(0, TCSANOW, &term);
	line = readline(("minishell $> "));
	signal(SIGINT, signal_ctr);
	tcsetattr(0, TCSANOW, &oldterm);
	return (line);
}

void	handle_global_signal(int sig)
{
	(void)sig;
	write(1, "\n", 1);
	g_exit_status = 1;
	rl_replace_line("", 1);
	rl_on_new_line();
	rl_redisplay();
}

void	end_of_pg(void)
{
	printf("exit \n");
	exit(g_exit_status);
}

void	handle_global_signal_2(int sig)
{
	(void)sig;
	printf("Quit: 3\n");
}
