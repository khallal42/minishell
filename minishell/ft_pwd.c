/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khallal <khallal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:20:40 by khallal           #+#    #+#             */
/*   Updated: 2023/03/19 20:02:00 by khallal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pwd(int fd1)
{
	char	buffer[255];

	if (getcwd(buffer, 255) == NULL)
	{
		perror("");
		return (1);
	}
	ft_putendl_fd(buffer, fd1);
	return (0);
}
