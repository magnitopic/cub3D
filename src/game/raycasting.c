/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarabia <jsarabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 18:42:16 by jsarabia          #+#    #+#             */
/*   Updated: 2023/10/06 18:36:17 by jsarabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	raycasting(t_game *game)
{
	int	x;

	x = 0;
	while (x < SCREEN_WIDTH)
	{
		game->camera.camerax = (2 * x / (double)SCREEN_WIDTH) - 1;
		game->camera.raydirx = game->camera.directionx - game->camera.planex * game->camera.camerax;
		game->camera.raydiry = game->camera.directiony - game->camera.planey * game->camera.camerax;
		game->camera.grid_x = game->player.x / WALL_SIZE;
		game->camera.grid_y = game->camera.y / WALL_SIZE;
		x++;
	}
	exit (0);
}
