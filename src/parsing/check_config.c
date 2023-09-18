/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarabia <jsarabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 18:48:04 by jsarabia          #+#    #+#             */
/*   Updated: 2023/09/18 18:55:54 by jsarabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static void	check_coords(char **matrix, int n, t_game *game)
{
	int	i;

	i = ft_get_matrix_size(matrix);
	if (i > n)
	{
		free(matrix);
		raise_error("The configuration is invalid");
		(void)game;
	}
}

void	check_config(t_game *game)
{
	char	**spl;

	spl = ft_split(game->map_data.map[0], ' ');
	check_coords(spl, 2, game); //TODO: hacer una función que además te chequee los permisos que tiene de las imágenes y de las texturas
	free_matrix(spl);
	spl = ft_split(game->map_data.map[1], ' ');
	check_coords(spl, 2, game);
	free_matrix(spl);
	spl = ft_split(game->map_data.map[2], ' ');
	check_coords(spl, 2, game);
	free_matrix(spl);
	spl = ft_split(game->map_data.map[3], ' ');
	check_coords(spl, 2, game);
	free_matrix(spl);
	spl = ft_split(ft_strchr(game->map_data.map[4], 'F') + 1, ',');
	check_coords(spl, 3, game);
	free_matrix(spl);
	spl = ft_split(ft_strchr(game->map_data.map[5], 'C') + 1, ',');
	check_coords(spl, 3, game);
}
