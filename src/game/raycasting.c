/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarabia <jsarabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 18:42:16 by jsarabia          #+#    #+#             */
/*   Updated: 2023/09/27 19:17:49 by jsarabia         ###   ########.fr       */
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
	if (game->camera.dy > 0)
	{
		while (hit != 1)
		{
			auxy--;
			x += game->camera.dx;
			auxx = x;
			if (auxy < ft_get_matrix_size(game->map_data.map)
				&& auxx < (float)ft_strlen(game->map_data.map[auxy])
				&& game->map_data.map[auxy][auxx] == '1')
				hit = 1;
			if (auxy <= 0 || auxx <= 0)
				hit = 1;
			if (auxy >= ft_get_matrix_size(game->map_data.map)
				|| auxx >= (float)ft_strlen(game->map_data.map[auxy]))
				hit = 1;
		}
	}
	if (game->camera.dy < 0)
	{
		while (hit != 1)
		{
			auxy++;
			x += game->camera.dx;
			auxx = x;
			if (auxy < ft_get_matrix_size(game->map_data.map)
				&& auxx < (float)ft_strlen(game->map_data.map[auxy])
				&& game->map_data.map[auxy][auxx] == '1')
				hit = 1;
			if (auxy <= 0 || auxx <= 0)
				hit = 1;
			if (auxy >= ft_get_matrix_size(game->map_data.map)
				|| auxx >= (float)ft_strlen(game->map_data.map[auxy]))
				hit = 1;
		}
	}
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
	if (game->camera.dx > 0)
	{
		while (hit != 1)
		{
			auxx++;
			y += game->camera.dx;
			auxy = y;
			if (auxy < ft_get_matrix_size(game->map_data.map)
				&& auxx < (float)ft_strlen(game->map_data.map[auxy])
				&& game->map_data.map[auxy][auxx] == '1')
				hit = 1;
			if (auxy <= 0 || auxx <= 0)
				hit = 1;
			if (auxy >= ft_get_matrix_size(game->map_data.map)
				|| auxx >= (float)ft_strlen(game->map_data.map[auxy]))
				hit = 1;
		}
	}
	else if (game->camera.dx > 0)
	{
		while (hit != 1)
		{
			auxx--;
			y += game->camera.dx;
			auxy = y;
			if (auxy < ft_get_matrix_size(game->map_data.map)
				&& auxx < (float)ft_strlen(game->map_data.map[auxy])
				&& game->map_data.map[auxy][auxx] == '1')
				hit = 1;
			if (auxy <= 0 || auxx <= 0)
				hit = 1;
			if (game->map_data.map[auxy][auxx] == '1')
				hit = 1;
			if (auxy >= ft_get_matrix_size(game->map_data.map)
				|| auxx >= (float)ft_strlen(game->map_data.map[auxy]))
				hit = 1;
		}
	}
	game->camera.vertical = pow(auxx, 2) + pow(auxy, 2);
}

void	raycasting(t_game *game)
{
	game->camera.fov = 0;
	game->camera.direction = game->player.direction - (PI / 6);
	while (game->camera.fov < 60)
	{
		game->camera.dx = cos(game->camera.direction) * 5;
		game->camera.dy = sin(game->camera.direction) * 5;
		check_horizontal_lines(game);
		check_vertical_lines(game);
		if (game->camera.vertical < game->camera.horizontal)
			game->camera.distance = game->camera.vertical;
		else
			game->camera.distance = game->camera.horizontal;
		printf("distance: %f  %f\n", game->camera.distance, game->camera.fov);
		game->camera.direction += 0.00163541666;
		game->camera.fov += 0.03125;
	}
}
