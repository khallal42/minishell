/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_export.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khallal <khallal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 21:32:09 by khallal           #+#    #+#             */
/*   Updated: 2023/03/19 21:32:10 by khallal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sort_export(t_list1 **export)
{
	t_list1	*tmp;
	t_list1	*tmp1;
	char	*swap;

	tmp = *export;
	tmp1 = *export;
	while (tmp && tmp->next)
	{
		if (ft_strcmp_1(tmp->data, tmp->next->data) > 0)
		{
			swap = tmp->data;
			tmp->data = tmp->next->data;
			tmp->next->data = swap;
			tmp = tmp1;
		}
		else
			tmp = tmp->next;
	}
}

void	print_exp_oonly1(char *k, int j, int fd1)
{
	int	i;

	i = 0;
	while (k && k[i])
	{
		if (k[i] != '=')
			ft_putchar_fd(k[i], fd1);
		else if (k[i] == '=')
		{
			ft_putstr_fd("=\"", fd1);
			j = 1;
		}
		if (k[i + 1] == '\0' && j == 1)
		{
			ft_putstr_fd("\"\n", fd1);
			j = 0;
			break ;
		}
		else if (k[i + 1] == '\0' && j == 0)
			ft_putchar_fd('\n', fd1);
		i++;
	}
}

int	print_exp_oonly(t_list1 **m, int fd1)
{
	t_list1	*tmp;
	int		j;
	char	*k;

	j = 0;
	sort_export(m);
	tmp = (*m);
	while (tmp)
	{
		ft_putstr_fd("declare -x ", fd1);
		k = tmp->data;
		print_exp_oonly1(k, j, fd1);
		tmp = tmp->next;
	}
	return (0);
}
