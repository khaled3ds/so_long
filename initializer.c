/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadas <kadas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 20:36:35 by kadas             #+#    #+#             */
/*   Updated: 2026/01/04 20:55:05 by kadas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	initialize(t_sl *sl, char **map)
{
	int	width;
	int	height;

	width = number_of_columns(map) * 64;
	height = number_of_rows(map) * 64;
	sl->mlx_ptr = mlx_init();
	if (!sl->mlx_ptr)
		return (0);
	sl->mlx_window = mlx_new_window(sl->mlx_ptr, width, height, "so_long");
	if (!sl->mlx_window)
	{
		mlx_destroy_display(sl->mlx_ptr);
		free(sl->mlx_ptr);
		return (0);
	}
	return (1);
}
