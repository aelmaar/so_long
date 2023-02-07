/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:43:14 by ael-maar          #+#    #+#             */
/*   Updated: 2023/02/06 17:18:32 by ael-maar         ###   ########.fr       */
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
	ft_putstr_fd(message, 2);
	free_map(map);
	exit(1);
}

void	destroy_all(t_inf *inf, char *message, int out)
{
	if (inf->img_ptr != NULL)
		mlx_destroy_image(inf->mlx_ptr, inf->img_ptr);
	ft_putstr_fd(message, out);
	if (inf->win_ptr != NULL)
		mlx_destroy_window(inf->mlx_ptr, inf->win_ptr);
	free(inf->mlx_ptr);
	free_map(inf->map);
	exit(0);
}

void	destroy_all_bonus(t_inf_b *inf, char *message, int out)
{
	if (inf->img_ptr != NULL)
		mlx_destroy_image(inf->mlx_ptr, inf->img_ptr);
	ft_putstr_fd(message, out);
	if (inf->win_ptr != NULL)
		mlx_destroy_window(inf->mlx_ptr, inf->win_ptr);
	free(inf->mlx_ptr);
	free_map(inf->map);
	ft_lstclear(&(inf->enemies));
	exit(0);
}
