/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarabia <jsarabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 18:42:16 by jsarabia          #+#    #+#             */
/*   Updated: 2023/10/03 18:24:05 by jsarabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	check_horizontal_lines(t_game *game)
{
	int		y;
	float	aux;

	if (game->camera.inter_y > 0)
	{
		y = ((game->camera.y / WALL_SIZE) * WALL_SIZE) - 1;
		game->camera.grid_y = y / WALL_SIZE;
		if (game->camera.xa == 0)
			aux = game->camera.x + ((y - game->camera.y) / tan(game->camera.direction));
		else
			aux = game->camera.x + game->camera.xa;
		game->camera.grid_x = aux / WALL_SIZE;
		if (game->camera.grid_y >= ft_get_matrix_size(game->map_data.map)
			|| game->camera.grid_y < 0 || game->camera.grid_x < 0
			|| game->camera.grid_x >= (int)ft_strlen(game->map_data.map[game->camera.grid_y]))
		{
			game->camera.hit = 1;
			game->camera.vertical = 1000000000;
			game->camera.offset = 1;
			return ;
		}
		if (game->map_data.map[game->camera.grid_y][game->camera.grid_x] == '1')
		{
			game->camera.hit = 1;
			game->camera.horizontal = sqrt(pow(aux - game->player.x, 2)
				+ pow(y - game->player.y, 2));
				game->camera.offset = 1;
			return ;
		}
		else
			game->camera.y -= 64;
	}
	else
	{
		y = ((game->camera.y / WALL_SIZE) * WALL_SIZE) - 1;
		game->camera.grid_y = y / WALL_SIZE;
		if (game->camera.xa == 0)
			aux = game->camera.x + ((y - game->camera.y) / tan(game->camera.direction));
		else
			aux = game->camera.x + game->camera.xa;
		game->camera.grid_x = aux / WALL_SIZE;
		if (game->camera.grid_y >= ft_get_matrix_size(game->map_data.map)
			|| game->camera.grid_y < 0 || game->camera.grid_x < 0
			|| game->camera.grid_x >= (int)ft_strlen(game->map_data.map[game->camera.grid_y]))
		{
			game->camera.hit = 1;
			game->camera.vertical = 1000000000;
			game->camera.offset = 1;
			return ;
		}
		if (game->map_data.map[game->camera.grid_y][game->camera.grid_x] == '1')
		{
			game->camera.hit = 1;
			game->camera.horizontal = sqrt(pow(aux - game->player.x, 2)
				+ pow(y - game->player.y, 2));
				game->camera.offset = 1;
			return ;
		}
		else
			game->camera.y += 64;
	}
	game->camera.xa = WALL_SIZE / tan(game->camera.direction);
}

void	check_vertical_lines(t_game *game)
{
	int		x;
	float	aux;

	if (game->camera.inter_x > 0)
	{
		x = ((game->camera.x / WALL_SIZE) * WALL_SIZE) + 64;
		game->camera.grid_x = x / WALL_SIZE;
		if (game->camera.ya == 0)
			aux = game->camera.y + ((x - game->camera.x) * tan(game->camera.direction));
		else
			aux = game->camera.y + game->camera.ya;
		game->camera.grid_y = aux / WALL_SIZE;
		if (game->camera.grid_y >= ft_get_matrix_size(game->map_data.map)
			|| game->camera.grid_y < 0 || game->camera.grid_x < 0
			|| x >= (int)ft_strlen(game->map_data.map[game->camera.grid_y]))
		{
			game->camera.hit = 1;
			game->camera.vertical = 1000000000;
			game->camera.offset = 0;
			return ;
		}
		if (game->map_data.map[game->camera.grid_y][game->camera.grid_x] == '1')
		{
			game->camera.hit = 1;
			game->camera.vertical = sqrt(pow(x - game->player.x, 2)
				+ pow(aux - game->player.y, 2));
			game->camera.offset = 0;
			return ;
		}
		else
			game->camera.x += 64;
	}
	else
	{
		x = ((game->camera.x / WALL_SIZE) * WALL_SIZE) - 1;
		game->camera.grid_x = x / WALL_SIZE;
		if (game->camera.ya == 0)
			aux = game->camera.y + ((x - game->camera.x) * tan(game->camera.direction));
		else
			aux = game->camera.y + game->camera.ya;
		game->camera.grid_y = aux / WALL_SIZE;
		if (game->camera.grid_y >= ft_get_matrix_size(game->map_data.map)
			|| game->camera.grid_y < 0 || game->camera.grid_x < 0
			|| x >= (int)ft_strlen(game->map_data.map[game->camera.grid_y]))
		{
			game->camera.hit = 1;
			game->camera.vertical = 1000000000;
			game->camera.offset = 0;
			return ;
		}
		printf("%c\n", game->map_data.map[game->camera.grid_y][game->camera.grid_x]);
		if (game->map_data.map[game->camera.grid_y][game->camera.grid_x] == '1')
		{
			game->camera.hit = 1;
			game->camera.vertical = sqrt(pow(x - game->player.x, 2)
				+ pow(aux - game->player.y, 2));
			game->camera.offset = 0;
			return ;
		}
		else
			game->camera.x -= 64;
	}
	game->camera.ya = WALL_SIZE * tan(game->camera.direction);
}

t_game	*set_starting_camvalues(t_game *game)
{
	game->camera.x = game->player.x;
	game->camera.y = game->player.y;
	game->camera.xa = 0;
	game->camera.ya = 0;
	game->camera.grid_x = game->camera.x;
	game->camera.grid_y = game->camera.y;
	game->camera.hit = 0;
	return (game);
}

void	check_next_square(t_game *game)
{
	game->camera.inter_y = 64 / sin(game->camera.direction);
	game->camera.inter_x = 64 / cos(game->camera.direction);
	while (game->camera.hit != 1)
		check_horizontal_lines(game);
	game = set_starting_camvalues(game);
	while (game->camera.hit != 1)
		check_vertical_lines(game);
	if (game->camera.horizontal < game->camera.vertical)
		game->camera.distance = game->camera.horizontal;
	else
		game->camera.distance = game->camera.vertical;
	printf("dist %f\n", game->camera.distance);
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
