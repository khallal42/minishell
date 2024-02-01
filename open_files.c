/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khallal <khallal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 10:12:15 by hrakik            #+#    #+#             */
/*   Updated: 2023/03/01 11:25:42 by khallal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void	check_if_ambiguous(char **s, char **env)
// {
// 	int		i;
// 	char	*cmd;

// 	i = 0;
// 	while (s[i])
// 	{
// 		if (ft_cherche(s[i], '$') == 1 && ft_check_quots(s[i]))
// 		{
// 			cmd = expande_var(s[i], env, 1, 0);
// 			cmd = ft_strtrim(cmd, "\"\'");
// 			if (ft_isalpha(cmd[0]) == 1 || ft_isdigit(cmd[0]) == 1
// 				|| cmd[0] == '/')
// 				printf("%s : Is a directory \n", cmd);
// 			else if (!cmd[0])
// 				printf("ambiguous redirect \n");
// 		}
// 		i++;
// 	}
// }

int	helper_open(char **av, int b)
{
	int	fd;

	if (av[b + 1])
	{
		fd = open(av[b + 1], O_RDONLY);
		if (fd == -1 && ft_cherche(av[b + 1], '$') == 1)
			b++;
		else if (fd != -1)
		{
			b++;
			close(fd);
		}
		else if (fd == -1)
			return (-1);
	}
	return (b);
}

int	count_inf_open(char **av, int b, int y)
{
	int	i;
	int	c;

	c = 0;
	i = 0;
	while (av[b] && b < y)
	{
		if (ft_strcmp_1(av[b], "<") == 0)
		{
			if (helper_open(av, b) == -1)
				break ;
			else
				b = helper_open(av, b);
		}
		else if ((ft_strcmp_1(av[b], ">>") == 0)
			|| (ft_strcmp_1(av[b], ">") == 0))
		{
			c++;
			b += 1;
		}
		if (!av[b])
			break ;
		b++;
	}
	return (c);
}
