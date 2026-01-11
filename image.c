/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadas <kadas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 21:02:08 by kadas             #+#    #+#             */
/*   Updated: 2026/01/04 20:55:03 by kadas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_img(t_sl *sl)
{
	int	w;
	int	h;

	w = 64;
	h = 64;
	sl->img_wall = mlx_xpm_file_to_image(sl->mlx_ptr, "textures/wall.xpm", &w,
			&h);
	sl->img_floor = mlx_xpm_file_to_image(sl->mlx_ptr, "textures/floor.xpm", &w,
			&h);
	sl->img_player = mlx_xpm_file_to_image(sl->mlx_ptr, "textures/player.xpm",
			&w, &h);
	sl->img_collectible = mlx_xpm_file_to_image(sl->mlx_ptr,
			"textures/collect.xpm",
			&w, &h);
	sl->img_exit = mlx_xpm_file_to_image(sl->mlx_ptr, "textures/exit.xpm", &w,
			&h);
	if (!sl->img_wall || !sl->img_floor || !sl->img_player
		|| !sl->img_collectible || !sl->img_exit)
		esc(sl);
	sl->tile = w;
}

void	draw_game(t_sl *sl)
{
	int	x;
	int	y;

	y = -1;
	while (sl->map[++y])
	{
		x = -1;
		while (sl->map[y][++x])
		{
			mlx_put_image_to_window(sl->mlx_ptr, sl->mlx_window, sl->img_floor,
				x * sl->tile, y * sl->tile);
			if (sl->map[y][x] == '1')
				mlx_put_image_to_window(sl->mlx_ptr, sl->mlx_window,
					sl->img_wall, x * sl->tile, y * sl->tile);
			else if (sl->map[y][x] == 'P')
				mlx_put_image_to_window(sl->mlx_ptr, sl->mlx_window,
					sl->img_player, x * sl->tile, y * sl->tile);
			else if (sl->map[y][x] == 'C')
				mlx_put_image_to_window(sl->mlx_ptr, sl->mlx_window,
					sl->img_collectible, x * sl->tile, y * sl->tile);
			else if (sl->map[y][x] == 'E')
				mlx_put_image_to_window(sl->mlx_ptr, sl->mlx_window,
					sl->img_exit, x * sl->tile, y * sl->tile);
		}
	}
}
