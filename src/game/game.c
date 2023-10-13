/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarabia <jsarabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 11:52:46 by alaparic          #+#    #+#             */
/*   Updated: 2023/10/11 17:42:50 by jsarabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	get_player_direction(t_game *game)
{
	if (game->map_data.map[(int)game->player.x / WALL_SIZE][(int)game->player.y / WALL_SIZE] == 'W')
	{
		game->camera.plane.x = -0.66;
		game->camera.plane.y = 0;
		game->player.direction.x = 0;
		game->player.direction.y = -1;
	}
	if (game->map_data.map[(int)game->player.x / WALL_SIZE][(int)game->player.y / WALL_SIZE] == 'S')
	{
		game->camera.plane.y = -0.66;
		game->camera.plane.x = 0;
		game->player.direction.x = 1;
		game->player.direction.y = 0;
	}
	if (game->map_data.map[(int)game->player.x / WALL_SIZE][(int)game->player.y / WALL_SIZE] == 'N')
	{
		game->camera.plane.y = 0.66;
		game->camera.plane.x = 0;
		game->player.direction.x = -1;
		game->player.direction.y = 0;
	}
	if (game->map_data.map[(int)game->player.x / WALL_SIZE][(int)game->player.y / WALL_SIZE] == 'E')
	{
		game->camera.plane.x = 0.66;
		game->camera.plane.y = 0;
		game->player.direction.x = 0;
		game->player.direction.y = 1;
	}
}

void	free_matrix_int(int **matrix)
{
	int	i;

	i = 0;
	while (matrix[i] != NULL)
	{
		printf("%d\n", i);
		free(matrix[i]);
		printf("%d\n", i);
		i++;
	}
	free(matrix);
}

void	start_game(t_game *game)
{
	int	i;

	i = 0;
	get_player_direction(game);
	game->player.x += WALL_SIZE / 2;
	game->player.y += WALL_SIZE / 2;
	game->camera.buffer = malloc(WALL_SIZE * sizeof(int *));
	if (!game->camera.buffer)
		return ;
	while (i < WALL_SIZE)
	{
		game->camera.buffer[i] = malloc(WALL_SIZE * sizeof(int));
		if (!game->camera.buffer[i])
		{
			free_matrix_int(game->camera.buffer);
			return ;
		}
		i++;
	}
	raycasting(game);
}
