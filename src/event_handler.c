/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 14:50:34 by alaparic          #+#    #+#             */
/*   Updated: 2023/10/09 09:24:40 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

static void	ft_handle_was(enum e_keys key, t_game *game)
{
	
	if (key == W || key == UP)
	{
		if (game->map_data.map[(int)game->player.y / WALL_SIZE][(int)(game->player.x + game->player.direction.x * 10) / WALL_SIZE] != '1')
			game->player.x += game->player.direction.x;
		if (game->map_data.map[(int)(game->player.y + game->player.direction.y * 10) / WALL_SIZE][(int)game->player.x / WALL_SIZE] != '1')
			game->player.y += game->player.direction.y;
	}
	else if (key == A)
	{
		if (game->map_data.map[(int)game->player.y / WALL_SIZE][(int)(game->player.x + game->player.direction.y * 10) / WALL_SIZE] != '1')
			game->player.x += game->player.direction.y;
		if (game->map_data.map[(int)(game->player.y - game->player.direction.x * 10) / WALL_SIZE][(int)game->player.x / WALL_SIZE] != '1')
			game->player.y -= game->player.direction.x;
	}
	else if (key == S || key == DOWN)
	{
		if (game->map_data.map[(int)game->player.y / WALL_SIZE][(int)(game->player.x - game->player.direction.x * 10) / WALL_SIZE] != '1')
			game->player.x -= game->player.direction.x;
		if (game->map_data.map[(int)(game->player.y - game->player.direction.y * 10) / WALL_SIZE][(int)game->player.x / WALL_SIZE] != '1')
			game->player.y -= game->player.direction.y;
	}
}

static void	ft_handle_arrows_and_d(enum e_keys key, t_game *game)
{
	if (key == D)
	{
		if (game->map_data.map[(int)game->player.y / WALL_SIZE][(int)(game->player.x - game->player.direction.y * 10) / WALL_SIZE] != '1')
			game->player.x -= game->player.direction.y;
		if (game->map_data.map[(int)(game->player.y + game->player.direction.x * 10) / WALL_SIZE][(int)game->player.x / WALL_SIZE] != '1')
			game->player.y += game->player.direction.x;
	}
	if (key == LEFT)
	{
		double oldDirectionX = game->player.direction.x;
		game->player.direction.x = game->player.direction.x * cos(-0.05) - game->player.direction.y * sin(-0.05);
		game->player.direction.y = oldDirectionX * sin(-0.05) + game->player.direction.y * cos(-0.05);
		double oldPlaneX = game->plane.x;
		game->plane.x = game->plane.x * cos(-0.05) - game->plane.y * sin(-0.05);
		game->plane.y = oldPlaneX * sin(-0.05) + game->plane.y * cos(-0.05);
	}
	else if (key == RIGHT)
	{
		double oldDirectionX = game->player.direction.x;
		game->player.direction.x = game->player.direction.x * cos(0.05) - game->player.direction.y * sin(0.5);
		game->player.direction.y = oldDirectionX * sin(0.5) + game->player.direction.y * cos(0.5);
		double oldPlaneX = game->plane.x;
		game->plane.x = game->plane.x * cos(0.5) - game->plane.y * sin(0.5);
		game->plane.y = oldPlaneX * sin(0.5) + game->plane.y * cos(0.5);
	}
}

/**
 * Check what key was pressed and move the player accordingly, the draw the
 * screen to update the player's view.
*/
int	event_handler(enum e_keys key, t_game *game)
{
	if (key == ESC)
		exit_game(game);
	ft_handle_was(key, game);
	ft_handle_arrows_and_d(key, game);
	draw_screen(game);
	return (0);
}
