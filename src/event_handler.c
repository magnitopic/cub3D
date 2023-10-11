/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 14:50:34 by alaparic          #+#    #+#             */
/*   Updated: 2023/10/11 15:16:51 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	event_handler(enum e_keys key, t_game *game)
{
	if (key == ESC)
		exit_game(game);
	else if (key == W || key == UP)
	{
		game->player.old_x = game->player.x + game->player.direction.x * 32;
		game->player.old_y = game->player.y + game->player.direction.y * 32;
		if (game->map_data.map[(int)game->player.old_x / WALL_SIZE][(int)game->player.y / WALL_SIZE] != '1')
			game->player.x += game->player.direction.x * 32;
		if (game->map_data.map[(int)game->player.x / WALL_SIZE][(int)game->player.old_y / WALL_SIZE] != '1')
			game->player.y += game->player.direction.y * 32;
	}
	else if (key == A)
	{
		game->player.old_x = game->player.x - game->player.direction.x * 32;
		game->player.old_y = game->player.y + game->player.direction.y * 32;
		if (game->map_data.map[(int)game->player.old_x / WALL_SIZE][(int)game->player.y / WALL_SIZE] != '1')
			game->player.x -= game->player.direction.x * 32;
		if (game->map_data.map[(int)game->player.x / WALL_SIZE][(int)game->player.old_y / WALL_SIZE] != '1')
			game->player.y += game->player.direction.y * 32;
	}
	else if (key == S || key == DOWN)
	{
		game->player.old_x = game->player.x - game->player.direction.x * 32;
		game->player.old_y = game->player.y - game->player.direction.y * 32;
		if (game->map_data.map[(int)game->player.old_x / WALL_SIZE][(int)game->player.y / WALL_SIZE] != '1')
			game->player.x -= game->player.direction.x * 32;
		if (game->map_data.map[(int)game->player.x / WALL_SIZE][(int)game->player.old_y / WALL_SIZE] != '1')
			game->player.y -= game->player.direction.y * 32;
	}
	else if (key == D)
	{
		game->player.old_x = game->player.x + game->player.direction.x * 32;
		game->player.old_y = game->player.y - game->player.direction.y * 32;
		if (game->map_data.map[(int)game->player.old_x / WALL_SIZE][(int)game->player.y / WALL_SIZE] != '1')
			game->player.x += game->player.direction.x * 32;
		if (game->map_data.map[(int)game->player.x / WALL_SIZE][(int)game->player.old_y / WALL_SIZE] != '1')
			game->player.y -= game->player.direction.y * 32;
	}
	else if (key == LEFT)
	{
		double	old_dir_x;
		double	old_plane_x;

		old_dir_x = game->player.direction.x;
		game->player.direction.x = game->player.direction.x * cos(0.1) - game->player.direction.y * sin(0.1);
		game->player.direction.y = old_dir_x * sin(0.1) + game->player.direction.y * cos(0.1);
		old_plane_x = game->camera.plane.x;
		game->camera.plane.x = game->camera.plane.x * cos(0.1) - game->camera.plane.y * sin(0.1);
		game->camera.plane.y = old_plane_x * sin(0.1) + game->camera.plane.y * cos(0.1);
	}
	else if (key == RIGHT)
	{
		double	old_dir_x;
		double	old_plane_x;

		old_dir_x = game->player.direction.x;
		game->player.direction.x = game->player.direction.x * cos(-0.1) - game->player.direction.y * sin(-0.1);
		game->player.direction.y = old_dir_x * sin(-0.1) + game->player.direction.y * cos(-0.1);
		old_plane_x = game->camera.plane.x;
		game->camera.plane.x = game->camera.plane.x * cos(-0.1) - game->camera.plane.y * sin(-0.1);
		game->camera.plane.y = old_plane_x * sin(-0.1) + game->camera.plane.y * cos(-0.1);
	}
	re_draw_screen(game);
	return (0);
}
