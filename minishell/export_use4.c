/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_use4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khallal <khallal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 16:43:57 by khallal           #+#    #+#             */
/*   Updated: 2023/03/27 22:03:24 by khallal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	export1(t_data *data, t_list1 **m, t_list1 **export, int i)
{
	char	*k;
	t_list1	*new;
	t_list1	*tmp;
	t_list1	*tmp1;
	char	*s;

	s = plus_egal(data->full_cmd[i]);
	k = ft_add(data->full_cmd[i], m);
	ft_hhh(m, export, s);
	new = ft_lstnew1(ft_strdup(k));
	tmp = (*m);
	while (tmp->next->next)
		tmp = tmp->next;
	tmp1 = tmp->next;
	new->next = tmp1;
	tmp->next = new;
	new = ft_lstnew1(ft_strdup(k));
	tmp = (*export);
	while (tmp->next->next)
		tmp = tmp->next;
	tmp1 = tmp->next;
	new->next = tmp1;
	tmp->next = new;
	free(k);
	free(s);
}

void	export2(t_data *data, t_list1 **m, t_list1 **export, int i)
{
	char	*k;
	t_list1	*tmp;
	t_list1	*tmp1;
	t_list1	*new;
	char	*plus;

	k = ft_rem_plus(data->full_cmd[i]);
	plus = plus_egal(data->full_cmd[i]);
	ft_unset1(export, plus);
	new = ft_lstnew1(ft_strdup(k));
	tmp = (*m);
	while (tmp->next->next)
		tmp = tmp->next;
	tmp1 = tmp->next;
	new->next = tmp1;
	tmp->next = new;
	new = ft_lstnew1(ft_strdup(k));
	tmp = (*export);
	while (tmp->next->next)
		tmp = tmp->next;
	tmp1 = tmp->next;
	new->next = tmp1;
	tmp->next = new;
	free(k);
	free(plus);
}

void	export3(t_data *data, t_list1 **m, t_list1 **export, int i)
{
	t_list1	*tmp;
	t_list1	*tmp1;
	t_list1	*new;
	char	*unse;

	unse = uns(data->full_cmd[i]);
	ft_unset1(m, unse);
	ft_unset1(export, unse);
	new = ft_lstnew1(ft_strdup(data->full_cmd[i]));
	tmp = (*m);
	while (tmp->next->next)
		tmp = tmp->next;
	tmp1 = tmp->next;
	new->next = tmp1;
	tmp->next = new;
	new = ft_lstnew1(ft_strdup(data->full_cmd[i]));
	tmp = (*export);
	while (tmp->next->next)
		tmp = tmp->next;
	tmp1 = tmp->next;
	new->next = tmp1;
	tmp->next = new;
	free(unse);
}

void	export4(t_data *data, t_list1 **m, t_list1 **export, int i)
{
	t_list1	*tmp;
	t_list1	*tmp1;
	t_list1	*new;
	char	*unse;

	unse = uns(data->full_cmd[i]);
	if (check_ex_(export, data->full_cmd[i]))
		ft_unset1(export, unse);
	new = ft_lstnew1(ft_strdup(data->full_cmd[i]));
	tmp = (*m);
	while (tmp->next->next)
		tmp = tmp->next;
	tmp1 = tmp->next;
	new->next = tmp1;
	tmp->next = new;
	new = ft_lstnew1(ft_strdup(data->full_cmd[i]));
	tmp = (*export);
	while (tmp->next->next)
		tmp = tmp->next;
	tmp1 = tmp->next;
	new->next = tmp1;
	tmp->next = new;
	free(unse);
}

void	export5(t_data *data, t_list1 **m, t_list1 **export, int i)
{
	t_list1	*tmp;
	t_list1	*tmp1;
	t_list1	*new;
	char	*unse;

	unse = uns(data->full_cmd[i]);
	if (!check_ex_(m, data->full_cmd[i]))
	{
		ft_unset1(export, unse);
		new = ft_lstnew1(ft_strdup(data->full_cmd[i]));
		tmp = (*export);
		while (tmp->next->next)
			tmp = tmp->next;
		tmp1 = tmp->next;
		new->next = tmp1;
		tmp->next = new;
	}
	free(unse);
}
