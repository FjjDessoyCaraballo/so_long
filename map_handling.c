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

void	parse_map(t_map map_struct, char *fname) // NEEDS MORE EXCEPTIONS PARSING
{
	size_t	i;
	int		fd;

	map_struct.height = count_lines(open(fname, O_RDONLY)); 
	map_struct.map = ft_calloc(map_struct.height + 1, sizeof(char *));
	if (!map_struct.map)
		exit(1);
	i = 0;
	fd = open(fname, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd(MAP_FD, 2);
		exit(1);
	}
	while (i < map_struct.height)
		map_struct.map[i++] = get_next_line(fd);
	remove_nl(map_struct);
	map_struct.width = ft_strlen(map_struct.map[0]);
	validate_map(map_struct);

	i = 0;
	while (map_struct.map[i])
		ft_printf("%s", map_struct.map[i++]); // this is for testing
	free_array(map_struct.map);
}

void	validate_map(t_map map_struct)
{
	check_rectangle(map_struct);
	// check_characters(map_struct);
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



