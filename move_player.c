/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadas <kadas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 21:41:20 by kadas             #+#    #+#             */
/*   Updated: 2026/01/04 20:55:14 by kadas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	move_exit(t_sl *sl, int i, int j)
{
	{
		if (sl->collectibles == 0)
		{
			sl->moves++;
			ft_putnbr(sl->moves);
			write(1, "\n", 1);
			esc(sl);
		}
		else
		{
			sl->fexit = 1;
			sl->map[sl->player_y][sl->player_x] = '0';
			sl->player_x = i;
			sl->player_y = j;
			sl->map[sl->player_y][sl->player_x] = 'P';
			sl->moves++;
			ft_putnbr(sl->moves);
			write(1, "\n", 1);
			draw_game(sl);
		}
		return (0);
	}
}

static void	move_normal(t_sl *sl, int i, int j)
{
	sl->player_x = i;
	sl->player_y = j;
	sl->map[sl->player_y][sl->player_x] = 'P';
	sl->moves++;
	ft_putnbr(sl->moves);
	write(1, "\n", 1);
	draw_game(sl);
}

void	move_player(t_sl *sl, int x, int y)
{
	int	i;
	int	j;

	i = sl->player_x + x;
	j = sl->player_y + y;
	if (sl->map[j][i] == '1')
		return ;
	else if (sl->map[j][i] == 'C')
	{
		sl->collectibles--;
	}
	else if (sl->map[j][i] == 'E')
	{
		move_exit(sl, i, j);
		return ;
	}
	if (sl->fexit == 0)
		sl->map[sl->player_y][sl->player_x] = '0';
	else
	{
		sl->map[sl->player_y][sl->player_x] = 'E';
		sl->fexit = 0;
	}
	move_normal(sl, i, j);
}
