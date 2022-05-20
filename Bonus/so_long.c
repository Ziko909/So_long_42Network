/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaabou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 08:22:31 by zaabou            #+#    #+#             */
/*   Updated: 2022/04/14 09:18:11 by zaabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../Header/so_long_bonus.h"

void	image_put_to_pixel(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->windows2,
		data->img_s, data->index * 50, data->j * 50);
	if (data->str[data->j][data->index] == '1')
		mlx_put_image_to_window(data->mlx, data->windows2,
			data->img_w, data->index * 50, data->j * 50);
	else if (data->str[data->j][data->index] == 'P')
	{
		mlx_put_image_to_window(data->mlx, data->windows2,
			data->img_pd, data->index * 50, data->j * 50);
		data->p = data->j;
		data->pp = data->index;
	}
	else if (data->str[data->j][data->index] == 'C')
	{
		data->collectible++;
		mlx_put_image_to_window(data->mlx, data->windows2,
			data->img_c1, data->index * 50, data->j * 50);
	}
	else if (data->str[data->j][data->index] == 'E')
		mlx_put_image_to_window(data->mlx, data->windows2,
			data->img_e1, data->index * 50, data->j * 50);
	else if (data->str[data->j][data->index] == 'T')
		mlx_put_image_to_window(data->mlx, data->windows2,
			data->img_ed, data->index * 50, data->j * 50);
}

int	ft_check_file(char *str)
{
	int	i;

	i = 0;
	while (*str)
		str++;
	str--;
	while (i < 4)
	{
		if (i == 0 && *str != 'r')
			return (0);
		else if (i == 1 && *str != 'e')
			return (0);
		else if (i == 2 && *str != 'b')
			return (0);
		else if (i == 3 && *str != '.')
			return (0);
		i++;
		str--;
	}
	return (1);
}

void	put_in_the_screen(t_data *data)
{
	data->index = -1;
	data->j = -1;
	data->collectible = 0;
	while (data->str[++data->j])
	{
		while (data->str[data->j][++data->index])
			image_put_to_pixel(data);
		data->index = -1;
	}
	mlx_put_image_to_window(data->mlx, data->windows2,
		data->img_score, 0, 0);
}

int	main(int ac, char **av)
{
	t_data	*data;

	data = NULL;
	if (ac == 2 && ft_check_file(av[1]))
	{
		data = malloc(sizeof(t_data));
		if (!data)
			ft_exit(1337, data);
		data = read_the_map(av[1], data);
		data = check_the_map(data);
		data->mlx = mlx_init();
		data->windows1 = mlx_new_window(data->mlx, 1920, 1080, "So_Long");
		data = xmp_to_img_p1(data, 0, 0);
		mlx_put_image_to_window(data->mlx,
			data->windows1, data->img_intro, 0, 0);
		mlx_hook(data->windows1, 2, 0, ft_exit, data);
		mlx_hook(data->windows1, 17, 0, exit_botton, data);
		mlx_hook(data->windows1, 4, 0, win1, data);
		mlx_loop(data->mlx);
	}
	else
		ft_error (7, data);
}
