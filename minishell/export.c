/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khallal <khallal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 18:53:24 by khallal           #+#    #+#             */
/*   Updated: 2023/03/27 21:58:22 by khallal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	export6(t_data *data, t_list1 **m, t_list1 **export, int i)
{
	if (check_data(data, i))
	{
		if (check_ex_(m, data->full_cmd[i]))
			export3(data, m, export, i);
		else
			export4(data, m, export, i);
	}
	else if (check(data->full_cmd[i]))
		export5(data, m, export, i);
}

int	ft_export(t_data *data, t_list1 **m, t_list1 **export)
{
	int	i;
	int	ret;

	i = 1;
	ret = 0;
	while (data->full_cmd[i])
	{
		if (check_ex_add(m, data->full_cmd[i]))
		{
			if (cherch(m, data->full_cmd[i]))
				export1(data, m, export, i);
		}
		else if (!check_ex_add(m, data->full_cmd[i]) && !cherch(m,
				data->full_cmd[i]) && check_data11(data, i)
			&& check_pleg(data->full_cmd[i]))
			export2(data, m, export, i);
		export6(data, m, export, i);
		if (!check(data->full_cmd[i]) && !check11(data->full_cmd[i]))
		{
			write(2, ": not a valid identifier\n", 26);
			ret = 1;
		}
		i++;
	}
	return (ret);
}
