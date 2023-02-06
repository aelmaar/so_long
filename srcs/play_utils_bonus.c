/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:57:25 by ael-maar          #+#    #+#             */
/*   Updated: 2023/02/06 16:44:25 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	calc_width_height_bonus(char **map, t_info_b *img)
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

void	count_collectibles_bonus(char **map, t_info_b *img)
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

static void	put_string_to_window(t_info_b *img)
{
	char	*message;
	char	*moves_count;

	moves_count = ft_itoa(img->count_moves);
	message = ft_strjoin("The moves: ", moves_count);
	draw_top_window(img);
	mlx_string_put(img->mlx_ptr, img->win_ptr, 60, 25, 0xFFFFFF, message);
	free(moves_count);
	free(message);
}

int	key_press_bonus(int keycode, t_info_b *img)
{
	int	prev_pos_x;
	int	prev_pos_y;

	prev_pos_x = img->player_posx;
	prev_pos_y = img->player_posy;
	move_player_bonus(keycode, img);
	if (img->collectibles == 0)
		img->path_exit = "./textures/open_door.xpm";
	if (img->map[img->player_posy][img->player_posx] == 'A')
		destroy_all_bonus(img, "Game Over, You touched the enemy");
	if (img->collectibles == 0 \
		&& img->map[img->player_posy][img->player_posx] == 'E')
		destroy_all_bonus(img, "\t\t\t\t\tYOU WIN !!\t\t\t\t\t");
	load_xpm_image_bonus(img->map[img->door_posy][img->door_posx], \
			img, img->door_posx * 60, img->door_posy * 60 + 60);
	load_xpm_image_bonus(img->map[prev_pos_y][prev_pos_x], \
			img, prev_pos_x * 60, prev_pos_y * 60 + 60);
	load_xpm_image_bonus(img->map[img->player_posy][img->player_posx], \
			img, img->player_posx * 60, img->player_posy * 60 + 60);
	put_string_to_window(img);
	return (0);
}
