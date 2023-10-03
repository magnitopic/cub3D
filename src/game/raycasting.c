/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarabia <jsarabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 18:42:16 by jsarabia          #+#    #+#             */
/*   Updated: 2023/10/03 15:12:34 by jsarabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	check_horizontal_lines(t_game *game)
{
	int		x;
	int		y;
	float	aux;

	if (game->camera.inter_y > 0)
	{
		y = game->camera.grid_y + (game->camera.v_y / 64);
		aux = game->camera.x + ((game->camera.inter_y / tan(game->camera.direction)) / WALL_SIZE);
		x = aux;
		if (y < ft_get_matrix_size(game->map_data.map)
			&& x < (int)ft_strlen(game->map_data.map[y]) && game->map_data.map[y][x] == '1')
		{
			game->camera.hit = 1;
			game->camera.grid_x = x;
			game->camera.grid_y = y;
			game->camera.distance = sqrt(pow((aux * WALL_SIZE) - (game->player.x), 2)
				+ pow((y * WALL_SIZE) - (game->player.y), 2));
				game->camera.offset = 1;
			return ;
		}
		else
			game->camera.v_y += 64;
	}
	else
	{
		y = game->camera.grid_y - (game->camera.v_y / 64);
		aux = game->camera.x + ((game->camera.inter_y / tan(game->camera.direction)) / WALL_SIZE);
		x = aux;
		if (y < ft_get_matrix_size(game->map_data.map)
			&& x < (int)ft_strlen(game->map_data.map[y]) && game->map_data.map[y][x] == '1')
		{
			game->camera.hit = 1;
			game->camera.grid_x = x;
			game->camera.grid_y = y;
			game->camera.distance = sqrt(pow((aux * WALL_SIZE) - (game->player.x), 2)
				+ pow((y * WALL_SIZE) - (game->player.y), 2));
			game->camera.offset = 1;
			return ;
		}
		else
			game->camera.v_y += 64;
	}
}

void	check_vertical_lines(t_game *game)
{
	int		x;
	int		y;
	float	aux;

	if (game->camera.inter_x > 0)
	{
		x = game->camera.grid_x + (game->camera.v_x / 64);
		aux = game->camera.y + ((game->camera.inter_x * sin(game->camera.direction)) / WALL_SIZE);
		y = aux;
		if (y < ft_get_matrix_size(game->map_data.map)
			&& x < (int)ft_strlen(game->map_data.map[y]) && game->map_data.map[y][x] == '1')
		{
			game->camera.hit = 1;
			game->camera.grid_x = x;
			game->camera.grid_y = y;
			game->camera.distance = sqrt(pow((x * WALL_SIZE) - (game->player.x), 2)
				+ pow((aux * WALL_SIZE) - (game->player.y), 2));
			game->camera.offset = 0;
			return ;
		}
		else
			game->camera.v_x += 64;
	}
	else
	{
		x = game->camera.grid_x - (game->camera.v_x / 64);
		aux = game->camera.y + ((game->camera.inter_x * sin(game->camera.direction)) / WALL_SIZE);
		y = aux;
		if (y < ft_get_matrix_size(game->map_data.map)
			&& x < (int)ft_strlen(game->map_data.map[y]) && game->map_data.map[y][x] == '1')
		{
			game->camera.hit = 1;
			game->camera.grid_x = x;
			game->camera.grid_y = y;
			game->camera.distance = sqrt(pow((x * WALL_SIZE) - (game->player.x), 2)
				+ pow((aux * WALL_SIZE) - (game->player.y), 2));
			game->camera.offset = 0;
			return ;
		}
		else
			game->camera.v_x += 64;
	}
}

void	check_next_square(t_game *game)
{
	game->camera.v_x = 64 - (game->player.x - (game->camera.grid_x * WALL_SIZE));
	game->camera.v_y = 64 - (game->player.y - (game->camera.grid_y * WALL_SIZE));
	while (game->camera.hit != 1)
	{
		game->camera.inter_y = game->camera.v_y / sin(game->camera.direction);
		game->camera.inter_x = game->camera.v_x / cos(game->camera.direction);
		if (ft_abs(game->camera.inter_y) < ft_abs(game->camera.inter_x))
			check_horizontal_lines(game);
		else
			check_vertical_lines(game);
	}
}

t_game	*set_starting_camvalues(t_game *game)
{
	game->camera.x = game->player.x / WALL_SIZE;
	game->camera.y = game->player.y / WALL_SIZE;
	game->camera.grid_x = game->camera.x;
	game->camera.grid_y = game->camera.y;
	game->camera.hit = 0;
	return (game);
}

void	raycasting(t_game *game)
{
	game->camera.direction = game->player.direction - (PI / 6);
	game->camera.fov = 0;
	while (game->camera.fov < 60)
	{
		game = set_starting_camvalues(game);
		if (game->camera.direction < 0)
			game->camera.direction += 2 * M_PI;
		if (game->camera.direction > 2 * M_PI)
			game->camera.direction -= 2 * M_PI;
		check_next_square(game);
		ft_draw_wall(game);
		game->camera.direction += 0.00054541539;
		game->camera.fov += 0.03125;
	}
	game->camera.direction = game->player.direction - (PI / 6);
}
