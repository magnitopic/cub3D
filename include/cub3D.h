/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 08:50:47 by alaparic          #+#    #+#             */
/*   Updated: 2023/10/17 12:24:18 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include "structs.h"
# include "../libft/libft.h"
# include <math.h>
# include <stdio.h>
# include <limits.h>

/* Defines */

# define PROGRAM_NAME "cub3d - "
# define PI 3.14159265
# define SCREEN_WIDTH 640
# define SCREEN_HEIGHT 480
# define WALL_SIZE 64
// WALL_SIZE * 0.5
# define SPEED 32

/* Enums */

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
 * Representing the type of value found in the file line.
 * If no type is found value will be ERROR
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
void	ft_draw_wall(t_game *game);
void	free_matrix_int(int **matrix);
int		ft_rgba(int r, int g, int b, int alpha);
int		event_handler(enum e_keys key, t_game *game);
void	draw_ceiling_floor(t_game *game, t_color celing, t_color floor);

/* Parsing */

char	**read_file(char **argv);
void	check_walls(t_game *game);
void	parsing(char **argv, t_game *game);
void	get_values(t_game *game, char **file_con);
void	check_closed_walls(t_game *game, char **map);

/* Game */

void	start_game(t_game *game);
void	raycasting(t_game *game);
void	re_draw_screen(t_game *game);
void	run_game(t_game *game, char *map_name);

#endif
