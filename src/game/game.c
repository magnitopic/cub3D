/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarabia <jsarabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 11:52:46 by alaparic          #+#    #+#             */
/*   Updated: 2023/10/09 17:48:19 by jsarabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	get_player_direction(t_game *game)
{
	if (game->map_data.map[(int)game->player.y / WALL_SIZE][(int)game->player.x / WALL_SIZE] == 'N')
	{
		game->camera.directionx = -1;
		game->camera.directiony = 0;
		game->player.direction = 1.570796325;
		game->player.dx = cos(game->player.direction) * 5;
		game->player.dy = sin(game->player.direction) * 5;
	}
	if (game->map_data.map[(int)game->player.y / WALL_SIZE][(int)game->player.x / WALL_SIZE] == 'E')
	{
		game->camera.directionx = 0;
		game->camera.directiony = 1;
		game->player.direction = 6.2831853;
		game->player.dx = cos(game->player.direction) * 5;
		game->player.dy = sin(game->player.direction) * 5;
	}
	if (game->map_data.map[(int)game->player.y / WALL_SIZE][(int)game->player.x / WALL_SIZE] == 'W')
	{
		game->camera.directionx = 0;
		game->camera.directiony = -1;
		game->player.direction = 3.14159265;
		game->player.dx = cos(game->player.direction) * 5;
		game->player.dy = sin(game->player.direction) * 5;
	}
	if (game->map_data.map[(int)game->player.y / WALL_SIZE][(int)game->player.x / WALL_SIZE] == 'S')
	{
		game->camera.directionx = 1;
		game->camera.directiony = 0;
		game->player.direction = 4.712388975;
		game->player.dx = cos(game->player.direction) * 5;
		game->player.dy = sin(game->player.direction) * 5;
	}
}

void	start_game(t_game *game)
{
	get_player_direction(game);
	game->camera.planex = 0;
	game->camera.planey = 0.66;
	game->camera.grid_y = game->player.y / WALL_SIZE;
	game->camera.grid_x = game->player.x / WALL_SIZE;
	raycasting(game);
	//minimap(game, game->map_data.map);
}
