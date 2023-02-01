/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 19:05:53 by ael-maar          #+#    #+#             */
/*   Updated: 2023/02/01 18:39:21 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/**************************/
/*                        */
/*     INCLUDES FILES     */
/*                        */
/**************************/

# include "libft.h"
# include "stdlib.h"
# include "fcntl.h"
# include "mlx.h"
# include "unistd.h"
# include "stdio.h"
# include "get_next_line.h"
# include "ft_printf.h"

/**************************/
/*                        */
/*     READ FROM MAP      */
/*                        */
/**************************/

char	**read_from_map(char *map_file);

/**************************/
/*                        */
/*       CHECK MAP        */
/*                        */
/**************************/

int		is_map_not_rectangular(char **map);
int		is_start_exit_duplicated(char **map);
int		is_valid_map_components(char **map);
int		is_map_surrounded_by_walls(char **map);
int		is_valid_path(char **map);
void	check_map(char	**map);

/**************************/
/*                        */
/*       UTILITIES        */
/*                        */
/**************************/

void	player_xy_position(char **map, int *player_posy, int *player_posx);
void	free_map(char **map);
void	free_map_on_error(char **map, char *message);

/**************************/
/*                        */
/*       PLAY GAME        */
/*                        */
/**************************/

/* STRUCT OF THAT INCLUDE ALL THE INFORMATIONS ABOUT THE GAME */

typedef struct s_info
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	**map;
	char	*path_player;
	char	*path_exit;
	char	*path_collectible;
	char	*path_wall;
	char	*path_bg;
	int		collectibles;
	int		width;
	int		height;
	int		player_posx;
	int		player_posy;
	int		count_moves;
	int		xpm_width;
	int		xpm_height;
}	t_info;

/* FUNCTION THAT DRAW ON THE WINDOW */

void	draw_on_window(char **map, t_info *img);

/* SOME UTILITIES REQUIRED FOR PLAY GAME FUNCTION */

void	calc_width_height(char **map, t_info *img);
void	count_collectibles(char **map, t_info *img);
void	destroy_all(t_info *img, char *message);

/* PLAYER MOVE FUNCTIONS */

void	move_right(t_info *img);
void	move_up(t_info *img);
void	move_left(t_info *img);
void	move_bottom(t_info *img);

/* GAME START FROM HER */

void	play_game(char **map);

#endif
