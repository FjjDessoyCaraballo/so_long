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
	int fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd(MAP_FD, 2);
		exit(1);
	}
	parse_map(map_struct, fd);
}

void	parse_map(t_map map_struct, int fd)
{
	char	*temp;
	char	*map_string;
	char	*temp_ptr;

	map_string = "";
	map_struct.temp_map = NULL;
	temp = get_next_line(fd);
	while (temp != NULL)
	{
		temp_ptr = ft_strjoin(map_string, temp);
		map_string = temp_ptr;
		free(temp);
		temp = get_next_line(fd);
	}
	ft_printf("%s\n", map_string);
	free(map_string);
}
