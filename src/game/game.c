/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarabia <jsarabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 11:52:46 by alaparic          #+#    #+#             */
/*   Updated: 2023/09/25 15:22:54 by jsarabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static t_player	get_player_direction(t_game *game)
{
	if (game->map_data.map[(int)game->player.y][(int)game->player.x] == 'N')
	{
		game->player.direction = PI / 2;
		game->player.dx = cos(game->player.direction);
		game->player.dy = sin(game->player.direction);
	}
	if (game->map_data.map[(int)game->player.y][(int)game->player.x] == 'E')
	{
		game->player.direction = 2 * PI;
		game->player.dx = cos(game->player.direction);
		game->player.dy = sin(game->player.direction);
	}
	if (game->map_data.map[(int)game->player.y][(int)game->player.x] == 'W')
	{
		game->player.direction = PI;
		game->player.dx = cos(game->player.direction);
		game->player.dy = sin(game->player.direction);
	}
	if (game->map_data.map[(int)game->player.y][(int)game->player.x] == 'S')
	{
		game->player.direction = 2 * PI / 3;
		game->player.dx = cos(game->player.direction);
		game->player.dy = sin(game->player.direction);
	}
	return (game->player);
}

void	start_game(t_game *game)
{
	game->player = get_player_direction(game);
	minimap(game, game->map_data.map);
}
