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

size_t	ft_strlen_mod(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
	{
		i++;
	}
	return (i);
}

void	remove_nl(t_map map_struct) // at this point, I need to take out newlines for the map
{
	size_t i;
	size_t j;

	i = 0;
	while (i < map_struct.height)
	{
		j = 0;
		while (map_struct.map[i][j] != '\0')
		{
			if (map_struct.map[i][j] == '\n')
			{
				map_struct.map[i][j] = '\0';
			}
			j++;
		}
		i++;
	}
}
