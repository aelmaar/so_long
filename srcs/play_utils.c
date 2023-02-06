/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:40:08 by ael-maar          #+#    #+#             */
/*   Updated: 2023/02/06 15:59:32 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	calc_width_height(char **map, t_info *img)
{
	int	row_len;
	int	col_len;

	row_len = ft_strlen(map[0]);
	col_len = 0;
	while (map[col_len] != NULL)
		col_len++;
	img->width = row_len * 60;
	img->height = col_len * 60;
}

void	count_collectibles(char **map, t_info *img)
{
	int	col;
	int	row;

	col = 0;
	img->collectibles = 0;
	while (map[col] != NULL)
	{
		row = 0;
		while (map[col][row] != '\0')
		{
			if (map[col][row] == 'C')
				img->collectibles++;
			row++;
		}
		col++;
	}
}

int	key_press(int keycode, t_info *img)
{
	int	prev_pos_x;
	int	prev_pos_y;

	prev_pos_x = img->player_posx;
	prev_pos_y = img->player_posy;
	move_player(keycode, img);
	if (img->collectibles == 0)
		img->path_exit = "./textures/open_door.xpm";
	if (img->collectibles == 0 \
		&& img->map[img->player_posy][img->player_posx] == 'E')
		destroy_all(img, "\t\t\t\t\tYOU WIN !!\t\t\t\t\t");
	load_xpm_image(img->map[img->door_posy][img->door_posx], \
			img, img->door_posx * 60, img->door_posy * 60);
	load_xpm_image(img->map[prev_pos_y][prev_pos_x], \
			img, prev_pos_x * 60, prev_pos_y * 60);
	load_xpm_image(img->map[img->player_posy][img->player_posx], \
			img, img->player_posx * 60, img->player_posy * 60);
	return (0);
}
