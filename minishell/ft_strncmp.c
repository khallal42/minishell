/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khallal <khallal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 11:21:00 by hrakik            #+#    #+#             */
/*   Updated: 2023/03/07 15:11:29 by khallal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n, int i)
{
	size_t	j;

	j = 0;
	while (j < n && (s1[i] || s2[j]))
	{
		if (s1[i] != s2[j])
		{
			return (((unsigned char)*(s1 + i)) - ((unsigned char)*(s2 + j)));
		}
		i++;
		j++;
	}
	return (0);
}

int	ft_strcmp_1(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
		{
			return (((unsigned char)*(s1 + i)) - ((unsigned char)*(s2 + i)));
		}
		i++;
	}
	return (0);
}
