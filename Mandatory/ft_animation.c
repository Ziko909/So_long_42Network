/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaabou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 08:20:19 by zaabou            #+#    #+#             */
/*   Updated: 2022/04/14 08:20:22 by zaabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../Header/so_long.h"

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
	if (!data->collectible)
		ft_put_anim_img(data, 'E', data->img_e2);
	return (0);
}

int	ft_mov(int key, t_data *data)
{
	static int	move;

	if ((key == 0 || key == 13 || key == 1 || key == 2)
		&& ft_check_sides(data, key))
	{
		move++;
		ft_putnbr_fd(move, 1);
		write(1, "\n", 1);
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

int	exit_botton(t_data *data)
{
	ft_free(data);
	exit(0);
}
