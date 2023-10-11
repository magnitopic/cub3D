/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarabia <jsarabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 11:52:46 by alaparic          #+#    #+#             */
/*   Updated: 2023/10/11 17:05:46 by jsarabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	get_player_direction(t_game *game)
{
	if (game->map_data.map[(int)game->player.x / WALL_SIZE][(int)game->player.y / WALL_SIZE] == 'W')
	{
		game->camera.plane.x = -0.66;
		game->camera.plane.y = 0;
		game->player.direction.x = 0;
		game->player.direction.y = -1;
	}
	if (game->map_data.map[(int)game->player.x / WALL_SIZE][(int)game->player.y / WALL_SIZE] == 'S')
	{
		game->camera.plane.y = -0.66;
		game->camera.plane.x = 0;
		game->player.direction.x = 1;
		game->player.direction.y = 0;
	}
	if (game->map_data.map[(int)game->player.x / WALL_SIZE][(int)game->player.y / WALL_SIZE] == 'N')
	{
		game->camera.plane.y = 0.66;
		game->camera.plane.x = 0;
		game->player.direction.x = -1;
		game->player.direction.y = 0;
	}
	if (game->map_data.map[(int)game->player.x / WALL_SIZE][(int)game->player.y / WALL_SIZE] == 'E')
	{
		game->camera.plane.x = 0.66;
		game->camera.plane.y = 0;
		game->player.direction.x = 0;
		game->player.direction.y = 1;
	}
}

void	start_game(t_game *game)
{
	get_player_direction(game);
	game->player.x += WALL_SIZE / 2;
	game->player.y += WALL_SIZE / 2;
	//exit (0);
	raycasting(game);
}
