/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khallal <khallal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:41:41 by khallal           #+#    #+#             */
/*   Updated: 2023/03/20 14:56:44 by khallal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strncmp1(const char *s1, const char *s2, unsigned int n)
{
	unsigned int	i;
	unsigned char	*s3;
	unsigned char	*s4;

	i = 0;
	s3 = (unsigned char *)s1;
	s4 = (unsigned char *)s2;
	while (i < n && (s3[i] != '\0' || s4[i] != '\0'))
	{
		if (s3[i] != s4[i])
		{
			return (s3[i] - s4[i]);
		}
		i++;
	}
	return (0);
}

int	ft_check_echo(char *str, char *ec)
{
	int	i;

	i = 2;
	if (!str)
		return (0);
	if (ft_strncmp1(str, ec, 2))
		return (0);
	while (str[i])
	{
		if (str[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

void	echo(char **k, int debut, int fd1)
{
	int	i;
	int	j;

	i = debut;
	j = 0;
	while (k[i])
	{
		j = 0;
		while (k[i][j])
		{
			write(fd1, &k[i][j], 1);
			j++;
		}
		i++;
		if (k[i])
			write(fd1, " ", 1);
	}
}

int	ft_echo(t_data *data, int fd1)
{
	int	i;

	i = 1;
	if ((data->full_cmd[1]) != NULL)
	{
		if (ft_check_echo(data->full_cmd[1], "-n"))
		{
			i++;
			while (ft_check_echo(data->full_cmd[i], "-n"))
				i++;
			echo(data->full_cmd, i, fd1);
		}
		else
		{
			echo(data->full_cmd, i, fd1);
			write(fd1, "\n", 1);
		}
	}
	else
		write(fd1, "\n", 1);
	return (0);
}
