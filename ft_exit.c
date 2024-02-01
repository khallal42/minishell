/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khallal <khallal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:19:46 by khallal           #+#    #+#             */
/*   Updated: 2023/03/25 16:48:49 by khallal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_atoi_exit(char *s)
{
	long long int	res;
	int				sign;
	int				i;

	res = 0;
	i = 0;
	sign = 1;
	while (s[i] == 32 || (s[i] >= 9 && s[i] <= 13))
		i++;
	if (s[i] == 45 || s[i] == 43)
	{	
		if (s[i] == '-')
			sign *= -1;
		i++;
	}
	while (s[i] >= 48 && s[i] <= 57)
	{
		res = res * 10 + s[i] - '0';
		if (res > 922337203775807)
			return (-1);
		i++;
	}
	return (res * sign);
}

int	ft_is_digit(char *k)
{
	int	i;

	if (k[0] != '-' && k[0] != '+' && (k[0] < '0' || k[0] > '9'))
		return (0);
	i = 1;
	while (k[i])
	{
		if (k[i] < '0' || k[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	ft_exit(t_data *data)
{
	if (data->full_cmd[1] == NULL)
		exit(g_exit_status);
	if (data->full_cmd[1] && ft_is_digit(data->full_cmd[1])
		&& data->full_cmd[2] != NULL)
	{
		write(2, "exit: too many arguments\n", 26);
		return (1);
	}
	if (data->full_cmd[1] && !ft_is_digit(data->full_cmd[1]))
	{
		write(2, ": numeric argument required\n", 29);
		exit(255);
	}
	if (data->full_cmd[1] && data->full_cmd[2] == NULL
		&& ft_is_digit(data->full_cmd[1]))
	{
		g_exit_status = ft_atoi_exit(data->full_cmd[1]);
		exit(g_exit_status);
	}
	exit(0);
	return (0);
}
