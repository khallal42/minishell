/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_use2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khallal <khallal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 23:54:50 by khallal           #+#    #+#             */
/*   Updated: 2023/03/27 22:04:41 by khallal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check11(char *k)
{
	int	i;

	i = 0;
	if ((k[0] >= '0' && k[0] <= '9') || k[0] == '=' || k[0] == '+')
		return (0);
	while (k[i] && k[i] != '=')
	{
		if (((k[i] < 65 || k[i] > 90) && (k[i] < 97 || k[i] > 122)
				&& (k[i] < '0' || k[i] > '9') && k[i] != '_' && (k[i] == '+'
					&& k[i + 1] != '=')) || k[i] == '-')
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_data11(t_data *data, int i)
{
	if (ft_strchr(data->full_cmd[i], '='))
	{
		if (check11(data->full_cmd[i]))
		{
			return (1);
		}
	}
	return (0);
}

char	*uns(char *k)
{
	char	*l;
	int		i;

	i = 0;
	while (k[i] && k[i] != '=')
		i++;
	l = malloc(i + 1);
	i = 0;
	while (k[i] && k[i] != '=')
	{
		l[i] = k[i];
		i++;
	}
	l[i] = '\0';
	return (l);
}

char	*check_ex_add(t_list1 **m, char *str)
{
	char	*k;
	t_list1	*tmp;
	int		i;

	i = 0;
	tmp = (*m);
	while (tmp)
	{
		k = tmp->data;
		while (str[i] && k[i] && k[i] == str[i] && (str[i] != '+'
				&& str[i + 1] != '='))
			i++;
		if (str[i] == '+' && str[i + 1] == '=')
			return (k);
		tmp = tmp->next;
	}
	return (NULL);
}

int	ft_strcmp_un(char *tmp, char *mv)
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
	return (1);
}
