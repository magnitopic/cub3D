/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 08:50:47 by alaparic          #+#    #+#             */
/*   Updated: 2023/10/09 09:24:23 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include "structs.h"
# include "../libft/libft.h"
# include <math.h>
# include <stdio.h>

# define PROGRAM_NAME "cub3d - "
# define SCREEN_WIDTH 640
# define SCREEN_HEIGHT 480
# define WALL_SIZE 64
# define PLAYER_SIZE WALL_SIZE / 3
# define PI 3.14159265

/* Enum */

enum e_keys
{
	W = 13,
	A = 0,
	S = 1,
	D = 2,
	UP = 126,
	LEFT = 123,
	DOWN = 125,
	RIGHT = 124,
	ESC = 53
};

/**
 * Representing the type of value is found in the file line.
 * If no type if found, ERROR is returned
*/
enum e_values
{
	NO,
	SO,
	WE,
	EA,
	F,
	C,
	ERROR
};

/* Functions */

int		exit_game(t_game *game);
void	raise_error(char *message);
int		ft_rgba(int r, int g, int b, int alpha);
int		event_handler(enum e_keys key, t_game *game);

/* Parsing */

int		map_width(char **map);
char	**read_file(char **argv);
void	check_walls(t_game *game);
void	check_config(t_game *game);
void	check_weird_char(t_game *game);
void	parsing(char **argv, t_game *game);
void	get_values(t_game *game, char **file_con);

/* Game */

void	start_game(t_game *game);
void	raycasting(t_game *game);
void	draw_screen(t_game *game);
void	minimap(t_game *game, char **map);
void	ft_draw_wall(t_game *game, int x, int side);
void	run_game(t_game *game, char *map_name);
void	draw_ceiling_floor(t_game *game, t_color celing, t_color floor);
double 	deg_to_rad(double degrees);
double 	rad_to_deg(double radians);

#endif
