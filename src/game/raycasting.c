/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarabia <jsarabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 18:42:16 by jsarabia          #+#    #+#             */
/*   Updated: 2023/10/02 18:27:43 by jsarabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	check_horizontal_lines(t_game *game)
{

}

void	check_vertical_lines(t_game *game)
{
	int		x;
	int		y;
	float	aux;

	if (game->camera.inter_x > 0)
	{
		x = game->camera.grid_x + 1;
		aux = game->camera.y + (game->camera.inter_x * sin(game->camera.direction));
		y = aux;
		if (game->map_data.map[y][x] == '1')
			game->camera.hit = 1;
		else
			game->camera.v_x += 64 - (game->player.x - (game->camera.grid_x * WALL_SIZE));
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
	printf("%f\n%f\n", game->camera.inter_y, game->camera.inter_x);
}

t_game	*set_starting_camvalues(t_game *game)
{
	game->camera.x = game->player.x / WALL_SIZE;
	game->camera.y = game->player.y / WALL_SIZE;
	game->camera.grid_x = game->camera.x;
	game->camera.grid_y = game->camera.y;
	game->camera.direction = game->player.direction + (PI / 6);
	game->camera.fov = 0;
	game->camera.hit = 0;
	return (game);
}

void	raycasting(t_game *game)
{
	game = set_starting_camvalues(game);
	while (game->camera.fov < 60)
	{
		if (game->camera.direction < 0)
			game->camera.direction += 2 * M_PI;
		if (game->camera.direction > 2 * M_PI)
			game->camera.direction -= 2 * M_PI;
		game->camera.dx = cos(game->camera.direction);
		game->camera.dy = sin(game->camera.direction);
		check_next_square(game);
		exit(0);
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
		game->camera.direction -= 0.00054541539;
		//game->camera.direction += 0.03125;
		game->camera.fov += 0.03125;
	}
	game->camera.direction = game->player.direction - (PI / 6);
}
