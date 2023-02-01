/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 19:13:21 by ael-maar          #+#    #+#             */
/*   Updated: 2023/02/01 18:10:48 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map(char	**map)
{
	if (is_map_not_rectangular(map) == 0)
		free_map_on_error(map, "The map not rectangular");
	else if (is_start_exit_duplicated(map) == 0)
		free_map_on_error(map, "The player start or exit are duplicated");
	else if (is_valid_map_components(map) == 0)
		free_map_on_error(map, "The map doesn't have valid components");
	else if (is_map_surrounded_by_walls(map) == 0)
		free_map_on_error(map, "The map is not surrounded by walls in the map");
	else if (is_valid_path(map) == 0)
		free_map_on_error(map, "The path of the map is not valid");
}
