/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarabia <jsarabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 18:42:16 by jsarabia          #+#    #+#             */
/*   Updated: 2023/09/29 18:19:17 by jsarabia         ###   ########.fr       */
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
	if (game->camera.direction < PI) // looking up
	{
		while (hit != 1)
		{
			if (game->map_data.map[y / WALL_SIZE][x / WALL_SIZE] == '1')
				hit = 1;
			y--;
			auxx += (game->player.y / y) / tan(game->camera.direction);
			auxy = y;
		}
	}
	else if (game->camera.direction != PI)							// looking down
	{
		while (hit != 1)
		{
			if (game->map_data.map[y / WALL_SIZE][x / WALL_SIZE] == '1')
				hit = 1;
			y++;
			auxx += (y / game->player.y) / tan(game->camera.direction);
			auxy = y;
		}
	}
	game->camera.horizontal = pow((game->player.x - auxx), 2) + pow((game->player.y - auxy), 2);
	game->camera.horizontal = sqrt(game->camera.horizontal);
}

void	check_vertical_lines(t_game *game)
{
	float	auxx;
	float	auxy;
	int		x;
	int		y;
	int		hit;

	auxx = game->player.x;
	auxy = game->player.y;
	x = auxx;
	y = auxy;
	hit = 0;
	if (game->camera.direction < 2 * PI / 3 && game->camera.direction > PI) // looking left
	{
		while (hit != 1)
		{
			if (game->map_data.map[y / WALL_SIZE][x / WALL_SIZE] == '1')
				hit = 1;
			x--;
			auxy += (game->player.x / x) * tan(game->camera.direction);
			auxx = x;
		}
	}
	else						// looking down
	{
		while (hit != 1)
		{
			if (game->map_data.map[y / WALL_SIZE][x / WALL_SIZE] == '1')
				hit = 1;
			x++;
			auxy += (x / game->player.x) * tan(game->camera.direction);
			auxx = x;
		}
	}
	game->camera.vertical = pow((game->player.x - auxx), 2) + pow((game->player.y - auxy), 2);
	game->camera.vertical =  sqrt(game->camera.vertical);
}

void	raycasting(t_game *game)
{
	game->camera.fov = 0;
	if (game->player.direction < 0)
		game->player.direction += 2 * M_PI;
	if (game->player.direction > 2 * M_PI)
		game->player.direction -= 2 * M_PI;
	game->camera.direction = game->player.direction - (PI / 6);
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
		ft_draw_wall(game);
		game->camera.direction += 0.00054541539;
		//game->camera.direction += 0.03125;
		game->camera.fov += 0.03125;
	}
	game->camera.direction = game->player.direction - (PI / 6);
}
