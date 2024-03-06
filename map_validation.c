/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_characters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 14:18:52 by fdessoy-          #+#    #+#             */
/*   Updated: 2024/03/01 14:18:53 by fdessoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_rectangle(t_map msl)
{
	size_t	i;

	i = 0;
	while (i < msl.height)
	{
		if (ft_strlen(msl.map[i]) != msl.width)
		{
			ft_putstr_fd(ERR_MAP, 2);
			exit(1);
		}
		i++;
	}
}

void	check_character(char **map)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] != 'P' && map[i][j] != 'E' &&
			map[i][j] != 'C' && map[i][j] != '1' && map[i][j] != '0')
			{
				ft_putstr_fd(ERR_CHAR, 2);
				exit(1);
			}
			j++;
		}
		i++;
	}
}

void	check_walls(t_map msl) // check if all limit walls are 1
{
	check_upper_wall(msl);
	check_lower_wall(msl);
	check_left_wall(msl);
	check_right_wall(msl);
}

void	check_content(t_map msl)
{
	size_t	i;
	size_t	j;
	size_t	found;

	found = 0;
	i = 0;
	while (i < msl.height)
	{
		j = 0;
		while (msl.map[i][j] != '\0')
		{
			if (msl.map[i][j] == 'P')
				found += 1;
			else if (msl.map[i][j] == 'E')
				found += 1;
			j++;
		}
		i++;
	}
	if (found != 2)
	{
		ft_putstr_fd(ERR_CHAR, 2);
		exit(1);
	}
}
