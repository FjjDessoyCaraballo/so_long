/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 09:51:32 by fdessoy-          #+#    #+#             */
/*   Updated: 2024/03/07 09:51:34 by fdessoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	parse_map(t_map *msl, char *fname)
{
	size_t	i;
	int		fd;
	char	**map_cpy;

	msl->height = count_lines(open(fname, O_RDONLY));
	msl->map = ft_calloc(msl->height + 1, sizeof(char *));
	if (!msl->map)
		exit(1);
	fd = open(fname, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd(MAP_FD, 2);
		exit(1);
	}
	i = 0;
	while (i < msl->height)
		msl->map[i++] = get_next_line(fd);
	remove_nl(msl);
	msl->width = ft_strlen(msl->map[0]);
	msl->collect = count_collect(msl);
	map_cpy = copy_map(msl->map, msl->height, msl->width);
	validate_map(msl, map_cpy);
	free_array(map_cpy);
	for (size_t i = 0; i < msl->height; i++) {
        printf("%s\n", msl->map[i]);
	}
	free_array(msl->map);
}

void	validate_map(t_map *msl, char **map_cpy)
{
	check_rectangle(msl);
	check_character(msl);
	check_walls(msl);
	check_content(msl);
	flood_fill(map_cpy, msl->y_ppos, msl->x_ppos);
	check_fill_exit(msl, map_cpy);
}
