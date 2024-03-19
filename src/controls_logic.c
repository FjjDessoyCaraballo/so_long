/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_logic.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 12:11:55 by fdessoy-          #+#    #+#             */
/*   Updated: 2024/03/14 12:11:56 by fdessoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_down(t_map *msl)
{
	if (msl->map[msl->y_ppos + 1][msl->x_ppos] != '1')
	{
		msl->y_ppos += 1;
		ft_printf("\e[0;32mmoves:%i\n", msl->p_move++);
		msl->img->img_p->instances->y += msl->tile_sq;
		if (msl->map[msl->y_ppos][msl->x_ppos] == 'C')
		{
			msl->map[msl->y_ppos][msl->x_ppos] = '0';
			if (mlx_image_to_window(msl->mlx, msl->img->img_0, msl->x_ppos
					* msl->tile_sq, msl->y_ppos * msl->tile_sq) < 0)
				end_game(msl, 1);
			mlx_delete_image(msl->mlx, msl->img->img_p);
			msl->img->img_p = mlx_texture_to_image(msl->mlx, msl->img->txt_p);
			if (!msl->img->img_p)
				end_game(msl, 1);
			if (!mlx_resize_image(msl->img->img_p, msl->tile_sq, msl->tile_sq))
				end_game(msl, 1);
			if (mlx_image_to_window(msl->mlx, msl->img->img_p, msl->x_ppos
					* msl->tile_sq, msl->y_ppos * msl->tile_sq) < 0)
				end_game(msl, 1);
			msl->collect--;
		}
		if (msl->map[msl->y_ppos][msl->x_ppos] == 'E' && msl->collect == 0)
			end_game(msl, 0);
	}
}

void	move_left(t_map *msl)
{
	if (msl->map[msl->y_ppos][msl->x_ppos - 1] != '1')
	{
		msl->x_ppos -= 1;
		ft_printf("\e[0;35mmoves:%i\n", msl->p_move++);
		msl->img->img_p->instances->x -= msl->tile_sq;
		if (msl->map[msl->y_ppos][msl->x_ppos] == 'C')
		{
			msl->map[msl->y_ppos][msl->x_ppos] = '0';
			if (mlx_image_to_window(msl->mlx, msl->img->img_0, msl->x_ppos
					* msl->tile_sq, msl->y_ppos * msl->tile_sq) < 0)
				end_game(msl, 1);
			mlx_delete_image(msl->mlx, msl->img->img_p);
			msl->img->img_p = mlx_texture_to_image(msl->mlx, msl->img->txt_p);
			if (!msl->img->img_p)
				end_game(msl, 1);
			if (!mlx_resize_image(msl->img->img_p, msl->tile_sq, msl->tile_sq))
				end_game(msl, 1);
			if (mlx_image_to_window(msl->mlx, msl->img->img_p, msl->x_ppos
					* msl->tile_sq, msl->y_ppos * msl->tile_sq) < 0)
				end_game(msl, 1);
			msl->collect--;
		}
		if (msl->map[msl->y_ppos][msl->x_ppos] == 'E' && msl->collect == 0)
			end_game(msl, 0);
	}
}

void	move_up(t_map *msl)
{
	if (msl->map[msl->y_ppos - 1][msl->x_ppos] != '1')
	{
		msl->y_ppos -= 1;
		ft_printf("\e[0;33mmoves:%i\n", msl->p_move++);
		msl->img->img_p->instances->y -= msl->tile_sq;
		if (msl->map[msl->y_ppos][msl->x_ppos] == 'C')
		{
			msl->map[msl->y_ppos][msl->x_ppos] = '0';
			if (mlx_image_to_window(msl->mlx, msl->img->img_0, msl->x_ppos
					* msl->tile_sq, msl->y_ppos * msl->tile_sq) < 0)
				end_game(msl, 1);
			mlx_delete_image(msl->mlx, msl->img->img_p);
			msl->img->img_p = mlx_texture_to_image(msl->mlx, msl->img->txt_p);
			if (!msl->img->img_p)
				end_game(msl, 1);
			if (!mlx_resize_image(msl->img->img_p, msl->tile_sq, msl->tile_sq))
				end_game(msl, 1);
			if (mlx_image_to_window(msl->mlx, msl->img->img_p, msl->x_ppos
					* msl->tile_sq, msl->y_ppos * msl->tile_sq) < 0)
				end_game(msl, 1);
			msl->collect--;
		}
		if (msl->map[msl->y_ppos][msl->x_ppos] == 'E' && msl->collect == 0)
			end_game(msl, 0);
	}
}

void	move_right(t_map *msl)
{
	if (msl->map[msl->y_ppos][msl->x_ppos + 1] != '1')
	{
		msl->x_ppos += 1;
		ft_printf("\e[0;30mmoves:%i\n", msl->p_move++);
		msl->img->img_p->instances->x += msl->tile_sq;
		if (msl->map[msl->y_ppos][msl->x_ppos] == 'C')
		{
			msl->map[msl->y_ppos][msl->x_ppos] = '0';
			if (mlx_image_to_window(msl->mlx, msl->img->img_0, msl->x_ppos
					* msl->tile_sq, msl->y_ppos * msl->tile_sq) < 0)
				end_game(msl, 1);
			mlx_delete_image(msl->mlx, msl->img->img_p);
			msl->img->img_p = mlx_texture_to_image(msl->mlx, msl->img->txt_p);
			if (!msl->img->img_p)
				end_game(msl, 1);
			if (!mlx_resize_image(msl->img->img_p, msl->tile_sq, msl->tile_sq))
				end_game(msl, 1);
			if (mlx_image_to_window(msl->mlx, msl->img->img_p, msl->x_ppos
					* msl->tile_sq, msl->y_ppos * msl->tile_sq) < 0)
				end_game(msl, 1);
			msl->collect--;
		}
		if (msl->map[msl->y_ppos][msl->x_ppos] == 'E' && msl->collect == 0)
			end_game(msl, 0);
	}
}
