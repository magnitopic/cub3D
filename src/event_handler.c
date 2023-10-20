/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 14:50:34 by alaparic          #+#    #+#             */
/*   Updated: 2023/10/20 12:25:43 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

static int	check_for_walls(t_game *game)
{
	if (game->player.old_y <= WALL_SIZE || (int)game->player.old_x / WALL_SIZE
		>= ft_get_matrix_size(game->map))
		return (0);
	if (game->player.old_x <= WALL_SIZE || (int)game->player.old_y
		/ WALL_SIZE >= (int)ft_strlen(game->map
			[(int)game->player.old_x / WALL_SIZE]))
		return (0);
	return (1);
}

static void	handle_arows(t_game *game, enum e_keys key)
{
	double	old_dir_x;
	double	old_plane_x;
	double	rot_speed;

	rot_speed = 0.1;
	if (key == RIGHT)
		rot_speed *= -1;
	old_dir_x = game->player.dir.x;
	game->player.dir.x = game->player.dir.x * cos(rot_speed)
		- game->player.dir.y * sin(rot_speed);
	game->player.dir.y = old_dir_x * sin(rot_speed)
		+ game->player.dir.y * cos(rot_speed);
	old_plane_x = game->cam.plane.x;
	game->cam.plane.x = game->cam.plane.x * cos(rot_speed)
		- game->cam.plane.y * sin(rot_speed);
	game->cam.plane.y = old_plane_x * sin(rot_speed)
		+ game->cam.plane.y * cos(rot_speed);
}

static void	move_back_and_forth(t_game *game, enum e_keys key)
{
	if (key == W || key == UP)
	{
		game->player.old_x = game->player.x + game->player.dir.x * SPEED;
		game->player.old_y = game->player.y + game->player.dir.y * SPEED;
		if (!check_for_walls(game))
			return ;
		if (game->map[(int)game->player.old_x / WALL_SIZE]
			[(int)game->player.y / WALL_SIZE] != '1')
			game->player.x += game->player.dir.x * SPEED;
		if (game->map[(int)game->player.x / WALL_SIZE]
			[(int)game->player.old_y / WALL_SIZE] != '1')
			game->player.y += game->player.dir.y * SPEED;
		return ;
	}
	game->player.old_x = game->player.x - game->player.dir.x * SPEED;
	game->player.old_y = game->player.y - game->player.dir.y * SPEED;
	if (!check_for_walls(game))
		return ;
	if (game->map[(int)game->player.old_x / WALL_SIZE]
		[(int)game->player.y / WALL_SIZE] != '1')
		game->player.x -= game->player.dir.x * SPEED;
	if (game->map[(int)game->player.x / WALL_SIZE]
		[(int)game->player.old_y / WALL_SIZE] != '1')
		game->player.y -= game->player.dir.y * SPEED;
}

static void	move_side_to_side(t_game *game, enum e_keys key)
{
	if (key == A)
	{
		game->player.old_x = game->player.x - game->player.dir.y * SPEED;
		game->player.old_y = game->player.y + game->player.dir.x * SPEED;
		if (!check_for_walls(game))
			return ;
		if (game->map[(int)game->player.old_x / WALL_SIZE]
			[(int)game->player.y / WALL_SIZE] != '1')
			game->player.x -= game->player.dir.y * SPEED;
		if (game->map[(int)game->player.x / WALL_SIZE]
			[(int)game->player.old_y / WALL_SIZE] != '1')
			game->player.y += game->player.dir.x * SPEED;
		return ;
	}
	game->player.old_x = game->player.x + game->player.dir.y * SPEED;
	game->player.old_y = game->player.y - game->player.dir.x * SPEED;
	if (!check_for_walls(game))
		return ;
	if (game->map[(int)game->player.old_x / WALL_SIZE]
		[(int)game->player.y / WALL_SIZE] != '1')
		game->player.x += game->player.dir.y * SPEED;
	if (game->map[(int)game->player.x / WALL_SIZE]
		[(int)game->player.old_y / WALL_SIZE] != '1')
		game->player.y -= game->player.dir.x * SPEED;
}

int	event_handler(enum e_keys key, t_game *game)
{
	if (key == ESC)
		exit_game(game);
	if (key == LEFT || key == RIGHT)
		handle_arows(game, key);
	else if (key == W || key == S || key == UP || key == DOWN)
		move_back_and_forth(game, key);
	else if (key == A || key == D)
		move_side_to_side(game, key);
	re_draw_screen(game);
	return (0);
}
