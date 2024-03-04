/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:36:34 by fdessoy-          #+#    #+#             */
/*   Updated: 2024/03/04 14:36:36 by fdessoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_upper_wall(t_map msl)
{
	size_t	j;

	j = 0;
	while (msl.map[0][j])
	{
		if (msl.map[0][j] != '1')
		{
			ft_putstr_fd(ERR_WALL, 2);
			exit(1);
		}
		j++;
	}
}

void	check_lower_wall(t_map msl)
{
	size_t	j;

	j = 0;
	while (msl.map[msl.height - 1][j])
	{
		if (msl.map[msl.height - 1][j] != '1')
		{
			ft_putstr_fd(ERR_WALL, 2);
			exit(1);
		}
		j++;
	}
}

void	check_left_wall(t_map msl)
{
	size_t	i;

	i = 0;
	while (i < msl.height)
	{
		if (msl.map[i][0] != '1')
		{
			ft_putstr_fd(ERR_WALL, 2);
			exit(1);
		}
		i++;
	}
}

void	check_right_wall(t_map msl)
{
	size_t	i;

	i = 0;
	while (i < msl.height)
	{
		if (msl.map[i][msl.width - 1] != '1')
		{
			ft_putstr_fd(ERR_WALL, 2);
			exit(1);
		}
		i++;
	}
}
