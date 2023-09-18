/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 08:50:47 by alaparic          #+#    #+#             */
/*   Updated: 2023/09/18 11:46:52 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include "structs.h"
# include "../libft/libft.h"

# define PROGRAM_NAME "cub3d - "
# define SCREEN_WIDTH 1920
# define SCREEN_HEIGHT 1080

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

/* Functions */

int		exit_game(t_game *game);
void	raise_error(char *message);
void	read_file(char **argv, t_game *game);
void	run_game(t_game *game, char *map_name);
void	draw_ceiling_floor(t_game *game);
int		event_handler(enum e_keys key, t_game *game);

#endif
