/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 11:52:55 by alaparic          #+#    #+#             */
/*   Updated: 2023/10/05 11:24:42 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static int	check_if_movement(t_game *game)
{
	if (game->map_data.map[(int)game->player.y / WALL_SIZE][(int)game->player.x / WALL_SIZE] == '1')
		return (0);
	if (game->map_data.map[((int)game->player.y + PLAYER_SIZE) / WALL_SIZE][((int)game->player.x + PLAYER_SIZE) / WALL_SIZE] == '1')
		return (0);
	return (1);
}

static void	draw_player(t_game *game, int color)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!check_if_movement(game))
	{
		game->player.x = game->player.old_x;
		game->player.y = game->player.old_y;
	}
	while (++i <= 3)
	{
		j = 0;
		while (++j <= 3)
			mlx_pixel_put(game->mlx, game->win, game->player.x / 64 * 5 + j, game->player.y / 64 * 5 + i, color);
	}
}

static void	draw_wall(int x, int y, t_game *game, int color)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (++i <= 5)
	{
		j = 0;
		while (++j <= 5)
			mlx_pixel_put(game->mlx, game->win, x + j, y + i, color);
	}
}

void	minimap(t_game *game, char **map)
{
	int	x;
	int	y;


	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == '1')
				draw_wall(x * 5, y * 5, game, ft_rgba(0, 0, 255, 0));
			else if (map[y][x] == '0' || map[y][x] == 'N' || map[y][x] == 'E'
				|| map[y][x] == 'W' || map[y][x] == 'S')
				draw_wall(x * 5, y * 5, game, ft_rgba(128, 128, 128, 0));
		}
	}
	draw_player(game, ft_rgba(0, 255, 0, 0));
}
