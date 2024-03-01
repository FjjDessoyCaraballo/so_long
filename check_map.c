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

/* gotta start by checking format of the map, later I can check letters
1. check if is a rectangle (I have width and height in the struct);
2. check if the characters are all correct;
3. check if the walls are all 1's;
4. check if the floor is all 0's;
5. check if there is at least one P
6. check if there is at least one C
7. check if there is at least one E
8. VS code terminal fucks up output, dont trust it always.
*/

void	check_rectangle(t_map map_struct)
{
	size_t i;
	size_t tmp;

	i = 0;
	while (map_struct.map[i])
	{
		tmp = ft_strlen(map_struct.map[i]);
		printf("%zu\n", tmp);
		// if (ft_strlen(map_struct.map[i]) != map_struct.width)
		// 	exit(1);
		i++; // 
	}
}

/* 01.03.2024 - my map is coming back in irregular size (not rectangular). The last 
row is coming back with -1 element different from the other rows (e.g. 6, 6, 5 for
minimap.ber. probably because ft_strlen is not counting the null at the end.) */


