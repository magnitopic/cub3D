/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 09:18:28 by alaparic          #+#    #+#             */
/*   Updated: 2023/10/11 13:02:05 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	ft_check_chars(t_game *game, char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] != '1' && map[y][x] != '0' && map[y][x] != 'N' &&
				map[y][x] != 'S' && map[y][x] != 'E' && map[y][x] != 'W' &&
				map[y][x] != ' ')
				raise_error("Invalid value found in map");
			if (map[y][x] == 'N' || map[y][x] == 'S' || map[y][x] == 'E' ||
				map[y][x] == 'W')
			{
				game->player.y = x * WALL_SIZE;
				game->camera.grid_y = y;
				game->player.x = y * WALL_SIZE;
				game->camera.grid_x = x;
			}
			x++;
		}
		y++;
	}
}

void	check_map(t_game *game, char **map)
{
	ft_printmatrix(map);
	ft_check_chars(game, map);
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
