/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadas <kadas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 15:12:28 by kadas             #+#    #+#             */
/*   Updated: 2026/01/04 20:55:33 by kadas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	isrectangle(char **map)
{
	int	i;
	int	j;

	if (!map || !map[0])
		return (0);
	i = 0;
	j = 1;
	while (map[j])
	{
		if (ft_strlen(map[i]) != ft_strlen(map[j]))
			return (0);
		j++;
	}
	return (1);
}

static int	walls(char **map)
{
	int	i;
	int	j;
	int	rows;
	int	cols;

	i = 0;
	rows = number_of_rows(map);
	cols = number_of_columns(map);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (i == 0 || i == rows - 1 || j == 0 || j == cols - 1)
				if (map[i][j] != '1')
					return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	player_and_exit(char **map)
{
	int	i;
	int	j;
	int	players;
	int	exits;

	i = 0;
	players = 0;
	exits = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				players++;
			else if (map[i][j] == 'E')
				exits++;
			j++;
		}
		i++;
	}
	if (players == 1 && exits == 1)
		return (1);
	return (0);
}

static int	collect(char **map)
{
	int	i;
	int	j;
	int	collectible;

	i = 0;
	collectible = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				collectible++;
			j++;
		}
		i++;
	}
	if (collectible != 0)
		return (1);
	return (0);
}

int	isvalid(char **map)
{
	if (!isrectangle(map) || !walls(map))
		return (0);
	if (!player_and_exit(map) || !collect(map) || !valid_char(map))
		return (0);
	return (1);
}
