/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:40:08 by ael-maar          #+#    #+#             */
/*   Updated: 2023/02/06 17:18:32 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	calc_width_height(char **map, t_inf *inf)
{
	int	row_len;
	int	col_len;

	row_len = ft_strlen(map[0]);
	col_len = 0;
	while (map[col_len] != NULL)
		col_len++;
	inf->width = row_len * 60;
	inf->height = col_len * 60;
	if (inf->width > 5120 || inf->height > 2880)
		free_map_on_error(map, "The screen resolution is bigger, performance suck");
}

void	count_collectibles(char **map, t_inf *inf)
{
	int	col;
	int	row;

	col = 0;
	inf->collectibles = 0;
	while (map[col] != NULL)
	{
		row = 0;
		while (map[col][row] != '\0')
		{
			if (map[col][row] == 'C')
				inf->collectibles++;
			row++;
		}
		col++;
	}
}

int	key_press(int keycode, t_inf *inf)
{
	int	prev_pos_x;
	int	prev_pos_y;

	prev_pos_x = inf->player_posx;
	prev_pos_y = inf->player_posy;
	move_player(keycode, inf);
	if (inf->collectibles == 0)
		inf->path_exit = "./textures/open_door.xpm";
	if (inf->collectibles == 0 \
		&& inf->map[inf->player_posy][inf->player_posx] == 'E')
		destroy_all(inf, "\t\t\t\t\tYOU WIN !!\t\t\t\t\t");
	load_xpm_image(inf->map[inf->door_posy][inf->door_posx], \
			inf, inf->door_posx * 60, inf->door_posy * 60);
	load_xpm_image(inf->map[prev_pos_y][prev_pos_x], \
			inf, prev_pos_x * 60, prev_pos_y * 60);
	load_xpm_image(inf->map[inf->player_posy][inf->player_posx], \
			inf, inf->player_posx * 60, inf->player_posy * 60);
	return (0);
}
