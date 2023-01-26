/* **111111******************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 19:13:21 by ael-maar          #+#    #+#             */
/*   Updated: 2023/01/26 17:35:44 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include "fcntl.h"
#include "unistd.h"
#include "stdlib.h"
#include "so_long.h"
#include "stdio.h"


void	check_map(char	**map)
{
	if (is_map_not_rectangular(map) == 0)
		perror("The map not rectangular");
	else if (is_start_exit_duplicated(map) == 0)
		perror("The player start and exit are duplicated in the map");
	else if (is_valid_map_components(map) == 0)
		perror("The map doesn't have valid components");
	else if (is_map_surrounded_by_walls(map) == 0)
		perror("The map is not surrounded by walls in the map");
	else if (is_valid_path(map) == 0)
		perror("The path of the map is not valid");
}

