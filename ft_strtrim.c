/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khallal <khallal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 11:52:44 by hrakik            #+#    #+#             */
/*   Updated: 2023/03/06 11:54:39 by khallal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_check_end(char const *str1, char const *str2)
{
	int	j;
	int	count;
	int	len;

	j = 0;
	count = 0;
	len = ft_strlen(str1) - 1;
	while (len > 0)
	{
		j = 0;
		while (str2[j] != '\0')
		{
			if (str1[len] == str2[j])
			{
				count++;
				break ;
			}
			j++;
		}
		break ;
		len--;
	}
	return (count);
}

static int	ft_check_start(char const *str1, char const *str2)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (str1[i] != '\0')
	{
		j = 0;
		while (str2[j] != '\0')
		{
			if (str1[i] == str2[j])
			{
				count++;
				break ;
			}
			j++;
		}
		break ;
		i++;
	}
	return (count);
}

char	*ft_strtrim(char *s1, char *set)
{
	int		start;
	int		end;
	char	*all;
	int		len;
	int		i;

	i = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	start = ft_check_start(s1, set);
	end = ft_check_end(s1, set);
	len = ft_strlen(s1) - (start + end);
	if (len < 0)
		return (ft_calloc(1, 1));
	all = ft_calloc(len + 1, sizeof(char));
	if (all == 0)
		return (0);
	while (i < len)
	{
		all[i] = s1[start];
		i++;
		start++;
	}
	free(s1);
	return (all);
}
