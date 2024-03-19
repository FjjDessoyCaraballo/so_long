/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_allocation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 11:43:55 by fdessoy-          #+#    #+#             */
/*   Updated: 2024/03/13 11:43:56 by fdessoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_allocation_0(t_map *msl, mlx_t *mlx)
{
	msl->x = 0;
	msl->y = 0;
	msl->i = 0;
	msl->j = 0;
	while (msl->map[msl->i])
	{
		msl->j = 0;
		msl->x = 0;
		while (msl->map[msl->i][msl->j])
		{
			if (msl->map[msl->i][msl->j] == '0')
				if (mlx_image_to_window(mlx, msl->img->img_0, msl->x
						* msl->tile_sq, msl->y * msl->tile_sq) < 0)
					end_game(msl, 1);
			msl->j++;
			msl->x++;
		}
		msl->i++;
		msl->y++;
	}
}

void	map_allocation_1(t_map *msl, mlx_t *mlx)
{
	msl->x = 0;
	msl->y = 0;
	msl->i = 0;
	msl->j = 0;
	while (msl->map[msl->i])
	{
		msl->j = 0;
		msl->x = 0;
		while (msl->map[msl->i][msl->j])
		{
			if (msl->map[msl->i][msl->j] == '1')
				if (mlx_image_to_window(mlx, msl->img->img_1, msl->x
						* msl->tile_sq, msl->y * msl->tile_sq) < 0)
					end_game(msl, 1);
			msl->j++;
			msl->x++;
		}
		msl->i++;
		msl->y++;
	}
}

void	map_allocation_p(t_map *msl, mlx_t *mlx)
{
	msl->x = 0;
	msl->y = 0;
	msl->i = 0;
	msl->j = 0;
	while (msl->map[msl->i])
	{
		msl->j = 0;
		msl->x = 0;
		while (msl->map[msl->i][msl->j])
		{
			if (msl->map[msl->i][msl->j] == 'P')
			{
				if (mlx_image_to_window(mlx, msl->img->img_0, msl->x
						* msl->tile_sq, msl->y * msl->tile_sq) < 0)
					end_game(msl, 1);
				if (mlx_image_to_window(mlx, msl->img->img_p, msl->x
						* msl->tile_sq, msl->y * msl->tile_sq) < 0)
					end_game(msl, 1);
			}
			msl->j++;
			msl->x++;
		}
		msl->i++;
		msl->y++;
	}
}

void	map_allocation_c(t_map *msl, mlx_t *mlx)
{
	msl->x = 0;
	msl->y = 0;
	msl->i = 0;
	msl->j = 0;
	while (msl->map[msl->i])
	{
		msl->j = 0;
		msl->x = 0;
		while (msl->map[msl->i][msl->j])
		{
			if (msl->map[msl->i][msl->j] == 'C')
			{
				if (mlx_image_to_window(mlx, msl->img->img_0, msl->x
						* msl->tile_sq, msl->y * msl->tile_sq) < 0)
					end_game(msl, 1);
				if (mlx_image_to_window(mlx, msl->img->img_c, msl->x
						* msl->tile_sq, msl->y * msl->tile_sq) < 0)
					end_game(msl, 1);
			}
			msl->j++;
			msl->x++;
		}
		msl->i++;
		msl->y++;
	}
}

void	map_allocation_e(t_map *msl, mlx_t *mlx)
{
	msl->x = 0;
	msl->y = 0;
	msl->i = 0;
	msl->j = 0;
	while (msl->map[msl->i])
	{
		msl->j = 0;
		msl->x = 0;
		while (msl->map[msl->i][msl->j])
		{
			if (msl->map[msl->i][msl->j] == 'E')
			{
				if (mlx_image_to_window(mlx, msl->img->img_0, msl->x
						* msl->tile_sq, msl->y * msl->tile_sq) < 0)
					end_game(msl, 1);
				if (mlx_image_to_window(mlx, msl->img->img_e, msl->x
						* msl->tile_sq, msl->y * msl->tile_sq) < 0)
					end_game(msl, 1);
			}
			msl->j++;
			msl->x++;
		}
		msl->i++;
		msl->y++;
	}
}
