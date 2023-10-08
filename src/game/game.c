/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 11:52:46 by alaparic          #+#    #+#             */
/*   Updated: 2023/10/08 14:04:39 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static void	get_player_direction(t_game *game)
{
	if (game->map_data.map[(int)game->player.y / WALL_SIZE][(int)game->player.x / WALL_SIZE] == 'N')
	{
		game->player.direction.x = 0;
		game->player.direction.y = -1;
		game->plane.x = 0.66;
		game->plane.y = 0.0;
	}
	if (game->map_data.map[(int)game->player.y / WALL_SIZE][(int)game->player.x / WALL_SIZE] == 'E')
	{
		game->player.direction.x = 1;
		game->player.direction.y = 0;
		game->plane.x = 0.0;
		game->plane.y = 0.66;
	}
	if (game->map_data.map[(int)game->player.y / WALL_SIZE][(int)game->player.x / WALL_SIZE] == 'W')
	{
		game->player.direction.x = -1;
		game->player.direction.y = 0;
		game->plane.x = 0.0;
		game->plane.y = -0.66;
	}
	if (game->map_data.map[(int)game->player.y / WALL_SIZE][(int)game->player.x / WALL_SIZE] == 'S')
	{
		game->player.direction.x = 0;
		game->player.direction.y = 1;
		game->plane.x = -0.66;
		game->plane.y = 0.0;
	}
}

void	start_game(t_game *game)
{
	get_player_direction(game);
	//minimap(game, game->map_data.map);
}
