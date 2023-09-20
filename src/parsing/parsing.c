/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 09:18:28 by alaparic          #+#    #+#             */
/*   Updated: 2023/09/20 21:01:00 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void check_map(char **map)
{
	ft_printmatrix(map);
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
	free_matrix(aux);
}
