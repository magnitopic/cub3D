/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarabia <jsarabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 18:42:16 by jsarabia          #+#    #+#             */
/*   Updated: 2023/09/27 12:55:32 by jsarabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

/*void	check_vertical_lines(t_game *game)
{

}*/

void	check_horizontal_lines(t_game *game, int rays)
{
	game->camera.ray_x = 2 * game->player.x / (double)rays - 1;
	game->camera.ray_dirx = game->player.dx + game->camera.max_x * game->camera.ray_x;
	game->camera.ray_diry = game->player.dy + game->camera.max_y * game->camera.ray_x;
}

void	raycasting(t_game *game)
{
	int	rays;

	rays = 0;
	game->camera.ray_angle = game->player.direction;
	while (rays++ < SCREEN_WIDTH)
	{
		check_horizontal_lines(game, rays);
		//check_vertical_lines(game);
	}
}
