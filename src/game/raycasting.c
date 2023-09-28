/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 18:42:16 by jsarabia          #+#    #+#             */
/*   Updated: 2023/09/28 15:24:42 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static void	check_horizontal_lines(t_game *game)
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
	if (game->player.direction > PI)
	{
		while (hit != 1)
		{
			auxx = x;
			if (auxy < 0 || auxx < 0)
				hit = 1;
			else if (auxy < ft_get_matrix_size(game->map_data.map)
				&& auxx < (int)ft_strlen(game->map_data.map[auxy])
				&& game->map_data.map[auxy][auxx] == '1')
				hit = 1;
			else if (auxy >= ft_get_matrix_size(game->map_data.map)
				|| auxx >= (float)ft_strlen(game->map_data.map[auxy]))
				hit = 1;
			auxy++;
			x += game->camera.dx / WALL_SIZE;
		}
	}
	if (game->player.direction > 0 && game->player.direction < PI)
	{
		while (hit != 1)
		{
			auxx = x;
			if (auxy < 0 || auxx < 0)
				hit = 1;
			else if (auxy < ft_get_matrix_size(game->map_data.map)
				&& auxx < (int)ft_strlen(game->map_data.map[auxy])
				&& game->map_data.map[auxy][auxx] == '1')
				hit = 1;
			else if (auxy >= ft_get_matrix_size(game->map_data.map)
				|| auxx >= (float)ft_strlen(game->map_data.map[auxy]))
				hit = 1;
			auxy--;
			x += game->camera.dx / WALL_SIZE;
		}
	}
	game->camera.horizontal = pow((game->player.x / WALL_SIZE) * WALL_SIZE - (x * WALL_SIZE), 2)
		+ pow((game->player.y / WALL_SIZE) * WALL_SIZE - (auxy * WALL_SIZE), 2);
	game->camera.horizontal = sqrt(game->camera.horizontal);
}

static void	check_vertical_lines(t_game *game)
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
	if (game->player.direction > PI  / 2 && game->player.direction < 3 * PI  / 2)
	{
		while (hit != 1)
		{
			auxy = y;
			if (auxy < 0 || auxx < 0)
				hit = 1;
			else if (auxy < ft_get_matrix_size(game->map_data.map)
				&& auxx < (int)ft_strlen(game->map_data.map[auxy])
				&& game->map_data.map[auxy][auxx] == '1')
				hit = 1;
			else if (auxy >= ft_get_matrix_size(game->map_data.map)
				|| auxx >= (float)ft_strlen(game->map_data.map[auxy]))
				hit = 1;
			auxx++;
			y += game->camera.dy / WALL_SIZE;
		}
	}
	else
	{
		while (hit != 1)
		{
			auxy = y;
			if (auxy < 0 || auxx < 0)
				hit = 1;
			else if (auxy < ft_get_matrix_size(game->map_data.map)
				&& auxx < (int)ft_strlen(game->map_data.map[auxy])
				&& game->map_data.map[auxy][auxx] == '1')
				hit = 1;
			else if (auxy >= ft_get_matrix_size(game->map_data.map)
				|| auxx >= (float)ft_strlen(game->map_data.map[auxy]))
				hit = 1;
			auxx--;
			y += game->camera.dy / WALL_SIZE;
		}
	}
	game->camera.vertical = pow((game->player.x / WALL_SIZE) * WALL_SIZE - (auxx * WALL_SIZE), 2)
		+ pow((game->player.y / WALL_SIZE) * WALL_SIZE - (y * WALL_SIZE), 2);
	game->camera.vertical = sqrt(game->camera.vertical);
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
		game->camera.direction += 0.00163541666;
		game->camera.fov += 0.03125;
	}
}

//TODO: hacer que cuando los ángulos sean menores a 0º o mayores a 360º no den la vuelta
