/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaabou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 08:23:45 by zaabou            #+#    #+#             */
/*   Updated: 2022/04/14 08:23:47 by zaabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../Header/so_long_bonus.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n >= 0 && n <= 9)
	{
		ft_putchar_fd(n + 48, fd);
	}
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(n % 10 + 48, fd);
	}
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
	}
	if (n < 0 && n > -2147483648)
	{
		n *= -1;
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(n, fd);
	}
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (s)
	{
		i = 0;
		while (s[i])
		{
			write(fd, &s[i++], 1);
		}
	}
}

int	ft_check_component(char c)
{
	return (c == '1' || c == 'T' || c == '0'
		|| c == 'P' || c == 'E' || c == 'C');
}
