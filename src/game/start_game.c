/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:35:00 by jsarabia          #+#    #+#             */
/*   Updated: 2023/10/18 19:05:09 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static void	get_player_direction(t_game *game)
{
	if (game->map[(int)game->player.x / WALL_SIZE][(int)game->player.y / WALL_SIZE] == 'W')
	{
		game->cam.plane.x = -0.66;
		game->cam.plane.y = 0;
		game->player.dir.x = 0;
		game->player.dir.y = -1;
	}
	if (game->map[(int)game->player.x / WALL_SIZE][(int)game->player.y / WALL_SIZE] == 'S')
	{
		game->cam.plane.y = -0.66;
		game->cam.plane.x = 0;
		game->player.dir.x = 1;
		game->player.dir.y = 0;
	}
	if (game->map[(int)game->player.x / WALL_SIZE][(int)game->player.y / WALL_SIZE] == 'N')
	{
		game->cam.plane.y = 0.66;
		game->cam.plane.x = 0;
		game->player.dir.x = -1;
		game->player.dir.y = 0;
	}
	if (game->map[(int)game->player.x / WALL_SIZE][(int)game->player.y / WALL_SIZE] == 'E')
	{
		game->cam.plane.x = 0.66;
		game->cam.plane.y = 0;
		game->player.dir.x = 0;
		game->player.dir.y = 1;
	}
}

static void	allocate_buffer(t_game *game)
{
	int	i;

	i = 0;
	game->cam.buffer = malloc(WALL_SIZE * sizeof(int *));
	if (!game->cam.buffer)
		exit(1);
	while (i < WALL_SIZE)
	{
		game->cam.buffer[i] = malloc(WALL_SIZE * sizeof(int));
		if (!game->cam.buffer[i])
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
	start_img(game);
	create_textures(game);
	allocate_buffer(game);
	get_player_direction(game);
	re_draw_screen(game);
	mlx_hook(game->win, 17, 0, exit_game, game);
	mlx_hook(game->win, 2, 1L << 0, event_handler, game);
	mlx_loop(game->mlx);
}
