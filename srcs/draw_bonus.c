/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 20:18:11 by ael-maar          #+#    #+#             */
/*   Updated: 2023/02/06 16:37:19 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	put_image_to_window(t_info_b *img, int x, int y)
{
	mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, img->img_ptr, x, y);
	if (img->img_ptr == NULL)
		destroy_all_bonus(img, "Check the path if its correct");
	else if (img->xpm_width != 60 || img->xpm_height != 60)
		destroy_all_bonus(img, \
			"the xpm file not respecting the right dimensions");
	mlx_destroy_image(img->mlx_ptr, img->img_ptr);
	img->img_ptr = NULL;
}

void	load_xpm_image_bonus(char icon, t_info_b *img, int x, int y)
{
	if (icon == 'P' || icon == 'E' || icon == 'C' || icon == 'A')
	{
		img->img_ptr = mlx_xpm_file_to_image(img->mlx_ptr, img->path_bg,
				&(img->xpm_width), &(img->xpm_height));
		put_image_to_window(img, x, y);
	}
	if (icon == 'P')
		img->img_ptr = mlx_xpm_file_to_image(img->mlx_ptr, img->path_player,
				&(img->xpm_width), &(img->xpm_height));
	else if (icon == '1')
		img->img_ptr = mlx_xpm_file_to_image(img->mlx_ptr, img->path_wall,
				&(img->xpm_width), &(img->xpm_height));
	else if (icon == 'C')
		img->img_ptr = mlx_xpm_file_to_image(img->mlx_ptr,
				img->path_collectible, &(img->xpm_width), &(img->xpm_height));
	else if (icon == 'E')
		img->img_ptr = mlx_xpm_file_to_image(img->mlx_ptr, img->path_exit,
				&(img->xpm_width), &(img->xpm_height));
	else if (icon == 'A')
		img->img_ptr = mlx_xpm_file_to_image(img->mlx_ptr, img->path_enemy,
				&(img->xpm_width), &(img->xpm_height));
	else
		img->img_ptr = mlx_xpm_file_to_image(img->mlx_ptr, img->path_bg,
				&(img->xpm_width), &(img->xpm_height));
	put_image_to_window(img, x, y);
}

void	draw_top_window(t_info_b *img)
{
	int	x;

	x = 0;
	while (x < img->width)
	{
		load_xpm_image_bonus('0', img, x, 0);
		x += 60;
	}
}

void	draw_map_bonus(char **map, t_info_b *img)
{
	int	col;
	int	row;
	int	x;
	int	y;

	draw_top_window(img);
	mlx_string_put(img->mlx_ptr, img->win_ptr, \
			60, 25, 0xFFFFFF, "The moves: 0");
	col = 0;
	y = 60;
	while (y < img->height + 60)
	{
		row = 0;
		x = 0;
		while (x < img->width)
		{
			load_xpm_image_bonus(map[col][row], img, x, y);
			x += 60;
			row++;
		}
		y += 60;
		col++;
	}
}
