/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaabou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 08:21:47 by zaabou            #+#    #+#             */
/*   Updated: 2022/04/14 08:21:50 by zaabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../Header/so_long_bonus.h"

void	ft_put_anim_img(t_data *data, char c, void *img)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->str[j])
	{
		while (data->str[j][i])
		{
			if (data->str[j][i] == c)
				mlx_put_image_to_window(data->mlx, data->windows2,
					img, i * 50, j * 50);
			i++;
		}
		i = 0;
		j++;
	}
}

int	ft_anim(t_data *data)
{
	int			sleep;
	static int	counter;

	sleep = 50;
	if (counter <= sleep)
		ft_put_anim_img(data, 'C', data->img_c1);
	else if (counter > sleep)
	{
		ft_put_anim_img(data, 'C', data->img_c2);
		if (counter == 100)
			counter = 0;
	}
	if (!data->collectible)
		ft_put_anim_img(data, 'E', data->img_e2);
	ft_tom_work(data);
	counter++;
	return (0);
}

int	ft_mov(int key, t_data *data)
{
	static int	move;
	char		*move_str;

	if ((key == 0 || key == 13 || key == 1 || key == 2)
		&& ft_check_sides(data, key))
	{
		move++;
		move_str = ft_itoa(move);
		mlx_put_image_to_window(data->mlx, data->windows2,
			data->img_score, 0, 0);
		mlx_string_put(data->mlx, data->windows2, 0, 15, 0x0FBC81C, move_str);
		free(move_str);
		mlx_put_image_to_window(data->mlx, data->windows2, data->img_s,
			data->pp * 50, data->p * 50);
		if (key == 13 || key == 1)
			data = ft_mov_u_d(key, data);
		else if (key == 0 || key == 2)
			data = ft_ft_mov_r_l(key, data);
	}
	if (key == 53)
		ft_exit(1337, data);
	return (0);
}
