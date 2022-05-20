/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jerry.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaabou <zaabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 02:09:19 by zaabou            #+#    #+#             */
/*   Updated: 2022/04/14 03:04:10 by zaabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../Header/so_long.h"

int	ft_check_sides(t_data *data, int key)
{
	if (ft_up_and_down(data, key))
		return (1);
	if (ft_right_and_left(data, key))
		return (1);
	return (0);
}

int	ft_up_and_down(t_data *data, int key)
{
	if (key == 13 && data->str[data->p - 1][data->pp] != '1')
	{
		if (data->collectible && data->str[data->p - 1][data->pp] == 'E')
			return (0);
		if (data ->str[data->p - 1][data->pp] == 'C')
		{
			data->str[data->p - 1][data->pp] = '0';
			data->collectible--;
		}
		return (1);
	}
	else if (key == 1 && data->str[data->p + 1][data->pp] != '1')
	{
		if (data->collectible && data->str[data->p + 1][data->pp] == 'E')
			return (0);
		if (data->str[data->p + 1][data->pp] == 'C')
		{
			data->str[data->p + 1][data->pp] = '0';
			data->collectible--;
		}
		return (1);
	}
	return (0);
}

int	ft_right_and_left(t_data *data, int key)
{
	if (key == 0 && data->str[data->p][data->pp - 1] != '1')
	{
		if (data->collectible && data->str[data->p][data->pp - 1] == 'E')
			return (0);
		if (data->str[data->p][data->pp - 1] == 'C')
		{
			data->str[data->p][data->pp - 1] = '0';
			data->collectible--;
		}
		return (1);
	}
	else if (key == 2 && data->str[data->p][data->pp + 1] != '1')
	{
		if (data->collectible && data->str[data->p][data->pp + 1] == 'E')
			return (0);
		if (data->str[data->p][data->pp + 1] == 'C')
		{
			data->str[data->p][data->pp + 1] = '0';
			data->collectible--;
		}
		return (1);
	}
	return (0);
}

t_data	*ft_ft_mov_r_l(int key, t_data *data)
{
	if (key == 0)
	{
		mlx_put_image_to_window(data->mlx, data->windows2,
			data->img_pl, (data->pp - 1) * 50, data->p * 50);
		if (!data->collectible && data->str[data->p][data->pp - 1] == 'E')
			ft_result(1337, data);
		data->pp -= 1;
	}
	else if (key == 2)
	{
		mlx_put_image_to_window(data->mlx, data->windows2, data->img_pr,
			(data->pp + 1) * 50, data->p * 50);
		if (!data->collectible && data->str[data->p][data->pp + 1] == 'E')
			ft_result(1337, data);
		data->pp += 1;
	}
	return (data);
}

t_data	*ft_mov_u_d(int key, t_data *data)
{
	if (key == 13)
	{
		mlx_put_image_to_window(data->mlx, data->windows2,
			data->img_pu, data->pp * 50, (data->p - 1) * 50);
		if (!data->collectible && data->str[data->p - 1][data->pp] == 'E')
			ft_result(1337, data);
		data->p -= 1;
	}
	else if (key == 1)
	{
		mlx_put_image_to_window(data->mlx, data->windows2,
			data->img_pd, data->pp * 50, (data->p + 1) * 50);
		if (!data->collectible && data->str[data->p + 1][data->pp] == 'E')
			ft_result(1337, data);
		data->p += 1;
	}
	return (data);
}
