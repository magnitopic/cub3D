/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarabia <jsarabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 18:42:16 by jsarabia          #+#    #+#             */
/*   Updated: 2023/09/29 12:58:44 by jsarabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	check_horizontal_lines(t_game *game)
{
	float	auxx;
	float	auxy;
	int		x;
	int		y;
	int		hit;

	hit = 0;
	auxx = game->player.x;
	auxy = game->player.y;
	x = auxx;
	y = auxy;
	printf("pos: %f,%f\n", auxx, auxy);
	printf("angle: %f\n", game->player.direction);
	if (game->camera.direction < PI) // looking up
	{
		while (hit != 1)
		{
			if (game->map_data.map[y / WALL_SIZE][x / WALL_SIZE] == '1')
				hit = 1;
			y--;
			auxx += (game->player.y / y) / tan(game->camera.direction);
			game->player.y = y;
		}
	}
	else if (tan(game->camera.direction) != 0)							// looking down
	{
		while (hit != 1)
		{
			printf("%f\n", tan(PI));
			if (game->map_data.map[y / WALL_SIZE][x / WALL_SIZE] == '1')
				hit = 1;
			y++;
			auxx += (y / game->player.y) / tan(game->camera.direction);
			game->player.y = y;
		}
	}
}

void	check_vertical_lines(t_game *game)
{
	float	auxx;
	float	auxy;
	int		x;
	int		y;

	auxx = game->player.x;
	auxy = game->player.y;
	x = auxx;
	y = auxy;
	printf("pos: %d,%d\n", x, y);
}

void	raycasting(t_game *game)
{
	game->camera.fov = 0;
	game->camera.direction = game->player.direction + (PI / 6);
	while (game->camera.fov < 60)
	{
		if (game->camera.direction < 0)
			game->camera.direction += 2 * M_PI;
		if (game->camera.direction > 2 * M_PI)
			game->camera.direction -= 2 * M_PI;
		game->camera.dx = cos(game->camera.direction);
		game->camera.dy = sin(game->camera.direction);
		check_horizontal_lines(game);
		check_vertical_lines(game);
		if (game->camera.vertical < game->camera.horizontal
			|| game->camera.horizontal == 0)
		{
			game->camera.distance = game->camera.vertical;
			game->camera.offset = 1;
		}
		else
		{
			game->camera.distance = game->camera.horizontal;
			game->camera.offset = 0;
		}
		//ft_draw_wall(game);
		game->camera.direction -= 0.00054541539;
		game->camera.fov += 0.03125;
	}
}

//TODO: hacer que cuando los ángulos sean menores a 0º o mayores a 360º no den la vuelta
