/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarabia <jsarabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 09:18:28 by alaparic          #+#    #+#             */
/*   Updated: 2023/09/26 16:00:01 by jsarabia         ###   ########.fr       */
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
				game->player.x = x * WALL_SIZE;
				game->player.y = y * WALL_SIZE;
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

static int	set_max_x(char **map)
{
	int	n;
	int	len;

	n = 0;
	len = 0;
	while (map[n])
	{
		if ((int)ft_strlen(map[n]) > len)
			len = ft_strlen(map[n]);
		n++;
	}
	return (len);
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
	game->map_data.max_x = set_max_x(game->map_data.map);
	game->map_data.max_y = ft_get_matrix_size(game->map_data.map);
	//free_matrix(aux);
}
