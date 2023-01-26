/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 19:05:53 by ael-maar          #+#    #+#             */
/*   Updated: 2023/01/26 17:18:02 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

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

int	is_map_not_rectangular(char **map);
int	is_start_exit_duplicated(char **map);
int	is_valid_map_components(char **map);
int	is_map_surrounded_by_walls(char **map);
int	is_valid_path(char **map);
void	check_map(char	**map);

#endif
