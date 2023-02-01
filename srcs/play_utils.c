/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:40:08 by ael-maar          #+#    #+#             */
/*   Updated: 2023/01/30 19:28:26 by ael-maar         ###   ########.fr       */
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

void	destroy_all(t_info *img, char *message)
{
	ft_putstr_fd(message, 1);
	mlx_clear_window(img->mlx_ptr, img->win_ptr);
	free(img->mlx_ptr);
	free_map(img->map);
	exit(0);
}
