/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadas <kadas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 20:45:35 by kadas             #+#    #+#             */
/*   Updated: 2026/01/04 20:48:22 by kadas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_sl
{
	void	*mlx_ptr;
	void	*mlx_window;
	char	**map;
	int		rows;
	int		cols;
	int		player_x;
	int		player_y;
	int		collectibles;
	int		moves;
	int		tile;
	int		fexit;
	void	*img_wall;
	void	*img_floor;
	void	*img_player;
	void	*img_exit;
	void	*img_collectible;
}			t_sl;

char	*get_next_line(int fd);
void	load_img(t_sl *sl);
int		click(int key, t_sl *sl);
void	ft_putnbr(int nb);
void	esc(t_sl *sl);
int		esc_button(t_sl *sl);
void	find_player(int *x, int *y, char **map);
int		path_exists(char **map);
void	draw_game(t_sl *sl);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *s);
char	**ft_split(char const *s, char c);
char	**mapper(char *ber);
size_t	ft_strlen(const char *str);
int		number_of_rows(char **map);
int		number_of_columns(char **map);
void	free_all(char **words);
int		valid_char(char **map);
int		isvalid(char **map);
int		initialize(t_sl *sl, char **map);
void	move_player(t_sl *sl, int x, int y);

#endif