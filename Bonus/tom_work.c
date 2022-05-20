/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tom_work.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaabou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 08:23:20 by zaabou            #+#    #+#             */
/*   Updated: 2022/04/14 08:23:24 by zaabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../Header/so_long_bonus.h"

void	ft_tom_work(t_data *data)
{
	int			sleep;
	static int	counter;

	ft_check_tom_table_of_pos(data);
	data->node = data->tmp;
	sleep = 15;
	data->enemy_s = 0;
	if (counter == sleep)
		ft_tom_work_2(data);
	if (counter >= sleep)
		counter = 0;
	counter++;
}

void	ft_tom_work_2(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (data->node->line != NULL)
	{
		while (data->node->line[++i])
		{
			if (data->node->line[i] == 'T')
			{
				ft_tom_mov(data, j, i);
				i++;
			}
		}
		i = -1;
		j++;
		data->node = data->node->next;
	}
}

void	ft_check_tom_table_of_pos(t_data *data)
{
	if (!data->enemy_p)
	{
		data->enemy_p = (int *) malloc (data->enemy_s * sizeof (int));
		if (!data->enemy_p)
		{
			write(2, "Problem In Memory Allocation\n", 30);
			ft_exit(1337, data);
		}
	}
}
