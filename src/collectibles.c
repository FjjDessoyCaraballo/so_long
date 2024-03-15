/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   content.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 09:53:46 by fdessoy-          #+#    #+#             */
/*   Updated: 2024/03/05 09:53:48 by fdessoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	count_collect(t_map	*msl)
{
	msl->i = 0;
	msl->collect = 0;
	while (msl->i < msl->height)
	{
		msl->j = 0;
		while (msl->map[msl->i][msl->j])
		{
			if (msl->map[msl->i][msl->j] == 'C')
				msl->collect += 1;
			else if (msl->map[msl->i][msl->j] == 'E')
			{
				msl->y_epos = msl->i;
				msl->x_epos = msl->j;
			}
			msl->j++;
		}
		msl->i++;
	}
	if (msl->collect <= 0)
	{
		ft_putstr_fd(ERR_CHAR, 2);
		exit(0);
	}
}
