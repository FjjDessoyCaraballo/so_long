/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 10:38:19 by fdessoy-          #+#    #+#             */
/*   Updated: 2024/03/04 10:38:21 by fdessoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	remove_nl(t_map *msl)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < msl->height)
	{
		j = 0;
		while (msl->map[i][j] != '\0')
		{
			if (msl->map[i][j] == '\n')
				msl->map[i][j] = '\0';
			j++;
		}
		i++;
	}
}

size_t	count_lines(int fd)
{
	size_t	i;
	char	*line;

	if (fd < 0)
		return (0);
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		i++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (i);
}

char	**copy_map(char **map, size_t row)
{
	char	**map_cpy;
	size_t	i;

	i = 0;
	map_cpy = malloc(sizeof(char *) * (row + 1));
	if (!map_cpy)
		exit_all(map, map_cpy);
	while (i < row)
	{
		map_cpy[i] = ft_strdup(map[i]);
		if (!map_cpy[i])
			exit_all(map, map_cpy);
		i++;
	}
	map_cpy[i] = 0;
	return (map_cpy);
}

void	exit_all(char **map1, char **map2)
{
	free_array(map1);
	free_array(map2);
	exit(1);
}
