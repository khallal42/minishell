/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_use3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khallal <khallal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 23:54:53 by khallal           #+#    #+#             */
/*   Updated: 2023/03/20 14:57:01 by khallal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_rem_plus(char *k)
{
	int		i;
	char	*l;
	int		j;
	int		x;

	x = 0;
	i = 0;
	j = 0;
	while (k[i])
		i++;
	l = malloc(i);
	i = 0;
	while (k[i])
	{
		if (k[i] != '+' || x == 1)
		{
			l[j] = k[i];
			j++;
		}
		if (k[i] == '+')
			x = 1;
		i++;
	}
	l[j] = '\0';
	return (l);
}

char	*plus_egal(char *k)
{
	char	*l;
	int		i;

	i = 0;
	while (k[i] != '+')
		i++;
	l = malloc(i + 1);
	i = 0;
	while (k[i] != '+')
	{
		l[i] = k[i];
		i++;
	}
	l[i] = '\0';
	return (l);
}

int	check_pleg(char *k)
{
	int	i;

	i = 0;
	while (k[i + 1])
	{
		if (k[i] == '+' && k[i + 1] == '=')
			return (1);
		i++;
	}
	return (0);
}

int	check_data(t_data *data, int i)
{
	if (ft_strchr(data->full_cmd[i], '='))
	{
		if (check(data->full_cmd[i]))
			return (1);
	}
	return (0);
}
