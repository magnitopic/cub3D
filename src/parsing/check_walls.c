/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarabia <jsarabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:55:34 by jsarabia          #+#    #+#             */
/*   Updated: 2023/09/18 18:01:57 by jsarabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static void	check_line_closed(char **map)
{
	int		i;
	char	*aux;

	i = 6;
	aux = NULL;
	while (map[i])
	{
		aux = ft_strtrim(map[i], " ");
		if (aux[0] != '1')
		{
			free(aux);
			raise_error("The map is not closed by walls");
		}
		free(aux);
		if (map[i][ft_strlen(map[i]) - 1] != '1')
			raise_error("The map is not closed by walls");
		i++;
	}
}

static void	check_everything_closed(int *checker, int num, t_game *game)
{
	int	n;

	n = 0;
	while (n < map_width(game->map_data.map))
	{
		if (checker[n] != num)
		{
			free(checker);
			raise_error("The map is not correctly closed by walls");
		}
		n++;
	}
}

static int	*check_top_closed(int *checker, t_game *game)
{
	int	n;
	int	i;

	n = 6;
	i = 0;
	while (game->map_data.map[n])
	{
		while (game->map_data.map[n][i])
		{
			if (game->map_data.map[n][i] == '1')
				checker[i] = 1;
			else if (game->map_data.map[n][i] == '0' && checker[i] != 1)
			{
				free(checker);
				raise_error("The map in not correctly closed by walls");
			}
			i++;
		}
		i = 0;
		n++;
	}
	check_everything_closed(checker, 1, game);
	return (checker);
}

static void	check_bottom_closed(int *checker, t_game *game)
{
	int	n;
	int	i;

	n = ft_get_matrix_size(game->map_data.map) - 1;
	i = 0;
	while (n > 5)
	{
		while (game->map_data.map[n][i])
		{
			if (game->map_data.map[n][i] == '1')
				checker[i] = 0;
			else if (game->map_data.map[n][i] == '0' && checker[i] != 0)
			{
				free(checker);
				raise_error("The map in not correctly closed by walls");
			}
			i++;
		}
		i = 0;
		n--;
	}
	check_everything_closed(checker, 0, game);
}

void	check_walls(t_game *game)
{
	int	*checker;

	check_line_closed(game->map_data.map);
	checker = ft_calloc(map_width(game->map_data.map), sizeof(int));
	checker = check_top_closed(checker, game);
	check_bottom_closed(checker, game);
}
