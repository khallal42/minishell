/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiple_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khallal <khallal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 15:23:23 by khallal           #+#    #+#             */
/*   Updated: 2023/03/27 23:08:29 by khallal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**split_path(char **env)
{
	int	i;

	i = 0;
	while (env[i] && !ft_strcmp_un(env[i], "PATH"))
		i++;
	if (ft_strcmp_un(env[i], "PATH"))
		return (ft_split(&env[i][5], ':'));
	else if (!env[i])
		return (NULL);
	else
		return (NULL);
}

void	ft_free1(char **k, int i)
{
	while (k[i])
	{
		free(k[i]);
		i++;
	}
	free(k);
}

void	ft_acc(char *cmd)
{
	DIR		*dir;

	dir = opendir(cmd);
	if (dir != NULL)
		(write(2, ": is a directory\n", 18), exit(126));
}

char	*ft_access(char **s_path, char *cmd)
{
	char	*k;
	int		i;

	i = 0;
	ft_acc(cmd);
	if (ft_strchr(cmd, '/') && access(cmd, X_OK) == -1)
		return (cmd);
	if (access(cmd, X_OK) == 0)
		return (cmd);
	if (!s_path)
		return (NULL);
	while (s_path[i])
	{
		k = ft_strjoin0(s_path[i], "/");
		k = ft_strjoin0(k, cmd);
		if (access(k, X_OK) == 0)
		{
			ft_free1(s_path, i + 1);
			return (k);
		}
		free(k);
		i++;
	}
	free(s_path);
	return (NULL);
}

int	ft_strcmp_un1(char *tmp, char *mv)
{
	int	i;

	i = 0;
	if (!tmp)
		return (0);
	while (tmp[i] && mv[i] && tmp[i] != '=')
	{
		if (tmp[i] != mv[i])
			return (0);
		i++;
	}
	if ((!mv[i] && tmp[i] == '='))
		return (1);
	return (0);
}
