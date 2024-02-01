/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_use1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khallal <khallal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 23:54:45 by khallal           #+#    #+#             */
/*   Updated: 2023/03/20 14:51:04 by khallal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*check_ex_(t_list1 **m, char *str)
{
	char	*k;
	t_list1	*tmp;
	int		i;

	i = 0;
	tmp = (*m);
	while (tmp)
	{
		k = tmp->data;
		while (str[i] && k[i] && k[i] == str[i] && str[i] != '=')
		{
			if (str[i] == '+' && str[i + 1] == '=')
			{
				break ;
			}
			i++;
		}
		if (str[i] == '=' || (str[i] == '+' && str[i + 1] == '=') || !str[i])
			return (k);
		tmp = tmp->next;
	}
	return (NULL);
}

int	ft_strcmp_ex(char *tmp, char *mv)
{
	int	i;

	i = 0;
	while (tmp[i] && mv[i] && mv[i] != '+')
	{
		if (tmp[i] != mv[i])
			return (0);
		i++;
	}
	return (1);
}

char	*cherch(t_list1 **m, char *str)
{
	t_list1	*tmp;
	int		i;

	i = 0;
	tmp = *m;
	while (tmp)
	{
		if (ft_strcmp_ex(tmp->data, str))
			return (tmp->data);
		tmp = tmp->next;
	}
	return (NULL);
}

char	*ft_add(char *add, t_list1 **m)
{
	int		i;
	char	*leak;

	leak = cherch(m, add);
	i = 0;
	while (add[i] != '=')
		i++;
	i++;
	return (ft_strjoin(leak, &add[i]));
}

int	check(char *k)
{
	int	i;

	i = 0;
	if ((k[0] >= '0' && k[0] <= '9') || k[0] == '=')
		return (0);
	while (k[i] && k[i] != '=')
	{
		if ((k[i] < 65 || k[i] > 90) && (k[i] < 97 || k[i] > 122) && (k[i] < '0'
				|| k[i] > '9') && k[i] != '_')
		{
			return (0);
		}
		i++;
	}
	return (1);
}
