/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 18:42:16 by jsarabia          #+#    #+#             */
/*   Updated: 2023/10/18 19:05:09 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static void	dda_algorithm(t_game *game)
{
	game->cam.hit = 0;
	while (game->cam.hit == 0)
	{
		if (game->cam.sidedx < game->cam.sidedy)
		{
			game->cam.sidedx += game->cam.dx;
			game->cam.grid_x += game->cam.stepx;
			game->cam.offset = 0;
		}
		else
		{
			game->cam.sidedy += game->cam.dy;
			game->cam.grid_y += game->cam.stepy;
			game->cam.offset = 1;
		}
		if (game->map[game->cam.grid_x][game->cam.grid_y]
			== '1')
			game->cam.hit = 1;
	}
}

static void	check_ray_direction(t_game *game)
{
	if (game->cam.raydirx < 0)
	{
		game->cam.stepx = -1;
		game->cam.sidedx = ((game->player.x / WALL_SIZE)
				- game->cam.grid_x) * game->cam.dx;
	}
	else
	{
		game->cam.stepx = 1;
		game->cam.sidedx = (game->cam.grid_x + 1
				- (game->player.x / WALL_SIZE)) * game->cam.dx;
	}
	if (game->cam.raydiry < 0)
	{
		game->cam.stepy = -1;
		game->cam.sidedy = ((game->player.y / WALL_SIZE)
				- game->cam.grid_y) * game->cam.dy;
	}
	else
	{
		game->cam.stepy = 1;
		game->cam.sidedy = (game->cam.grid_y + 1
				- (game->player.y / WALL_SIZE)) * game->cam.dy;
	}
}

void	raycasting(t_game *game)
{
	int	x;

	x = 0;
	while (x < SCREEN_WIDTH)
	{
		game->cam.camerax = (2 * x / (double)SCREEN_WIDTH) - 1;
		game->cam.raydirx = game->player.dir.x
			+ game->cam.plane.x * game->cam.camerax;
		game->cam.raydiry = game->player.dir.y
			+ game->cam.plane.y * game->cam.camerax;
		game->cam.grid_y = game->player.y / WALL_SIZE;
		game->cam.grid_x = game->player.x / WALL_SIZE;
		game->cam.dx = fabs(1 / game->cam.raydirx);
		game->cam.dy = fabs(1 / game->cam.raydiry);
		check_ray_direction(game);
		dda_algorithm(game);
		if (game->cam.offset == 0)
			game->cam.distance = game->cam.sidedx - game->cam.dx;
		else
			game->cam.distance = game->cam.sidedy - game->cam.dy;
		ft_draw_wall(game);
		x++;
	}
}
