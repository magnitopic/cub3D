/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:35:00 by jsarabia          #+#    #+#             */
/*   Updated: 2023/10/18 15:43:00 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static void	get_player_direction(t_game *game)
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

static void	allocate_buffer(t_game *game)
{
	int	i;

	i = 0;
	game->camera.buffer = malloc(WALL_SIZE * sizeof(int *));
	if (!game->camera.buffer)
		exit(1);
	while (i < WALL_SIZE)
	{
		game->camera.buffer[i] = malloc(WALL_SIZE * sizeof(int));
		if (!game->camera.buffer[i])
			exit(1);
		i++;
	}
}

static void	start_img(t_game *game)
{
	game->img.img = mlx_new_image(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bpp,
			&game->img.line_len, &game->img.endian);
}

void	start_game(t_game *game, char *map_name)
{
	char	*aux;

	aux = ft_strjoin(PROGRAM_NAME, map_name);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, aux);
	free(aux);
	create_texture_imgs(game);
	get_player_direction(game);
	re_draw_screen(game);
	mlx_hook(game->win, 17, 0, exit_game, game);
	mlx_hook(game->win, 2, 1L << 0, event_handler, game);
	mlx_loop(game->mlx);
}
