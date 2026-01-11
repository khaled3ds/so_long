/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadas <kadas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 15:11:11 by kadas             #+#    #+#             */
/*   Updated: 2026/01/04 20:55:09 by kadas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	count_collectibles(t_sl *sl)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (sl->map[i])
	{
		j = 0;
		while (sl->map[i][j])
		{
			if (sl->map[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

static int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	tmp;

	tmp = 0;
	while ((s1[tmp] || s2[tmp]) && tmp < n)
	{
		if (s1[tmp] > s2[tmp])
			return ((unsigned char)s1[tmp] - (unsigned char)s2[tmp]);
		else if (s1[tmp] < s2[tmp])
			return ((unsigned char)s1[tmp] - (unsigned char)s2[tmp]);
		tmp++;
	}
	return (0);
}

static int	exitt(t_sl *sl)
{
	free_all(sl->map);
	mlx_destroy_window(sl->mlx_ptr, sl->mlx_window);
	mlx_destroy_display(sl->mlx_ptr);
	free(sl->mlx_ptr);
	exit(0);
}

static void	right_input(int argc, char *argv)
{
	int	len;

	if (argc != 2)
	{
		write(2, "wrong number of argumnets", 26);
		exit(1);
	}
	len = ft_strlen(argv);
	if (len < 4 || ft_strncmp(&argv[len - 4], ".ber", 4))
	{
		write(2, "doesnt include .ber", 20);
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	char	**map;
	t_sl	sl;

	right_input(argc, argv[1]);
	map = mapper(argv[1]);
	if (!map)
		return (write(2, "Error\n", 6));
	if (!isvalid(map) || !path_exists(map) || !initialize(&sl, map))
	{
		free_all(map);
		return (write(2, "Error\n", 6));
	}
	sl.map = map;
	sl.rows = number_of_rows(sl.map);
	sl.cols = number_of_columns(sl.map);
	sl.moves = 0;
	sl.fexit = 0;
	sl.collectibles = count_collectibles(&sl);
	find_player(&sl.player_x, &sl.player_y, sl.map);
	load_img(&sl);
	draw_game(&sl);
	mlx_key_hook(sl.mlx_window, click, &sl);
	mlx_hook(sl.mlx_window, 17, 0, esc_button, &sl);
	mlx_loop(sl.mlx_ptr);
	exitt(&sl);
}
