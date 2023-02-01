/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:43:14 by ael-maar          #+#    #+#             */
/*   Updated: 2023/02/01 18:11:50 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_xy_position(char **map, int *player_posy, int *player_posx)
{
	*player_posy = 0;
	while (map[*player_posy] != NULL)
	{
		*player_posx = 0;
		while (map[*player_posy][*player_posx] != '\0')
		{
			if (map[*player_posy][*player_posx] == 'P')
				return ;
			(*player_posx)++;
		}
		(*player_posy)++;
	}
}

void	free_map(char **map)
{
	int	col;

	col = 0;
	while (map[col] != NULL)
		free(map[col++]);
	free(map);
}

void	free_map_on_error(char **map, char *message)
{
	perror(message);
	free_map(map);
	exit(1);
}
