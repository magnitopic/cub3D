/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarabia <jsarabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 18:42:16 by jsarabia          #+#    #+#             */
/*   Updated: 2023/09/27 18:14:40 by jsarabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	check_horizontal_lines(t_game *game)
{
	float	y;
	float	x;
	int		auxx;
	int		auxy;
	int		hit;

	hit = 0;
	y = game->player.y / WALL_SIZE;
	auxy = y;
	x = game->player.x / WALL_SIZE;
	auxx = x;
	if (game->player.dy > 0) //looking UP
	{
		while (hit != 1)
		{
			auxy--;
			x += game->player.dx;
			auxx = x;
			if (game->map_data.map[auxy][auxx] == '1')
				hit = 1;
		}
	}
	else if (game->player.dy < 0) //looking DOWN
	{
		while (hit != 1)
		{
			auxy++;
			x += game->player.dx;
			auxx = x;
			if (game->map_data.map[auxy][auxx] == '1')
				hit = 1;
		}
	}
	printf("wall at map[%d][%d]\n", auxy, auxx);
	game->camera.horizontal = pow(auxx, 2) + pow(auxy, 2);
}

void	check_vertical_lines(t_game *game)
{
	float	y;
	float	x;
	int		auxx;
	int		auxy;
	int		hit;

	hit = 0;
	y = game->player.y / WALL_SIZE;
	auxy = y;
	x = game->player.x / WALL_SIZE;
	auxx = x;
	if (game->player.dx > 0) //looking RIGHT
	{
		while (hit != 1)
		{
			auxx++;
			y += game->player.dx;
			auxy = y;
			if (game->map_data.map[auxy][auxx] == '1')
				hit = 1;
		}
	}
	if (game->player.dx > 0) //looking LEFT*/
	{
		while (hit != 1)
		{
			auxx--;
			y += game->player.dx;
			auxy = y;
			if (game->map_data.map[auxy][auxx] == '1')
				hit = 1;
		}
	}
	printf("wall at map[%d][%d]\n", auxy, auxx);
	game->camera.vertical = pow(auxx, 2) + pow(auxy,  2);
}

void	raycasting(t_game *game)
{
	int	rays;

	rays = -1;
	check_horizontal_lines(game);
	check_vertical_lines(game);
	if (game->camera.vertical < game->camera.horizontal)
		game->camera.distance  = game->camera.vertical;
	else
		game->camera.distance  = game->camera.horizontal;
	printf("distance: %f\n", game->camera.distance);
}
