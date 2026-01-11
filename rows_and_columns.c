/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rows_and_columns.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadas <kadas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 15:26:59 by kadas             #+#    #+#             */
/*   Updated: 2026/01/04 20:55:27 by kadas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	number_of_rows(char **map)
{
	int	i;

	if (!map || !map[0])
		return (0);
	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	number_of_columns(char **map)
{
	int	i;

	if (!map || !map[0])
		return (0);
	i = 0;
	while (map[0][i])
		i++;
	return (i);
}
