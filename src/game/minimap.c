/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 11:52:55 by alaparic          #+#    #+#             */
/*   Updated: 2023/09/25 12:49:40 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

#define WALL_SIZE 20
#define PLAYER_SIZE WALL_SIZE/3

static void	draw_player(int x, int y, t_game *game, int color)
{
	int	i;
	int	j;

	i = 0;
	while (++i <= PLAYER_SIZE)
	{
		j = 0;
		while (++j <= PLAYER_SIZE)
		{
			mlx_pixel_put(game->mlx, game->win, x + j, y + i, color);
		}
	}
}

static void	draw_wall(int x, int y, t_game *game, int color)
{
	int	i;
	int	j;

	i = 0;
	while (++i <= WALL_SIZE)
	{
		j = 0;
		while (++j <= WALL_SIZE)
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
				draw_wall(x * WALL_SIZE, y * WALL_SIZE, game, ft_rgba(0, 0, 255, 0));
			else if (map[y][x] == '0')
				draw_wall(x * WALL_SIZE, y * WALL_SIZE, game, ft_rgba(128, 128, 128, 0));
		}
	}
	draw_wall(x * WALL_SIZE, y * WALL_SIZE, game, ft_rgba(128, 128, 128, 0));
	draw_player(x * WALL_SIZE, y * WALL_SIZE, game, ft_rgba(0, 255, 0, 0));
}
