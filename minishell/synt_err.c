/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   synt_err.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrakik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 16:10:11 by hrakik            #+#    #+#             */
/*   Updated: 2023/03/19 16:10:12 by hrakik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_synt_first_pipe(char **a)
{
	if (a && a[0][0] == '|')
	{
		msg_err_cmd("Syntaxe_Error   :  '|'");
		g_exit_status = 258;
		return (0);
	}
	return (1);
}

int	check_herdoc_1(char *s)
{
	if (s[0] == '<' && s[1] == '<')
		return (1);
	if (s[0] == '>' && s[1] == '>')
		return (1);
	return (0);
}

int	helper_synt_err(char **a, int i)
{
	if (!a[i + 1])
		msg_err_cmd("Syntaxe_Error :  newline");
	else
		msg_err_cmd_seconde("Syntaxe_Error   :  ", a[i + 1]);
	g_exit_status = 258;
	return (0);
}

int	helper_synt_err_2(char **a, int i)
{
	if (!a[i + 1] || check_herdoc_1(a[i + 1]) == 1)
	{
		if (!a[i + 2] || if_sp_char(a[i + 2][0] == 1))
		{
			if (helper_synt_err(a, (i + 1)) == 0)
				return (0);
		}
	}
	else if (!a[i + 1] || if_sp_char(a[i + 1][0] == 1))
	{
		if (!a[i + 2] || if_sp_char(a[i + 2][0]) == 1)
		{
			if (helper_synt_err(a, i + 1) == 0)
				return (0);
		}
	}
	return (1);
}

int	check_argument(char **a)
{
	int	i;

	i = 0;
	if (check_synt_first_pipe(a) == 0)
		return (0);
	while (a && a[i])
	{
		if ((a[i][0] == '>' || a[i][0] == '<')
			&& (!a[i + 1] || if_sp_char(a[i + 1][0]) == 1))
		{
			if (helper_synt_err(a, i) == 0)
				return (0);
		}
		else if (check_herdoc_1(a[i]) == 1)
		{
			if ((!a[i + 1] || if_sp_char(a[i + 1][0]) == 1))
				if (helper_synt_err(a, i) == 0)
					return (0);
		}
		else if (if_sp_char(a[i][0]) == 1)
			if (helper_synt_err_2(a, i) == 0)
				return (0);
		i++;
	}
	return (1);
}
