/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 18:42:16 by jsarabia          #+#    #+#             */
/*   Updated: 2023/09/26 14:47:02 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	check_vertical_lines(t_game *game)
{
	
}

void	check_horizontal_lines(t_game *game)
{
	
}

void	raycasting(t_game *game)
{
	int	rays;

	rays = 1;
	while (rays-- > 0){
		check_horizontal_lines(game);
		check_vertical_lines(game);
	}
}
