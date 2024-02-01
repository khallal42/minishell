/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   break_helper_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrakik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 09:53:55 by hrakik            #+#    #+#             */
/*   Updated: 2023/02/25 09:53:56 by hrakik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_copy_str(char *s, int index, int len, char *b)
{
	int	h;

	h = 0;
	while (s[index] && len > h)
	{
		b[h] = s[index];
		index++;
		h++;
	}
	return (b);
}

char	*helper_fun_fill(char *s, int i, int len, char *b)
{
	int	h;

	h = 0;
	while (s[i] && len > 0)
	{
		b[h] = s[i];
		i++;
		h++;
		len--;
	}
	return (b);
}

int	ft_skip(char *s, int i)
{
	while (s[i] && (s[i] == ' ' || s[i] == '\t'))
		i++;
	return (i);
}

int	ft_herdoc(char *s, int i)
{
	if ((s[i] == '>' && s[i + 1] == '>') || (s[i] == '<' && s[i + 1] == '<'))
		return (1);
	return (-1);
}

char	**ft_fill_list(char **av, char *s, int i, int len)
{
	char	*b;
	int		bob;

	bob = 0;
	i = ft_skip(s, i);
	while (s[i])
	{
		len = ft_strlen_sp(s, i);
		b = ft_calloc(len + 1, sizeof(char));
		if (b == NULL)
			exit(1);
		i = ft_skip(s, i);
		if ((s[i] == '|' || s[i] == '>' || s[i] == '<') && len == 1)
			b = ft_copy_str(s, i, len, b);
		else if (ft_herdoc(s, i) == 1)
			b = ft_copy_str(s, i, len, b);
		else
			b = helper_fun_fill(s, i, len, b);
		i += len;
		if (b[0])
			av[bob++] = ft_strdup(b);
		free(b);
	}
	return (av);
}
