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

size_t	count_collect(t_map	*msl)
{
	size_t	i;
	size_t	j;
	size_t	found_c;

	i = 0;
	found_c = 0;
	while (i < msl->height)
	{
		j = 0;
		while (msl->map[i][j])
		{
			if (msl->map[i][j] == 'C')
				found_c += 1;
			j++;
		}
		i++;
	}
	if (found_c <= 0)
	{
		ft_putstr_fd(ERR_CHAR, 2);
		exit(0);
	}
	return (found_c);
}
