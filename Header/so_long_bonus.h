/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaabou <zaabou@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 14:09:48 by zaabou            #+#    #+#             */
/*   Updated: 2022/10/05 00:55:22 by zaabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
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
	int		enemy_s;
	int		exit;
	int		pp;
	int		p;
	int		fd;
	int		j;
	char	**str;
	t_lst	*node;
	t_lst	*swap;
	t_lst	*tmp;
	void	*img_w;
	void	*img_e1;
	void	*img_e2;
	void	*img_s;
	void	*img_intro;
	void	*img_help;
	void	*img_el;
	void	*img_er;
	void	*img_ed;
	void	*img_c1;
	void	*img_c2;
	void	*img_pl;
	void	*img_pr;
	void	*img_pu;
	void	*img_pd;
	void	*img_score;
	void	*mlx;
	void	*windows1;
	void	*windows2;
	int		*enemy_p;	
}t_data;
// convert xpm file to img
t_data	*xmp_to_img_p1(t_data *data, int width, int height);
t_data	*xmp_to_img_p2(t_data *data, int width, int height);
// jerry Management Functions
int		ft_check_sides(t_data *data, int key);
int		ft_up_and_down(t_data *data, int key);
int		ft_right_and_left(t_data *data, int key);
t_data	*ft_ft_mov_r_l(int key, t_data *data);
t_data	*ft_mov_u_d(int key, t_data *data);
// Tom Management Functions
void	ft_tom_work(t_data *data);
void	ft_tom_work_2(t_data *data);
void	ft_tom_mov(t_data *data, int j, int i);
void	ft_tom_mov_to_right(t_data *data, int j, int i);
void	ft_tom_mov_to_left(t_data *data, int j, int i);
void	ft_check_tom_table_of_pos(t_data *data);
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
