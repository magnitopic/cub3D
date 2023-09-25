/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 09:18:28 by alaparic          #+#    #+#             */
/*   Updated: 2023/09/25 10:06:38 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	ft_check_chars(char **map)
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
			{
				printf("|%c|", map[y][x]);
				raise_error("Invalid value found in map");
			}
			x++;
		}
		y++;
	}
}

void	check_map(char **map)
{
	ft_printmatrix(map);
	ft_check_chars(map);
}

void	parsing(char **argv, t_game *game)
{
	char	**file_content;
	char	**aux;

	file_content = read_file(argv);
	aux = file_content;
	get_values(game, file_content);
	file_content += 6;
	check_map(file_content);
	game->map_data.map = file_content;
	//free_matrix(aux);
}
