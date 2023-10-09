/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 11:52:46 by alaparic          #+#    #+#             */
/*   Updated: 2023/10/09 12:54:02 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static void	get_player_direction(t_game *game)
{
	if (game->map_data.map[(int)game->player.x][(int)game->player.y] == 'N')
	{
		game->player.direction->x = 0;
		game->player.direction->y = -1;
		game->plane->x = 0.66;
		game->plane->y = 0.0;
		
	}
	if (game->map_data.map[(int)game->player.x][(int)game->player.y] == 'E')
	{
		game->player.direction->x = 1;
		game->player.direction->y = 0;
		game->plane->x = 0.0;
		game->plane->y = 0.66;
	}
	if (game->map_data.map[(int)game->player.x][(int)game->player.y] == 'W')
	{
		game->player.direction->x = -1;
		game->player.direction->y = 0;
		game->plane->x = 0.0;
		game->plane->y = -0.66;
	}
	printf("%c\n", game->map_data.map[(int)game->player.x][(int)game->player.y]);
	if (game->map_data.map[(int)game->player.x][(int)game->player.y] == 'S')
	{
		game->player.direction->x = 0;
		game->player.direction->y = 1;
		game->plane->x = -0.66;
		game->plane->y = 0.0;
	}
}

void	start_game(t_game *game)
{
	// TODO: Free these values
	game->player.direction = ft_calloc(sizeof(t_vector), 1);
	game->plane = ft_calloc(sizeof(t_vector), 1);
	
	get_player_direction(game);
	//minimap(game, game->map_data.map);
}
