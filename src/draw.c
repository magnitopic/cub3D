/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 10:01:04 by alaparic          #+#    #+#             */
/*   Updated: 2023/09/21 08:00:07 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	ft_put_pixel(t_img img, int x, int y, t_color rgb)
{
	int		color;
	char	*pixel;


	color = ft_rgba(rgb.red, rgb.green, rgb.blue, 0);
	pixel = img.addr + (y * img.line_len + x * (img.bpp / 8));
	*(int *)pixel = color;
}

void	draw_ceiling_floor(t_game *game, t_color ceiling, t_color floor)
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
				ft_put_pixel(game->img, x, y, floor);
			else
				ft_put_pixel(game->img, x, y, ceiling);
		}
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
}
