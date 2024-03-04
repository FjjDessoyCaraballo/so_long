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
1. check if is a rectangle (I have width and height in the struct); DONE
2. remove new lines - DONE 
3. check if the walls are all 1's;
4. check if the floor is all 0's;
5. check if there is at least one P
6. check if there is at least one C
7. check if there is at least one E
8. VS code terminal fucks up output, dont trust it always.
9. check if the characters are all correct;
*/

void	check_rectangle(t_map map_struct)
{
	size_t i;

	i = 0;
	while (i < map_struct.height)
	{
		if (ft_strlen(map_struct.map[i]) != map_struct.width)
		{
			ft_putstr_fd(ERR_MAP, 2);
			exit(1);
		}
		i++;
	}
}

void	check_characters(t_map map_struct)
{
	size_t i;

	i = 0;
	while (i < map_struct.height)
	{
		return ;
	}
}
/* diary of progress*/
/* 01.03.2024 
1 - My map is coming back in irregular size (not rectangular). The last 
row is coming back with -1 element different from the other rows (e.g. 6, 6, 5 for
minimap.ber. probably because ft_strlen is not counting the null at the end.) */
/* 04.03.2024 
1 - Modded ft_strlen to count until new line. Now the struct has the true
value of the width for any possible scenario. Modded strlen is in utils.c
2 - In remove_nl() I will insert a new variable in the struct that will take the
parsed map, while leaving the original map unnafected. As the name says, this
function will take out the newlines. 
3 - New map has been inserted to the struct. Now the array has just null terminated
strings in it. Next step is to check if the map is a rectangle.*/


