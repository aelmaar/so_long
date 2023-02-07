/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 19:51:22 by ael-maar          #+#    #+#             */
/*   Updated: 2023/02/06 17:18:32 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

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
/*       PLAY GAME        */
/*                        */
/**************************/

/* STRUCT OF THAT INCLUDE ALL THE infRMATIONS ABOUT THE GAME */

typedef struct s_inf_b
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
	char	*path_enemy;
	int		collectibles;
	int		width;
	int		height;
	int		player_posx;
	int		player_posy;
	int		door_posx;
	int		door_posy;
	int		count_moves;
	int		xpm_width;
	int		xpm_height;
	t_enemy	*enemies;
	int		enemy_length;
	t_enemy	*temp;
}	t_inf_b;

/* FUNCTIONS THAT DRAW ON THE WINDOW */

void	draw_map_bonus(char **map, t_inf_b *inf);
void	load_xpm_image_bonus(char icon, t_inf_b *inf, int x, int y);
void	draw_top_window(t_inf_b *inf);

/* EVENT HANDLING FUNCTIONS */

int		enemy_patrol(t_inf_b *inf);
int		key_press_bonus(int keycode, t_inf_b *inf);

/* PLAYER MOVE FUNCTION */

void	move_player_bonus(int keycode, t_inf_b *inf);

/* ENEMY MOVE FUNCTION */

void	move_enemy(t_inf_b *inf);

/* GAME START FROM HER */

void	play_game(char **map);

/**************************/
/*                        */
/*       UTILITIES        */
/*                        */
/**************************/

void	component_xy_position(char **map, int *cmp_posy, \
								int *cmp_posx, int icon);
void	free_map(char **map);
void	free_map_on_error(char **map, char *message);
void	destroy_all_bonus(t_inf_b *inf, char *message, int out);
void	enemies_x_y_positions(char **map, t_enemy **enemy);
void	calc_width_height_bonus(char **map, t_inf_b *inf);
void	count_collectibles_bonus(char **map, t_inf_b *inf);

#endif
