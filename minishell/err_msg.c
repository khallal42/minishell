/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_msg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrakik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 16:47:22 by hrakik            #+#    #+#             */
/*   Updated: 2023/02/05 16:47:23 by hrakik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	msg_err_cmd(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(2, &s[i], 1);
		i++;
	}
	write(2, "\n", 1);
}

void	msg_err_cmd_seconde(char *s, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		write(2, &s[i], 1);
		i++;
	}
	while (s2[j])
	{
		write(2, &s2[j], 1);
		j++;
	}
	write(2, "\n", 1);
}
