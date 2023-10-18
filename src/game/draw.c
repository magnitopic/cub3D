/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 10:01:04 by alaparic          #+#    #+#             */
/*   Updated: 2023/10/18 15:46:13 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static void	calculate_hit_pos(t_game *game, int start)
{
	if (game->camera.offset == 0)
		game->camera.wallx = game->player.y + game->camera.distance
			* game->camera.raydiry;
	else
		game->camera.wallx = game->player.x + game->camera.distance
			* game->camera.raydirx;
	game->camera.wallx -= floor(game->camera.wallx);
	game->camera.textx = (int)(game->camera.wallx * (double)(WALL_SIZE));
	if (game->camera.offset == 0 && game->camera.raydirx > 0)
		game->camera.textx =  WALL_SIZE -game->camera.textx - 1;
	if (game->camera.offset == 1 && game->camera.raydiry > 0)
		game->camera.textx =  WALL_SIZE -game->camera.textx - 1;
	game->camera.increase = 1.0 * WALL_SIZE / game->camera.lineheight;
	game->camera.textpos = (start - SCREEN_HEIGHT / 2 + game->camera.lineheight
			/ 2) * game->camera.increase;
}

static void	ft_draw_wall(t_game *game)
{
	static int	x = 0;
	int			start;
	int			end;
	int			texcolor;

	game->camera.lineheight = (int)(SCREEN_HEIGHT / game->camera.distance);
	start = -game->camera.lineheight / 2 + SCREEN_HEIGHT / 2;
	if (x == SCREEN_WIDTH)
		x = 0;
	if (start < 0)
		start = 0;
	end = SCREEN_HEIGHT / 2 + game->camera.lineheight / 2;
	if (end >= SCREEN_HEIGHT)
		end = SCREEN_HEIGHT - 1;
	calculate_hit_pos(game, start);
	while (start < end)
	{
		game->camera.texty = (int)game->camera.textpos & (WALL_SIZE - 1);
		game->camera.textpos += game->camera.increase;
		if (game->camera.offset == 0)
		{
			if (game->camera.raydirx < 0)
				texcolor = game->textu_n.text_value[(int)(WALL_SIZE * game->camera.texty + game->camera.textx)];
			else
				texcolor = game->textu_s.text_value[(int)(WALL_SIZE * game->camera.texty + game->camera.textx)];
		}
		else
		{
			if (game->camera.raydiry < 0)
				texcolor = game->textu_w.text_value[(int)(WALL_SIZE * game->camera.texty + game->camera.textx)];
			else
				texcolor = game->textu_e.text_value[(int)(WALL_SIZE * game->camera.texty + game->camera.textx)];
		}
		//mlx_pixel_put(game->mlx, game->win, x, start, texcolor);
		ft_put_pixel(game->img, x, start, texcolor);
		// TODO: Add shadows to side
		start++;
	}
	x++;
}

static void	draw_ceiling_floor(t_game *game, t_color ceiling, t_color floor)
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
				ft_put_pixel(game->img, x, y, ft_rgba(floor.red, floor.green,
						floor.blue, 0));
			else
				ft_put_pixel(game->img, x, y, ft_rgba(ceiling.red,
						ceiling.green, ceiling.blue, 0));
		}
	}
}

static void	ft_put_pixel(t_img img, int x, int y, int color)
{
	if (x >= 0 && y >= 0 && x < SCREEN_WIDTH && y < SCREEN_HEIGHT)
		*(int *)&img.addr[((x * img.bpp) >> 3) + (y * img.line_len)] = color;
}

/**
 * At the start of the game and when any movement key is pressed the screen is
 * re-drawn.
 * 
 * First the floor and ceiling is drawn. Half of the screen will be drawn the
 * ceiling colour and the other half will be the floor color, since the walls
 * will be drawn from the middle it'll give the illusion of floor and ceiling.
 * 
 * Next Raycasging will do all the necessary calculations to mesure the distance
 * to each wall.
 * 
 * The that distance will determine the height of each segment of wall and we'll
 * draw them accordingly.
 * 
 * Finally the with every pixel placed in the image, it is put on the screen.
*/
void	re_draw_screen(t_game *game)
{
	draw_ceiling_floor(game, game->map_data.ceiling, game->map_data.floor);
	raycasting(game);
	ft_draw_wall(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
}
