/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarabia <jsarabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 18:42:16 by jsarabia          #+#    #+#             */
/*   Updated: 2023/09/26 17:34:18 by jsarabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

/*void	check_vertical_lines(t_game *game)
{

}*/

void	check_horizontal_lines(t_game *game)
{
	game->camera.dof = 0;
	game->camera.angle_tan = -1 / tan(game->camera.ray_angle);
	if (game->camera.angle_tan > PI)
	{
		game->camera.ray_y = ((int)game->player.y / WALL_SIZE) * WALL_SIZE
			- 0.0001;
		game->camera.ray_x = game->player.y - game->camera.ray_y
			* game->camera.angle_tan + game->player.x;
		game->camera.y_offset = WALL_SIZE * (-1);
		game->camera.x_offset = game->camera.y_offset * game->camera.angle_tan;
	}
	if (game->camera.angle_tan < PI)
	{
		game->camera.ray_y = ((int)game->player.y / WALL_SIZE) * WALL_SIZE
			+ WALL_SIZE;
		game->camera.ray_x = game->player.y - game->camera.ray_y
			* game->camera.angle_tan + game->player.x;
		game->camera.y_offset = WALL_SIZE;
		game->camera.x_offset = game->camera.y_offset * game->camera.angle_tan;
	}
	if (game->camera.angle_tan == PI || game->camera.angle_tan == 0)
	{
		game->camera.ray_x = game->player.x;
		game->camera.ray_y = game->player.y;
		game->camera.dof = 8;
	}
	while (game->camera.dof != 8)
	{
		game->camera.max_x = (int)game->camera.ray_x / WALL_SIZE;
		game->camera.max_y = (int)game->camera.ray_y / WALL_SIZE;
		game->camera.map_pos = game->camera.max_y * game->map_data.max_x
			- game->camera.max_x;
		if (game->camera.map_pos < game->map_data.max_x * game->map_data.max_y
			&& game->map_data.map[game->camera.map_pos / game->map_data.max_x][game->camera.map_pos % game->map_data.max_x] == '1')
				game->camera.dof = 8;
		else
		{
			game->camera.ray_x += game->camera.x_offset;
			game->camera.ray_y += game->camera.y_offset;
			game->camera.dof += 1;
		}
	}
	//ft_printf("%d, %d\n", game->camera.ray_x, game->camera.ray_y);
}

void	raycasting(t_game *game)
{
	int	rays;

	rays = 1;
	game->camera.ray_angle = game->player.direction;
	while (rays-- > 0)
	{
		check_horizontal_lines(game);
		//check_vertical_lines(game);
	}
}
