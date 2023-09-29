/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarabia <jsarabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 09:00:07 by alaparic          #+#    #+#             */
/*   Updated: 2023/09/29 17:26:40 by jsarabia         ###   ########.fr       */
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

	if (game->camera.direction < PI)
	{
		curr_point.y = (int)floor(game->player.y / WALL_SIZE) * WALL_SIZE - 1;
		ya = -WALL_SIZE;
	}
	else
	{
		curr_point.y = (int)floor(game->player.y / WALL_SIZE) * WALL_SIZE
			+ WALL_SIZE;
		ya = WALL_SIZE;
	}
	xa = WALL_SIZE / tan(game->player.direction);
	while (game->map_data.map[curr_point.x][curr_point.y] != '1')
	{
		prev_point = curr_point;
		curr_point.y = prev_point.y + ya;
		curr_point.x = prev_point.x + xa;
	}
	printf("Found a horizontal wall\n");	// TODO: remove
	return (sqrt(pow(game->player.x - curr_point.x, 2)
			+ pow(game->player.y - curr_point.y, 2)));
}

static double	check_vertical_lines(t_game *game)
{
	t_vector	curr_point;
	t_vector	prev_point;
	int			ya;
	int			xa;

	if (game->camera.direction < 2 * PI / 3 && game->camera.direction > PI) //facing up
	{
		curr_point.x = (int)floor(game->player.x / WALL_SIZE) * WALL_SIZE
			+ WALL_SIZE;
		xa = -WALL_SIZE;
	}
	else
	{
		curr_point.x = (int)floor(game->player.x / WALL_SIZE) * WALL_SIZE - 1;
		xa = WALL_SIZE;
	}
	ya = WALL_SIZE / tan(game->player.direction);
	while (game->map_data.map[curr_point.x][curr_point.y] != '1')
	{
		prev_point = curr_point;
		curr_point.y = prev_point.y + ya;
		curr_point.x = prev_point.x + xa;
	}
	printf("Found a vertical wall\n");		// TODO: remove
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
	while (game->camera.fov < 60)
	{
		h_distance = check_horizontal_lines(game);
		v_distance = check_vertical_lines(game);
		game->camera.distance = v_distance;
		if (h_distance < v_distance)
			game->camera.distance = h_distance;
		ft_draw_wall(game);
		game->camera.fov += 0.03125;
	}
}
