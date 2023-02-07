/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:57:25 by ael-maar          #+#    #+#             */
/*   Updated: 2023/02/06 17:18:32 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	calc_width_height_bonus(char **map, t_inf_b *inf)
{
	int	row_len;
	int	col_len;

	row_len = ft_strlen(map[0]);
	col_len = 0;
	while (map[col_len] != NULL)
		col_len++;
	inf->width = row_len * 60;
	inf->height = col_len * 60;
	if (inf->width > 5120 || (inf->height + 60) > 2880)
		free_map_on_error(map, \
			"The screen resolution is bigger, performance suck");
}

void	count_collectibles_bonus(char **map, t_inf_b *inf)
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

static void	put_string_to_window(t_inf_b *inf)
{
	char	*message;
	char	*moves_count;

	moves_count = ft_itoa(inf->count_moves);
	message = ft_strjoin("The moves: ", moves_count);
	draw_top_window(inf);
	mlx_string_put(inf->mlx_ptr, inf->win_ptr, 60, 25, 0xFFFFFF, message);
	free(moves_count);
	free(message);
}

int	key_press_bonus(int keycode, t_inf_b *inf)
{
	int	prev_pos_x;
	int	prev_pos_y;

	prev_pos_x = inf->player_posx;
	prev_pos_y = inf->player_posy;
	move_player_bonus(keycode, inf);
	if (inf->collectibles == 0)
		inf->path_exit = "./textures/open_door.xpm";
	if (inf->map[inf->player_posy][inf->player_posx] == 'A')
		destroy_all_bonus(inf, "Game Over, You touched the enemy", 1);
	if (inf->collectibles == 0 \
		&& inf->map[inf->player_posy][inf->player_posx] == 'E')
		destroy_all_bonus(inf, "\t\t\t\t\tYOU WIN !!\t\t\t\t\t", 1);
	load_xpm_image_bonus(inf->map[inf->door_posy][inf->door_posx], \
			inf, inf->door_posx * 60, inf->door_posy * 60 + 60);
	load_xpm_image_bonus(inf->map[prev_pos_y][prev_pos_x], \
			inf, prev_pos_x * 60, prev_pos_y * 60 + 60);
	load_xpm_image_bonus(inf->map[inf->player_posy][inf->player_posx], \
			inf, inf->player_posx * 60, inf->player_posy * 60 + 60);
	put_string_to_window(inf);
	return (0);
}
