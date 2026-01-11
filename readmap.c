/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadas <kadas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 14:31:44 by kadas             #+#    #+#             */
/*   Updated: 2026/01/04 20:55:21 by kadas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*map_reader(char *all, int fd)
{
	char	*line;
	char	*tmp;

	line = get_next_line(fd);
	if (!line)
	{
		free(all);
		return (NULL);
	}
	while (line)
	{
		tmp = all;
		all = ft_strjoin(tmp, line);
		free(line);
		if (!all)
			return (NULL);
		line = get_next_line(fd);
	}
	free(line);
	return (all);
}

char	**mapper(char *ber)
{
	int		fd;
	char	**map;
	char	*all;

	fd = open(ber, O_RDONLY);
	if (fd < 0)
		return (NULL);
	all = ft_strdup("");
	if (!all)
		return (NULL);
	all = map_reader(all, fd);
	close(fd);
	if (!all)
		return (NULL);
	map = ft_split(all, '\n');
	free(all);
	if (!map)
		return (NULL);
	return (map);
}
