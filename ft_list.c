/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khallal <khallal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 18:27:21 by hrakik            #+#    #+#             */
/*   Updated: 2023/03/19 18:52:45 by khallal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_lstdelone1(t_data *lst, void (*del)(char **))
{
	if (!lst || !del)
		return ;
	del(lst->infile);
	del(lst->outfile);
	del(lst->full_cmd);
	free(lst);
	lst = NULL;
}

t_data	*l_lstlast(t_data **lst)
{
	t_data	*tmp;

	tmp = *lst;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	return (tmp);
}

t_data	*l_lstnew(t_divide *dive)
{
	t_data	*node;

	node = malloc(sizeof(t_data));
	if (node == NULL)
		return (NULL);
	node->out_open = dive->out_open;
	node->infile = dive->infile;
	node->outfile = dive->outfile;
	node->full_cmd = dive->full_cmd;
	node->next = NULL;
	return (node);
}

void	l_lstadd_back(t_data **lst, t_data *new)
{
	t_data	*p;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	p = l_lstlast(lst);
	p->next = new;
}

int	l_lstsize(t_data *lst)
{
	int		i;
	t_data	*tmp;

	tmp = lst;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
