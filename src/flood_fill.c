/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 12:09:21 by fdessoy-          #+#    #+#             */
/*   Updated: 2024/03/06 12:09:23 by fdessoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(char **map, size_t y, size_t x)
{
	if (map[y][x] == '1' || map[y][x] == 'x')
		return ;
	map[y][x] = 'x';
	flood_fill(map, y + 1, x);
	flood_fill(map, y, x + 1);
	flood_fill(map, y - 1, x);
	flood_fill(map, y, x - 1);
}

void	check_fill_exit(t_map *msl, char **map_cpy)
{
	size_t	i;
	size_t	j;
	size_t	found;

	found = 0;
	i = 0;
	while (i < msl->height)
	{
		j = 0;
		while (map_cpy[i][j] != '\0')
		{
			if (map_cpy[i][j] == 'E' || map_cpy[i][j] == 'C')
				found += 1;
			j++;
		}
		i++;
	}
	if (found != 0)
	{
		ft_putstr_fd(ERR_PATH, 2);
		free_array(msl->map);
		exit(1);
	}
}
