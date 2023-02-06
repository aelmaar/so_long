/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 20:18:11 by ael-maar          #+#    #+#             */
/*   Updated: 2023/02/06 17:18:32 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	put_image_to_window(t_inf_b *inf, int x, int y)
{
	mlx_put_image_to_window(inf->mlx_ptr, inf->win_ptr, inf->img_ptr, x, y);
	if (inf->img_ptr == NULL)
		destroy_all_bonus(inf, "Check the path if its correct");
	else if (inf->xpm_width != 60 || inf->xpm_height != 60)
		destroy_all_bonus(inf, \
			"the xpm file not respecting the right dimensions");
	mlx_destroy_image(inf->mlx_ptr, inf->img_ptr);
	inf->img_ptr = NULL;
}

void	load_xpm_image_bonus(char icon, t_inf_b *inf, int x, int y)
{
	if (icon == 'P' || icon == 'E' || icon == 'C' || icon == 'A')
	{
		inf->img_ptr = mlx_xpm_file_to_image(inf->mlx_ptr, inf->path_bg,
				&(inf->xpm_width), &(inf->xpm_height));
		put_image_to_window(inf, x, y);
	}
	if (icon == 'P')
		inf->img_ptr = mlx_xpm_file_to_image(inf->mlx_ptr, inf->path_player,
				&(inf->xpm_width), &(inf->xpm_height));
	else if (icon == '1')
		inf->img_ptr = mlx_xpm_file_to_image(inf->mlx_ptr, inf->path_wall,
				&(inf->xpm_width), &(inf->xpm_height));
	else if (icon == 'C')
		inf->img_ptr = mlx_xpm_file_to_image(inf->mlx_ptr,
				inf->path_collectible, &(inf->xpm_width), &(inf->xpm_height));
	else if (icon == 'E')
		inf->img_ptr = mlx_xpm_file_to_image(inf->mlx_ptr, inf->path_exit,
				&(inf->xpm_width), &(inf->xpm_height));
	else if (icon == 'A')
		inf->img_ptr = mlx_xpm_file_to_image(inf->mlx_ptr, inf->path_enemy,
				&(inf->xpm_width), &(inf->xpm_height));
	else
		inf->img_ptr = mlx_xpm_file_to_image(inf->mlx_ptr, inf->path_bg,
				&(inf->xpm_width), &(inf->xpm_height));
	put_image_to_window(inf, x, y);
}

void	draw_top_window(t_inf_b *inf)
{
	int	x;

	x = 0;
	while (x < inf->width)
	{
		load_xpm_image_bonus('0', inf, x, 0);
		x += 60;
	}
}

void	draw_map_bonus(char **map, t_inf_b *inf)
{
	int	col;
	int	row;
	int	x;
	int	y;

	draw_top_window(inf);
	mlx_string_put(inf->mlx_ptr, inf->win_ptr, \
			60, 25, 0xFFFFFF, "The moves: 0");
	col = 0;
	y = 60;
	while (y < inf->height + 60)
	{
		row = 0;
		x = 0;
		while (x < inf->width)
		{
			load_xpm_image_bonus(map[col][row], inf, x, y);
			x += 60;
			row++;
		}
		y += 60;
		col++;
	}
}
