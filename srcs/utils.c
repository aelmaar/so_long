/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:43:14 by ael-maar          #+#    #+#             */
/*   Updated: 2023/02/06 16:29:37 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "so_long_bonus.h"

void	component_xy_position(char **map, int *cmp_posy, \
								int *cmp_posx, int icon)
{
	*cmp_posy = 0;
	while (map[*cmp_posy] != NULL)
	{
		*cmp_posx = 0;
		while (map[*cmp_posy][*cmp_posx] != '\0')
		{
			if (map[*cmp_posy][*cmp_posx] == icon)
				return ;
			(*cmp_posx)++;
		}
		(*cmp_posy)++;
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

void	destroy_all(t_info *img, char *message)
{
	if (img->img_ptr != NULL)
		mlx_destroy_image(img->mlx_ptr, img->img_ptr);
	ft_putstr_fd(message, 1);
	mlx_destroy_window(img->mlx_ptr, img->win_ptr);
	free(img->mlx_ptr);
	free_map(img->map);
	exit(0);
}

void	destroy_all_bonus(t_info_b *img, char *message)
{
	if (img->img_ptr != NULL)
		mlx_destroy_image(img->mlx_ptr, img->img_ptr);
	ft_putstr_fd(message, 1);
	mlx_destroy_window(img->mlx_ptr, img->win_ptr);
	free(img->mlx_ptr);
	free_map(img->map);
	ft_lstclear(&(img->enemies));
	exit(0);
}
