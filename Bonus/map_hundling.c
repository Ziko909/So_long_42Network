/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_hundling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaabou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 08:22:17 by zaabou            #+#    #+#             */
/*   Updated: 2022/04/14 09:17:55 by zaabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../Header/so_long_bonus.h"

t_data	*ft_fill(t_data *data)
{
	data->map_len = (data->j - 1);
	data->node->next = 0;
	data->str = malloc ((data->j + 1) * sizeof(char *));
	if (!data->str)
	{
		write(2, "Problem In Memory Allocation\n", 30);
		ft_exit(1337, data);
	}
	while (data->node)
	{
		data->str[data->j] = data->node->line;
		if (data->node->line && !data->node->next->line
			&& data->node->line[ft_strlen(data->node->line) - 1] == '\n')
			ft_error(8, data);
		if (data->node->line && data->j != data->map_len)
			data->str[data->j][ft_strlen(data->str[data->j]) - 1] = 0;
		data->tmp = data->node;
		data->node = data->node->prev;
		data->j--;
	}
	return (data);
}

void	ft_error(int x, t_data *data)
{
	if (x == 0)
		ft_putstr_fd("ERROR\nThe Map Must Be Rectangular \n", 2);
	else if (x == 1)
		ft_putstr_fd("ERROR\nThe Map Must Contain Only 6 Component \n", 2);
	else if (x == 3)
		ft_putstr_fd("ERROR\nThe Map Must Be Closed \n", 2);
	else if (x == 4)
		ft_putstr_fd("ERROR\nPlease Enter One Player In The Map \n", 2);
	else if (x == 5)
		ft_putstr_fd("ERROR\nThe Map Must Contain at least One E And One C\n", 2);
	else if (x == 6)
		ft_putstr_fd("ERROR\nPlease Enter A valid File\n", 2);
	else if (x == 7)
		ft_putstr_fd("ERROR\nThe Extension Of File Must Be .ber\n", 2);
	else if (x == 8)
		ft_putstr_fd("ERROR\nExtra A New Line At  The End Of The File\n", 2);
	ft_exit(1337, data);
}

t_data	*read_the_map(char	*av, t_data	*data)
{
	data->node = malloc (sizeof(t_lst));
	if (!data->node)
		ft_exit(1337, data);
	data->node->prev = NULL;
	data->tmp = data->node;
	data->fd = open(av, O_RDONLY, 00777);
	if (data->fd < 0)
		ft_error(6, data);
	data->j = 0;
	data->node->line = get_next_line(data->fd);
	while (data->node->line)
	{
		data->node->next = malloc(sizeof(t_lst));
		if (!data->node->next)
			ft_exit(1337, data);
		data->tmp = data->node;
		data->node = data->node->next;
		data->node->prev = data->tmp;
		data->j++;
		data->node->line = get_next_line(data->fd);
	}
	data = ft_fill(data);
	return (data);
}

t_data	*ft_check_validity(t_data *data, char c)
{
	if (!data->j)
	{
		data->player = 0;
		data->collectible = 0;
		data->exit = 0;
		data->enemy_s = 0;
	}
	if (c == 'P')
		data->player++;
	else if (c == 'C')
		data->collectible++;
	else if (c == 'T')
		data->enemy_s++;
	else if (c == 'E')
		data->exit++;
	return (data);
}

t_data	*check_the_map(t_data *data)
{
	data->index = -1;
	while (data->str[++data->j])
	{
		if (data->j && (ft_strlen(data->str[data->j])
				!= ft_strlen(data->str[data->j - 1])))
			ft_error(0, data);
		while (data->str[data->j][++data->index])
		{
			data = ft_check_validity(data, data->str[data->j][data->index]);
			if (!ft_check_component(data->str[data->j][data->index]))
				ft_error(1, data);
			if ((!data->j || data->j == data->map_len)
				&& data->str[data->j][data->index] != '1')
				ft_error(3, data);
			else if (data->str[data->j][0] != '1' || data->str[data->j]
					[ft_strlen(data->str[data->j]) - 1] != '1')
				ft_error(3, data);
		}
		data->index = -1;
	}
	if (data->player != 1)
		ft_error (4, data);
	if (!data->collectible || !data->exit)
		ft_error (5, data);
	return (data);
}
