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
/* Check list (not necessarily in order):
1. check if is a rectangle (I have width and height in the struct); DONE
2. remove new lines - DONE 
3. check if there are no invalid characters - DONE
4. check if the floor is all 0's - UNNECESSARY!
5. check if the limit walls are all 1's - DONE
6. check if there is at least one C - DONE
7. check if there is at least one E - DONE
8. check if there is at least one P - DONE
9. account for all collectibles (C) - DONE
10. create a flood fill

OBS: VS code terminal fucks up output, dont trust it always.
*/

/* journal of progress */
/*
01.03.2024 
1 - Map is coming back in irregular size (not rectangular). 
The last row is coming back with -1 element different 
from the other rows (e.g. 6, 6, 5 for minimap.ber. 
Probably because ft_strlen is not counting the null at the end.)

04.03.2024 
1 - Modded ft_strlen to count until new line. 
Now the struct has the true value of the width 
for any possible scenario. Modded strlen is in utils.c.
2 - In remove_nl() I will insert a new variable in the 
struct that will take the parsed map, while leaving the
original map unnafected. As the name says, this function 
will take out the newlines. 
3 - New map has been inserted to the struct. Now the array 
has just null terminated strings in it. Next step is to 
check if the map is a rectangle.
4 - Added check_character() that rejects maps with invalid
characters in the map.
5 - Added multiple checks for the limit walls. If any given
map is not contained by 1's, the map is rejected with its
own error message.
END OF DAY: next step is to check for at least one occurrence
of P, E, and C.

05.03.2024
1 - Added check_components to check existence of necessary
elements in the game - i.e. one player and exit, and at least
one collectible.
2 - map_validation now has check_content() that checks for
existence of ONE occurrence of exit and player.
3 - Added a collectibles.c with count_collect() to have the
number of collectibles into my msl struct for further use.
The function only allow the map to have at least ONE
collectible. 

06.03.2024
1 - 
*/