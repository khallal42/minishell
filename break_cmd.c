/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   break_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khallal <khallal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:57:09 by hrakik            #+#    #+#             */
/*   Updated: 2023/03/10 15:30:49 by khallal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_tokens(char c)
{
	if (c == '<' || c == '>' || c == '|' || c == '\'' || c == '\"')
		return (1);
	return (0);
}

int	find_set(char *s, int i, char c)
{
	i++;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	helper_fun_quots(char *s, int i)
{
	if (s[i] == '\'')
	{
		i = find_set(s, i, '\'');
		if (i == -1)
		{
			msg_err_cmd("syntaxe Error Single_Quots");
			g_exit_status = 258;
			return (-1);
		}
	}
	else if (s[i] == '\"')
	{
		i = find_set(s, i, '\"');
		if (i == -1)
		{
			msg_err_cmd("syntaxe Error Double_Quots");
			g_exit_status = 258;
			return (-1);
		}
	}
	return (i);
}

int	count_word(char *s, int i)
{
	int	sp;

	i = 0;
	sp = 0;
	i = ft_skip(s, i);
	while (s[i])
	{
		if (s[i] == '\'' || s[i] == '\"')
			i = helper_fun_quots(s, i);
		if (i == -1)
			return (0);
		else if (ft_herdoc(s, i) == 0)
			return (0);
		else if (ft_herdoc(s, i) == 1)
		{
			sp++;
			i++;
		}
		else if (ft_tokens(s[i]) == 1)
			sp++;
		i++;
		sp++;
	}
	return (sp);
}

char	**break_cmd(char *s)
{
	int		nword;
	char	**av;
	int		h;
	int		i;
	int		len;

	h = 0;
	i = 0;
	len = 0;
	nword = count_word(s, i);
	if (nword == 0)
		return (NULL);
	av = ft_calloc((nword + 1), sizeof(char *));
	if (av == NULL)
		exit(1);
	av = ft_fill_list(av, s, h, len);
	return (av);
}
