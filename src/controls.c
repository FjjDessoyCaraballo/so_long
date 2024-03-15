/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:04:01 by fdessoy-          #+#    #+#             */
/*   Updated: 2024/03/13 14:04:03 by fdessoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_controls(t_map *msl, mlx_t *mlx)
{
	mlx_key_hook(mlx, &keyf, msl);
}

void	keyf(mlx_key_data_t keydata, void *param)
{
	t_map	*msl;

	msl = param;
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(msl->mlx);
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		move_up(msl);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		move_down(msl);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		move_right(msl);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		move_left(msl);
	ft_printf("\n\nplayer y pos: %i\nplayer x pos: %i\nplayer movement %i\n\n", msl->y_ppos, msl->x_ppos, msl->p_move);
}
