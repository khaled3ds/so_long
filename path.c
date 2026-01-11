/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadas <kadas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 15:52:44 by kadas             #+#    #+#             */
/*   Updated: 2026/01/06 13:26:51 by kadas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**copy(char **map)
{
	char	**new_map;
	int		i;

	i = 0;
	new_map = malloc(sizeof(char *) * (number_of_rows(map) + 1));
	if (!new_map)
		return (NULL);
	while (map[i])
	{
		new_map[i] = ft_strdup(map[i]);
		if (!new_map[i])
		{
			free_all(new_map);
			return (NULL);
		}
		i++;
	}
	new_map[i] = NULL;
	return (new_map);
}

void	find_player(int *x, int *y, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				*y = i;
				*x = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

static void	flood_fill(char **map, int x, int y)
{
	if (x < 0 || y < 0 || !map[y] || !map[y][x])
		return ;
	if (map[y][x] == '1' || map[y][x] == '2')
		return ;
	map[y][x] = '2';
	flood_fill(map, x, y - 1);
	flood_fill(map, x, y + 1);
	flood_fill(map, x - 1, y);
	flood_fill(map, x + 1, y);
}

static int	collectable_exit(char **map)
{
	int	i;
	int	j;
	int	exits;
	int	collects;

	i = 0;
	collects = 0;
	exits = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				collects++;
			else if (map[i][j] == 'E')
				exits++;
			j++;
		}
		i++;
	}
	return (collects == 0 && exits == 0);
}

int	path_exists(char **map)
{
	char	**new_map;
	int		x;
	int		y;

	new_map = copy(map);
	if (!new_map)
		return (0);
	find_player(&x, &y, new_map);
	flood_fill(new_map, x, y);
	if (collectable_exit(new_map))
	{
		free_all(new_map);
		return (1);
	}
	free_all(new_map);
	return (0);
}
