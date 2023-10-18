/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_closed_walls.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:01:20 by alaparic          #+#    #+#             */
/*   Updated: 2023/10/18 15:54:58 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static int	ft_get_longest_line(char **matrix)
{
	int	j;
	int	longest;

	longest = INT_MIN;
	while (*matrix)
	{
		j = 0;
		while ((*matrix)[j])
			j++;
		if (j > longest)
			longest = j;
		matrix++;
	}
	return (longest);
}

static void	add_og_map(char **map, char ***map_cpy)
{
	int	i;
	int	j;
	int	map_heigh;

	map_heigh = ft_get_matrix_size(map);
	i = 0;
	while (++i < map_heigh + 1)
	{
		j = 0;
		while (++j < (int)ft_strlen(map[i - 1]) + 1)
			(*map_cpy)[i][j] = map[i - 1][j - 1];
	}
}

static char	**get_map_cpy(char **map)
{
	int		i;
	int		j;
	int		map_heigh;
	int		map_width;
	char	**map_cpy;

	map_heigh = ft_get_matrix_size(map);
	map_width = ft_get_longest_line(map);
	map_cpy = ft_calloc(map_heigh + 3, sizeof(char *));
	if (!map_cpy)
		exit(1);
	i = -1;
	while (++i < map_heigh + 2)
	{
		map_cpy[i] = ft_calloc(map_width + 3, sizeof(char));
		if (!map_cpy[i])
			exit(1);
		j = -1;
		while (++j < map_width + 2)
			map_cpy[i][j] = ' ';
		map_cpy[i][j] = '\0';
	}
	map_cpy[i] = NULL;
	add_og_map(map, &map_cpy);
	return (map_cpy);
}

static void	check_walls(char **map_cpy)
{
	int	i;
	int	j;

	i = -1;
	while (++i < ft_get_matrix_size(map_cpy))
	{
		j = -1;
		while (++j < (int)ft_strlen(map_cpy[i]))
		{
			if (map_cpy[i][j] == '0' || map_cpy[i][j] == 'N' || map_cpy[i][j]
				== 'S' || map_cpy[i][j] == 'E' || map_cpy[i][j] == 'W')
			{
				if (map_cpy[i + 1][j] == ' ' || map_cpy[i - 1][j] == ' ' ||
					map_cpy[i][j + 1] == ' ' || map_cpy[i][j - 1] == ' ')
					raise_error("Map must not be open");
			}
		}
	}
}

void	check_closed_walls(char **map)
{
	char	**map_cpy;

	map_cpy = get_map_cpy(map);
	check_walls(map_cpy);
}
