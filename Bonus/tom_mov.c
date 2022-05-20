/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tom_mov.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaabou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 08:22:49 by zaabou            #+#    #+#             */
/*   Updated: 2022/04/14 08:22:51 by zaabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../Header/so_long_bonus.h"

void	ft_tom_mov(t_data *data, int j, int i)
{
	if (data->node->line[i] == 'T')
	{
		if (i == data->pp && j == data->p)
		{
			mlx_put_image_to_window(data->mlx, data->windows2,
				data->img_ed, i * 50, j * 50);
			ft_result(0, data);
		}
		if (data->node->line[i + 1] != '0')
			data->enemy_p[data->enemy_s] = -(i - 1);
		else if (data->node->line[i - 1] != '0')
			data->enemy_p[data->enemy_s] = 0;
		if (data->node->line[i + 1] == '0' && data->enemy_p[data->enemy_s] >= 0)
			ft_tom_mov_to_right(data, j, i);
		else if (data->node->line[i - 1] == '0'
			&& data->enemy_p[data->enemy_s] < 0)
			ft_tom_mov_to_left(data, j, i);
	}
		data->enemy_s++;
}

void	ft_tom_mov_to_right(t_data *data, int j, int i)
{
	data->node->line[i] = '0';
	mlx_put_image_to_window(data->mlx, data->windows2,
		data->img_s, i * 50, j * 50);
	mlx_put_image_to_window(data->mlx, data->windows2,
		data->img_er, (i + 1) * 50, j * 50);
	data->node->line[i + 1] = 'T';
}

void	ft_tom_mov_to_left(t_data *data, int j, int i)
{
	data->node->line[i] = '0';
	mlx_put_image_to_window(data->mlx, data->windows2,
		data->img_s, i * 50, j * 50);
	mlx_put_image_to_window(data->mlx, data->windows2,
		data->img_el, (i - 1) * 50, j * 50);
	data->node->line[i - 1] = 'T';
}
