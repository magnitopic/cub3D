/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 10:01:04 by alaparic          #+#    #+#             */
/*   Updated: 2023/09/18 10:20:31 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	draw_ceiling_floor(t_game *game)
{
	int	y;
	int	x;

	y = -1;
	while (y++ < SCREEN_WITH)
	{
		x = -1;
		while (x++ < SCREEN_HEIGHT)
		{
			
		}
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
}
