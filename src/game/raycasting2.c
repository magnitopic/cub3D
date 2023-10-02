/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 18:42:16 by alaparic          #+#    #+#             */
/*   Updated: 2023/10/02 09:45:29 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

// WALL_SIZE is 64 in the tutorial, we should decide how big we want our walls

static double	check_horizontal_lines(t_game *game)
{
	t_vector	curr_point;
	t_vector	prev_point;
	int			ya;
	int			xa;

	ya = WALL_SIZE;
	if (game->camera.direction < PI)
	{
		curr_point.y = (int)floor(game->player.y / WALL_SIZE) * WALL_SIZE - 1;
		ya = -WALL_SIZE;
	}
	else
		curr_point.y = (int)floor(game->player.y / WALL_SIZE) * WALL_SIZE
			+ WALL_SIZE;
	curr_point.x = game->player.x + (game->player.y - curr_point.y)
		/ tan(game->player.direction);
	xa = WALL_SIZE / tan(game->player.direction);
	while (!(game->map_data.map[curr_point.y / 64][curr_point.x / 64]))
	{
		prev_point = curr_point;
		curr_point.y = prev_point.y + ya;
		curr_point.x = prev_point.x + xa;
	}
	return (sqrt(pow(game->player.x - curr_point.x, 2)
			+ pow(game->player.y - curr_point.y, 2)));
}

static double	check_vertical_lines(t_game *game)
{
	t_vector	curr_point;
	t_vector	prev_point;
	int			ya;
	int			xa;

	xa = WALL_SIZE;
	if (game->camera.direction < PI)
	{
		curr_point.x = (int)floor(game->player.x / WALL_SIZE) * WALL_SIZE
			+ WALL_SIZE;
		xa = -WALL_SIZE;
	}
	else
		curr_point.x = (int)floor(game->player.x / WALL_SIZE) * WALL_SIZE - 1;
	ya = WALL_SIZE / tan(game->player.direction);
	curr_point.y = game->player.y + (game->player.x - curr_point.x)
		/ tan(game->player.direction);
	while (!(game->map_data.map[curr_point.y / 64][curr_point.x / 64]))
	{
		prev_point = curr_point;
		curr_point.y = prev_point.y + ya;
		curr_point.x = prev_point.x + xa;
	}
	return (sqrt(pow(game->player.x - curr_point.x, 2)
			+ pow(game->player.y - curr_point.y, 2)));
}

/**
 * Player FOV will be 60
*/
void	raycasting(t_game *game)
{
	float	v_distance;
	float	h_distance;

	game->camera.fov = 0;
	game->camera.direction = game->player.direction - (PI / 6);
	while (game->camera.fov < 60)
	{
		h_distance = check_horizontal_lines(game);
		v_distance = check_vertical_lines(game);
		game->camera.distance = v_distance;
		if (h_distance < v_distance)
			game->camera.distance = h_distance;
		ft_draw_wall(game);
		game->camera.direction += 0.00054541539;
		game->camera.fov += 0.03125;
	}
}
