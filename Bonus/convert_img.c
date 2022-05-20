/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaabou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 07:57:35 by zaabou            #+#    #+#             */
/*   Updated: 2022/04/14 08:04:56 by zaabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../Header/so_long_bonus.h"

t_data	*xmp_to_img_p1(t_data *data, int width, int height)
{
	data->img_pl = mlx_xpm_file_to_image(data->mlx,
			"img/win2/imgP/left.xpm", &width, &height);
	data->img_pr = mlx_xpm_file_to_image(data->mlx,
			"img/win2/imgP/r.xpm", &width, &height);
	data->img_pu = mlx_xpm_file_to_image(data->mlx,
			"img/win2/imgP/up.xpm", &width, &height);
	data->img_pd = mlx_xpm_file_to_image(data->mlx,
			"img/win2/imgP/down.xpm", &width, &height);
	data->img_el = mlx_xpm_file_to_image(data->mlx,
			"img/win2/imgE/Left.xpm", &width, &height);
	data->img_er = mlx_xpm_file_to_image(data->mlx,
			"img/win2/imgE/Right.xpm", &width, &height);
	data->img_ed = mlx_xpm_file_to_image(data->mlx,
			"img/win2/imgE/Down.xpm", &width, &height);
	data = xmp_to_img_p2(data, 0, 0);
	return (data);
}

t_data	*xmp_to_img_p2(t_data *data, int width, int height)
{
	data->img_w = mlx_xpm_file_to_image(data->mlx,
			"img/win2/Wall.xpm", &width, &height);
	data->img_e1 = mlx_xpm_file_to_image(data->mlx,
			"img/win2/door/exit1.xpm", &width, &height);
	data->img_e2 = mlx_xpm_file_to_image(data->mlx,
			"img/win2/door/exit2.xpm", &width, &height);
	data->img_s = mlx_xpm_file_to_image(data->mlx,
			"img/win2/Space.xpm", &width, &height);
	data->img_intro = mlx_xpm_file_to_image(data->mlx,
			"img/win1/Intro.xpm", &width, &height);
	data->img_help = mlx_xpm_file_to_image(data->mlx,
			"img/win1/Help.xpm", &width, &height);
	data->img_c1 = mlx_xpm_file_to_image(data->mlx,
			"img/win2/img_C1.xpm", &width, &height);
	data->img_c2 = mlx_xpm_file_to_image(data->mlx,
			"img/win2/img_C2.xpm", &width, &height);
	data->img_score = mlx_xpm_file_to_image(data->mlx,
			"img/win2/score_border.xpm", &width, &height);
	return (data);
}
