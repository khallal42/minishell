/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khallal <khallal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:27:06 by khallal           #+#    #+#             */
/*   Updated: 2023/03/25 16:36:19 by khallal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	change_old(t_list1 **m, char *k)
{
	t_list1	*tmp;

	tmp = *m;
	while (tmp)
	{
		if (ft_strcmp_un(tmp->data, "OLDPWD"))
		{
			if (k)
				tmp->data = ft_strjoin("OLD", k);
			break ;
		}
		tmp = tmp->next;
	}
}

void	change_fenv(t_list1 **m)
{
	t_list1	*tmp;
	char	buffer[255];
	char	*k;

	tmp = *m;
	k = NULL;
	while (tmp)
	{
		if (ft_strcmp_un(tmp->data, "PWD"))
		{
			k = tmp->data;
			if (getcwd(buffer, 255) == NULL)
				perror("");
			tmp->data = ft_strjoin("PWD=", buffer);
			break ;
		}
		tmp = tmp->next;
	}
	change_old(m, k);
}

char	*old_pwd(t_list1 **m)
{
	t_list1	*tmp;

	tmp = *m;
	while (tmp)
	{
		if (!ft_strncmp1(tmp->data, "OLDPWD", 6))
			return (tmp->data + 7);
		tmp = tmp->next;
	}
	return (NULL);
}

int	ft_cd(char *newdir, t_list1 **m)
{
	int	i;

	if (newdir == NULL || ft_strcmp(newdir, "~"))
	{
		newdir = cd_home(m);
		if (newdir == NULL)
		{
			write(2, "cd: HOME not set\n", 18);
			return (1);
		}
		i = chdir(newdir);
		if (i != 0)
		{
			perror("");
			return (1);
		}
		change_fenv(m);
	}
	return (0);
}

int	ft_cd1(t_list1 **m, t_data *data)
{
	int		i;
	char	*newdir;

	newdir = data->full_cmd[1];
	if (newdir == NULL || ft_strcmp(newdir, "~"))
		return (ft_cd(newdir, m));
	if (ft_strcmp(newdir, "-") && old_pwd(m))
	{
		newdir = old_pwd(m);
		if (newdir)
			ft_putendl_fd(newdir, 1);
	}
	if (ft_strcmp(newdir, "."))
		return (0);
	i = chdir(newdir);
	if (i != 0)
	{
		perror("");
		return (1);
	}
	change_fenv(m);
	return (0);
}
