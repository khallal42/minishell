/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khallal <khallal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:35:57 by khallal           #+#    #+#             */
/*   Updated: 2023/03/25 16:38:09 by khallal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strcmp_6(char *tmp, char *mv)
{
	int	i;

	i = 0;
	while (tmp[i] && mv[i] && tmp[i] != '=')
	{
		if (tmp[i] != mv[i])
			return (0);
		i++;
	}
	if ((!mv[i] && tmp[i] == '=') || (!mv[i] && !tmp[i]))
		return (1);
	return (0);
}

int	ft_unset2(t_list1 **head_ref, char *key)
{
	t_list1	*temp;
	t_list1	*first;
	t_list1	*prev;

	first = (*head_ref);
	temp = *head_ref;
	prev = *head_ref;
	if (temp != NULL && ft_strcmp_6(temp->data, key))
	{
		*head_ref = temp->next;
		free(temp->data);
		free(temp);
		return (0);
	}
	return (1);
}

int	ft_unset1(t_list1 **head_ref, char *key)
{
	t_list1	*temp;
	t_list1	*first;
	t_list1	*prev;

	first = (*head_ref);
	temp = *head_ref;
	prev = *head_ref;
	if (ft_unset2(head_ref, key) == 0)
		return (0);
	while (temp != NULL && !ft_strcmp_6(temp->data, key))
	{
		prev = temp;
		temp = temp->next;
	}
	if (temp == NULL)
		return (0);
	prev->next = temp->next;
	(*head_ref) = first;
	free(temp->data);
	free(temp);
	return (0);
}

int	ft_unset(t_list1 **head_ref, t_list1 **export, t_data *data)
{
	int	i;
	int	k;

	i = 1;
	k = 0;
	while (data->full_cmd[i])
	{
		if (!ft_strcmp_6(data->full_cmd[i], "_"))
		{
			if (!check(data->full_cmd[i]))
			{
				write(2, ": not a valid identifier\n", 26);
				k = 1;
			}
			if (check(data->full_cmd[i]))
			{
				ft_unset1(head_ref, data->full_cmd[i]);
				ft_unset1(export, data->full_cmd[i]);
			}
		}
		i++;
	}
	return (k);
}
