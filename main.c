/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 13:44:50 by fdessoy-          #+#    #+#             */
/*   Updated: 2024/01/04 13:44:52 by fdessoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_map	map_struct;

	ft_memset(&map_struct, 0, sizeof(map_struct));
	invalid_arg(argc, argv);
	so_long(map_struct, argv);
	return (0);
}
