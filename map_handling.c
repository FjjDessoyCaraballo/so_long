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

void	take_map(t_map map_struct, char **argv)
{
	parse_map(map_struct, argv[1]);
}

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
		exit(1);
	while (i < map_struct.height)
		map_struct.map[i++] = get_next_line(fd);

	// i = 0;
	// while (map_struct.map[i])
	// 	ft_printf("%s", map_struct.map[i++]); // this is just for checking the map
	// free_array(map_struct.map);
}

size_t	count_lines(int fd)
{
	size_t	i;
	char	*line;

	if (fd < 0)
		return (0);
	i = 0;
	line = get_next_line(fd);
	if (!check_characters(line))
		return (0);
	while (line)
	{
		i++;
		
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (i);
}

int	check_characters(char *line)
{
	while (*line)
	{
		if (*line != '0' && *line != '1' && *line != 'P'
			&& *line != 'E' && *line != 'C')
			return (0);
		line++;
	}
	return (1);
}
