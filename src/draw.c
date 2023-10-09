/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 10:01:04 by alaparic          #+#    #+#             */
/*   Updated: 2023/10/06 10:29:19 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

// ! Bugged function
void	ft_put_pixel(t_img img, int x, int y, t_color rgb)
{
	int		color;

	color = ft_rgba(rgb.red, rgb.green, rgb.blue, 0);
	if (x >= 0 && y >= 0 && x < SCREEN_WIDTH && y < SCREEN_HEIGHT)
		*(int *)&img.addr[((x * img.bpp) >> 3) + (y * img.line_len)] = color;
}

void	ft_draw_wall(t_game *game, int x, int side)
{
	int			y;

	int drawStart = (-game->camera.distance / 2) + (SCREEN_HEIGHT / 2);
	if (drawStart < 0)
		drawStart = 0;
	int drawEnd = (game->camera.distance / 2) + (SCREEN_HEIGHT / 2);
	if (drawEnd >= SCREEN_HEIGHT)
		drawEnd = SCREEN_HEIGHT - 1;
	y = drawStart;
	while (y != drawEnd)
	{
		int color = 0xffffff;
		if (side == 1)
			color = (color >> 1) & 8355711;
		mlx_pixel_put(game->mlx, game->win, x, y, color);
		y++;
	}
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
			{
				//ft_put_pixel(game->img, x, y, floor);
				mlx_pixel_put(game->mlx, game->win, x, y, ft_rgba(ceiling.red, ceiling.green, ceiling.blue, 0));
			}
			else
			{
				//ft_put_pixel(game->img, x, y, ceiling);
				mlx_pixel_put(game->mlx, game->win, x, y, ft_rgba(floor.red, floor.green, floor.blue, 0));
			}
		}
	}
	//mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
}

void	draw_screen(t_game *game)
{
	draw_ceiling_floor(game, game->map_data.ceiling, game->map_data.floor);
	raycasting(game);
	minimap(game, game->map_data.map);
}
