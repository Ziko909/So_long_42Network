/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_managment.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaabou <zaabou@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 00:18:23 by zaabou            #+#    #+#             */
/*   Updated: 2022/06/27 18:22:30 by zaabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../Header/so_long.h"

void	init_data(t_data **data)
{
	(*data)->str = NULL;
	(*data)->node->next = NULL;
	(*data)->node->prev = NULL;
	(*data)->node->line = NULL;
	(*data)->tmp = (*data)->node;
}

void	ft_free(t_data *data)
{
	if (data)
	{
		if (data->tmp)
		{
			data->node = data->tmp;
			while (data->node)
			{
				data->tmp = data->node->next;
				if (data->node->line)
					free(data->node->line);
				free(data->node);
				data->node = data->tmp;
			}
			if (data->str)
				free(data->str);
		}
		free(data);
	}
}
