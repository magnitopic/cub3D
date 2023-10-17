/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 09:18:28 by alaparic          #+#    #+#             */
/*   Updated: 2023/10/17 12:01:30 by alaparic         ###   ########.fr       */
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
		game->player.y = x * WALL_SIZE;
		game->camera.grid_y = y;
		game->player.x = y * WALL_SIZE;
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

void	check_map(t_game *game, char **map)
{
	ft_printmatrix(map);
	check_map_chars(game, map);
	check_closed_walls(game, map);
}

void	parsing(char **argv, t_game *game)
{
	char	**file_content;
	//char	**aux;

	file_content = read_file(argv);
	//aux = file_content;
	get_values(game, file_content);
	file_content += 6;
	check_map(game, file_content);
	game->map_data.map = file_content;
	//free_matrix(aux);
}
