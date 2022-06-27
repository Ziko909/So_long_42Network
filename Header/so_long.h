/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaabou <zaabou@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 14:09:48 by zaabou            #+#    #+#             */
/*   Updated: 2022/04/14 08:17:14 by zaabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <libc.h>
# include <mlx.h>
# include "../get_next_line/get_next_line.h"

typedef struct lst{
	struct lst	*prev;
	char		*line;
	struct lst	*next;
}t_lst;

typedef struct data{
	int		map_len;
	int		collectible;
	int		player;
	int		index;
	int		exit;
	int		pp;
	int		p;
	int		fd;
	int		j;
	char	**str;
	t_lst	*node;
	t_lst	*tmp;
	void	*img_w;
	void	*img_e1;
	void	*img_e2;
	void	*img_c1;
	void	*img_s;
	void	*img_intro;
	void	*img_help;
	void	*img_pl;
	void	*img_pr;
	void	*img_pu;
	void	*img_pd;
	void	*mlx;
	void	*windows1;
	void	*windows2;
}t_data;
// Convert xpm to img
t_data	*xmp_to_img(t_data *data, int width, int height);
// jerry Management Functions
int		ft_check_sides(t_data *data, int key);
int		ft_up_and_down(t_data *data, int key);
int		ft_right_and_left(t_data *data, int key);
t_data	*ft_ft_mov_r_l(int key, t_data *data);
t_data	*ft_mov_u_d(int key, t_data *data);
// Windows Management Functions
int		win1(int keycode, int x, int y, t_data *data);
int		win2(int keycode, int x, int y, t_data *data);
int		ft_mov(int key, t_data *data);
// Map Hundling Functions
t_data	*read_the_map(char	*av, t_data	*data);
t_data	*check_the_map(t_data	*data);
int		ft_check_component(char c);
// Game Screen Management
void	put_in_the_screen(t_data *data);
void	image_put_to_pixel(t_data *data);
// Animation Fonctions
int		ft_anim(t_data *data);
void	ft_put_anim_img(t_data *data, char c, void *img);
// Memory Management
void	init_data(t_data **data);
void	ft_free(t_data *data);
// Helpful Functions
int		ft_strlen(char *str);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
char	*ft_itoa(int n);
// Errors Mode
void	ft_error(int x, t_data *data);
// Win And Lose Cases
void	ft_result(int mode, t_data *data);
// Exit The Process
int		ft_exit(int key, t_data *data);
int		exit_botton(t_data *data);
#endif
