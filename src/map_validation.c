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

void	check_rectangle(t_map *msl)
{
	size_t	i;

	i = 0;
	while (i < msl->height)
	{
		if (ft_strlen(msl->map[i]) != msl->width)
		{
			ft_putstr_fd(ERR_MAP, 2);
			free_array(msl->map);
			exit(1);
		}
		i++;
	}
}

void	check_character(t_map *msl)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (msl->map[i])
	{
		j = 0;
		while (msl->map[i][j] != '\0')
		{
			if (msl->map[i][j] != 'P' && msl->map[i][j] != 'E' &&
			msl->map[i][j] != 'C' && msl->map[i][j] != '1' &&
			msl->map[i][j] != '0')
			{
				ft_putstr_fd(ERR_CHAR, 2);
				free_array(msl->map);
				exit(1);
			}
			j++;
		}
		i++;
	}
}

void	check_walls(t_map *msl)
{
	check_upper_wall(msl);
	check_lower_wall(msl);
	check_left_wall(msl);
	check_right_wall(msl);
}

void	check_content(t_map *msl) // need to pass a pointer
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < msl->height)
	{
		j = 0;
		while (msl->map[i][j] != '\0')
		{
			if (msl->map[i][j] == 'P')
			{
				msl->y_ppos = i;
				msl->x_ppos = j;
				msl->p_count += 1;
			}
			else if (msl->map[i][j] == 'E')
				msl->e_count += 1;
			j++;
		}
		i++;
	}
	content_found(msl);
}

void	content_found(t_map *msl)
{
	if (msl->p_count != 1 || msl->e_count != 1)
	{
		ft_putstr_fd(ERR_CHAR, 2);
		free_array(msl->map);
		exit(1);
	}
}
