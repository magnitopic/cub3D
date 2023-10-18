/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 09:18:28 by alaparic          #+#    #+#             */
/*   Updated: 2023/10/18 15:31:59 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static int	check_chars(t_game *game, char value, int x, int y)
{
	if (value != '1' && value != '0' && value != 'N'
		&& value != 'S' && value != 'E' && value != 'W' && value != ' ')
		raise_error("Invalid value found in map");
	if (value == 'N' || value == 'S' || value == 'E' || value == 'W')
	{
		game->player.y = (x * WALL_SIZE) + WALL_SIZE / 2;
		game->camera.grid_y = y;
		game->player.x = (y * WALL_SIZE) + WALL_SIZE / 2;
		game->camera.grid_x = x;
		return (1);
	}
	return (0);
}

static void	check_map_chars(t_game *game, char **map)
{
	int	x;
	int	y;
	int	player_flag;

	y = -1;
	player_flag = 0;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
			player_flag += check_chars(game, map[y][x], x, y);
	}
	if (player_flag > 1)
		raise_error("Mutiple players found");
	if (!player_flag)
		raise_error("No player position found");
}

void	parsing(char **argv, t_game *game)
{
	char	**file_content;
	char	**map;
	//char	**aux;

	file_content = read_file(argv);
	//aux = file_content;
	get_values(game, file_content);
	map = file_content + 6;
	check_map_chars(game, map);
	check_closed_walls(map);
	game->map_data.map = map;
	//free_matrix(aux);
}
