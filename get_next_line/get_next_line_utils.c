/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaabou <zaabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 23:29:59 by zaabou            #+#    #+#             */
/*   Updated: 2022/04/14 06:46:35 by zaabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*ft_strjoine(char *rest, char *buffer)
{
	int		i;
	int		all_index;
	int		len;
	char	*all;

	if (!rest)
		rest = malloc(1 * sizeof(char));
	if (!rest)
		return (NULL);
	i = 0;
	all_index = 0;
	len = ft_2strlen(rest, buffer);
	all = (char *) malloc((len + 1) * sizeof(char));
	if (!all)
		return (NULL);
	while (rest[i])
		all[all_index++] = rest[i++];
	i = 0;
	while (buffer[i])
		all[all_index++] = buffer[i++];
	all[all_index] = '\0';
	free(rest);
	return (all);
}

int	ft_2strlen(char *rest, char *buffer)
{
	int	i;
	int	j;

	if (!rest && !buffer)
		return (0);
	i = 0;
	j = 0;
	while (buffer[i])
		i++;
	if (!rest)
		return (i);
	while (rest[j])
		j++;
	return (i + j);
}

char	*ft_line_(char *rest)
{
	int		i;
	char	*line;
	int		j;

	i = 0;
	j = 0;
	if (!rest)
		return (NULL);
	while (rest[i] && rest[i] != '\n')
		i++;
	line = (char *)malloc((i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	while (rest[j] && rest[j] != '\n')
	{
		line[j] = rest[j];
		j++;
	}
	if (rest[j] && rest[j] == '\n')
		line[j++] = '\n';
	line[j] = '\0';
	return (line);
}

char	*ft_next_line(char *rest)
{
	int		i;
	int		j;
	char	*next_line;

	if (!rest)
		return (NULL);
	i = 0;
	j = 0;
	while (rest[i] && rest[i] != '\n')
		i++;
	if (!rest[i])
		return (free(rest), NULL);
	i++;
	next_line = (char *) malloc(ft_2strlen(NULL, rest) - i + 1);
	if (!next_line)
		return (NULL);
	while (rest[i])
		next_line[j++] = rest[i++];
	next_line[j] = '\0';
	free(rest);
	return (next_line);
}
