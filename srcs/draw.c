/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:27:41 by ael-maar          #+#    #+#             */
/*   Updated: 2023/02/01 18:55:11 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_image_to_window(t_info *img, int x, int y)
{
	mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, img->img_ptr, x, y);
	if (img->img_ptr == NULL)
		destroy_all(img, "Check the path if its correct");
	else if (img->xpm_width != 60 || img->xpm_height != 60)
		destroy_all(img, \
			"The size of the xpm file not respecting the right dimensions");
	mlx_destroy_image(img->mlx_ptr, img->img_ptr);
}

static void	load_xpm_image(char icon, t_info *img, int x, int y)
{
	if (icon == 'P' || icon == 'E' || icon == 'C')
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
	else
		img->img_ptr = mlx_xpm_file_to_image(img->mlx_ptr, img->path_bg,
				&(img->xpm_width), &(img->xpm_height));
	put_image_to_window(img, x, y);
}

void	draw_on_window(char **map, t_info *img)
{
	int	col;
	int	row;
	int	x;
	int	y;

	mlx_clear_window(img->mlx_ptr, img->win_ptr);
	col = 0;
	y = 0;
	while (y < img->height)
	{
		row = 0;
		x = 0;
		while (x < img->width)
		{
			load_xpm_image(map[col][row], img, x, y);
			x += 60;
			row++;
		}
		y += 60;
		col++;
	}
}
