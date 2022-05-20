/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_mng.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaabou <zaabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 08:24:19 by zaabou            #+#    #+#             */
/*   Updated: 2022/04/14 09:09:23 by zaabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../Header/so_long_bonus.h"

void	ft_free(t_data *data)
{
	if (data)
	{
		if (data->enemy_p)
			free(data->enemy_p);
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

void	ft_result(int mode, t_data *data)
{
	if (!mode)
		write(1, "You Lost ❌\n", 13);
	else
		write(1, "You Win ✅\n", 13);
	ft_exit(1337, data);
}

int	ft_exit(int key, t_data *data)
{
	if (key == 53 || key == 1337)
	{
		ft_free(data);
		exit(0);
	}
	return (0);
}

int	win2(int keycode, int x, int y, t_data *data)
{
	keycode = 1;
	if ((x >= 1476 && x <= 1762) && (y >= 329 && y <= 443))
	{
		mlx_destroy_window(data->mlx, data->windows1);
		data->windows2 = mlx_new_window(data->mlx, ft_strlen(data->str[0]) * 50,
				(data->map_len + 1) * 50, "So_Long");
		mlx_hook(data->windows2, 17, 0, exit_botton, 0);
		put_in_the_screen(data);
		mlx_loop_hook(data->mlx, &ft_anim, data);
		mlx_hook(data->windows2, 2, 0, ft_mov, data);
	}
	if ((x >= 1482 && x <= 1774) && (y >= 648 && y <= 804))
	{
		mlx_put_image_to_window(data->mlx,
			data->windows1, data->img_intro, 0, 0);
		mlx_hook(data->windows1, 4, 0, win1, data);
	}
	return (0);
}

int	win1(int keycode, int x, int y, t_data *data)
{
	keycode = 4;
	if ((x >= 1475 && x <= 1800) && (y >= 275 && y <= 375))
	{
		mlx_destroy_window(data->mlx, data->windows1);
		data->windows2 = mlx_new_window(data->mlx, ft_strlen(data->str[0]) * 50,
				(data->map_len + 1) * 50, "So_Long");
		mlx_hook(data->windows2, 17, 0, exit_botton, data);
		put_in_the_screen(data);
		mlx_loop_hook(data->mlx, &ft_anim, data);
		mlx_hook(data->windows2, 2, 0, ft_mov, data);
	}
	if ((x >= 1475 && x <= 1800) && (y >= 495 && y <= 595))
	{
		mlx_put_image_to_window(data->mlx, data->windows1,
			data->img_help, 0, 0);
		mlx_hook(data->windows1, 4, 0, win2, data);
	}
	if ((x >= 1475 && x <= 1800) && (y >= 725 && y <= 825))
		ft_exit(1337, data);
	return (0);
}
