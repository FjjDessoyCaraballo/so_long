/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 12:09:45 by fdessoy-          #+#    #+#             */
/*   Updated: 2024/02/28 12:09:47 by fdessoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	parse_map(t_map msl, char *fname) // NEEDS MORE EXCEPTIONS PARSING
{
	size_t	i;
	int		fd;

	msl.height = count_lines(open(fname, O_RDONLY));
	msl.map = ft_calloc(msl.height + 1, sizeof(char *));
	if (!msl.map)
		exit(1);
	i = 0;
	fd = open(fname, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd(MAP_FD, 2);
		exit(1);
	}
	while (i < msl.height)
		msl.map[i++] = get_next_line(fd);
	remove_nl(msl);
	msl.width = ft_strlen(msl.map[0]);
	validate_map(msl);
	msl.collect = count_collect(msl);
}
	// ft_printf("\nThese infos show if map is validated\n");
	// ft_printf("height: %i\n", msl.height);
	// ft_printf("width: %i\n", msl.width);
	// ft_printf("collectibles: %i\n", msl.collect);


void	validate_map(t_map msl)
{
	check_rectangle(msl);
	check_character(msl.map);
	check_walls(msl);
	check_content(msl);
}
