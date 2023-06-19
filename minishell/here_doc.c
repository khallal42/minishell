/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khallal <khallal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:21:11 by khallal           #+#    #+#             */
/*   Updated: 2023/03/21 00:25:58 by khallal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "minishell.h"

int	check_heredoc(char **k, int i)
{
	if (k)
	{
		while (k[i])
		{
			if (k[i][0] == '<' && k[i][1] == '<')
				return (1);
			i++;
		}
	}
	return (0);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

void	doc(int sin)
{
	if (sin == SIGINT)
		exit(44);
}

void	here_doc1(char **env, char *lim, int fdp)
{
	char	*tmp;

	while (1)
	{
		write(1, "> ", 2);
		tmp = get_next_line(0);
		if (!tmp || ft_strcmp1(tmp, lim))
			break ;
		tmp = expand_herdoc(tmp, env);
		ft_putstr_fd(tmp, fdp);
		free(tmp);
	}
	free(tmp);
	free(lim);
}

int	here_doc(char *dat, char **env)
{
	int				fdp[2];
	int				i;
	char			*lim;
	char			*trim;
	struct termios	a2;

	i = 0;
	trim = ft_strtrim_1(dat, "<");
	pipe(fdp);
	lim = ft_strjoin(trim, "\n");
	(free(trim), tcgetattr(0, &a2));
	if (fork() == 0)
		ft_here(a2, env, lim, fdp[1]);
	else
	{
		(free(lim), waitpid(0, &i, 0), close(fdp[1]));
		if (WEXITSTATUS(i) == 44)
		{
			close(fdp[0]);
			return (1200);
		}
	}
	return (fdp[0]);
}
