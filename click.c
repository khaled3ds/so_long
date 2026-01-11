/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   click.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadas <kadas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 21:27:12 by kadas             #+#    #+#             */
/*   Updated: 2026/01/04 20:54:37 by kadas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	esc(t_sl *sl)
{
	if (sl->map)
		free_all(sl->map);
	mlx_destroy_image(sl->mlx_ptr, sl->img_exit);
	mlx_destroy_image(sl->mlx_ptr, sl->img_floor);
	mlx_destroy_image(sl->mlx_ptr, sl->img_player);
	mlx_destroy_image(sl->mlx_ptr, sl->img_wall);
	mlx_destroy_image(sl->mlx_ptr, sl->img_collectible);
	mlx_destroy_window(sl->mlx_ptr, sl->mlx_window);
	mlx_destroy_display(sl->mlx_ptr);
	free(sl->mlx_ptr);
	exit(0);
}

int	click(int key, t_sl *sl)
{
	if (key == 65307)
		esc(sl);
	else if (key == 119 || key == 65362)
		move_player(sl, 0, -1);
	else if (key == 115 || key == 65364)
		move_player(sl, 0, 1);
	else if (key == 97 || key == 65361)
		move_player(sl, -1, 0);
	else if (key == 100 || key == 65363)
		move_player(sl, 1, 0);
	return (0);
}

int	esc_button(t_sl *sl)
{
	if (sl->map)
		free_all(sl->map);
	mlx_destroy_image(sl->mlx_ptr, sl->img_exit);
	mlx_destroy_image(sl->mlx_ptr, sl->img_floor);
	mlx_destroy_image(sl->mlx_ptr, sl->img_player);
	mlx_destroy_image(sl->mlx_ptr, sl->img_wall);
	mlx_destroy_image(sl->mlx_ptr, sl->img_collectible);
	mlx_destroy_window(sl->mlx_ptr, sl->mlx_window);
	mlx_destroy_display(sl->mlx_ptr);
	free(sl->mlx_ptr);
	exit(0);
}
