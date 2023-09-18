/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 10:01:04 by alaparic          #+#    #+#             */
/*   Updated: 2023/09/18 12:50:38 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	draw_ceiling_floor(t_game *game)
{
	int	y;
	int	x;

	y = -1;
	while (y++ < SCREEN_HEIGHT)
	{
		x = -1;
		while (x++ < SCREEN_WIDTH)
		{
			if (y < SCREEN_HEIGHT / 2)
				mlx_pixel_put(game->mlx, game->win, x, y, ft_rgba(0, 0, 255, 0));
			else
				mlx_pixel_put(game->mlx, game->win, x, y, ft_rgba(255, 255, 0, 0));
		}
	}
	//mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
}
