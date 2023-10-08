/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 18:42:16 by jsarabia          #+#    #+#             */
/*   Updated: 2023/10/08 14:02:51 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"
// WALL_SIZE is 64 in the tutorial, we should decide how big we want our walls


/* static double	check_horizontal_lines(t_game *game)
{
	t_vector	curr_point;
	t_vector	prev_point;
	int			ya;
	int			xa;

	ya = WALL_SIZE;
	if (game->camera.direction < PI)
	{
		curr_point.y = (int)floor(game->player.y / WALL_SIZE) * WALL_SIZE - 1;
		ya = -WALL_SIZE;
	}
	else
		curr_point.y = (int)floor(game->player.y / WALL_SIZE) * WALL_SIZE
			+ WALL_SIZE;
	curr_point.x = game->player.x + (game->player.y - curr_point.y)
		/ tan(game->player.direction);
	xa = WALL_SIZE / tan(game->player.direction);
	while (!(game->map_data.map[(int)curr_point.y / 64][(int)curr_point.x / 64]))
	{
		prev_point = curr_point;
		curr_point.y = prev_point.y + ya;
		curr_point.x = prev_point.x + xa;
	}
	return (sqrt(pow(game->player.x - curr_point.x, 2)
			+ pow(game->player.y - curr_point.y, 2)));
} */

/* static double	check_vertical_lines(t_game *game)
{
	t_vector	curr_point;
	t_vector	prev_point;
	int			ya;
	int			xa;

	xa = WALL_SIZE;
	if (game->camera.direction < PI)
	{
		curr_point.x = (int)floor(game->player.x / WALL_SIZE) * WALL_SIZE
			+ WALL_SIZE;
		xa = -WALL_SIZE;
	}
	else
		curr_point.x = (int)floor(game->player.x / WALL_SIZE) * WALL_SIZE - 1;
	ya = WALL_SIZE / tan(game->player.direction);
	curr_point.y = game->player.y + (game->player.x - curr_point.x)
		/ tan(game->player.direction);
	while (!(game->map_data.map[(int)curr_point.y / 64][(int)curr_point.x / 64]))
	{
		prev_point = curr_point;
		curr_point.y = prev_point.y + ya;
		curr_point.x = prev_point.x + xa;
	}
	return (sqrt(pow(game->player.x - curr_point.x, 2)
			+ pow(game->player.y - curr_point.y, 2)));
} */


void imageDraw(t_game *game)
{
    for (int y = 0; y < SCREEN_HEIGHT; y++)
        for (int x = 0; x < SCREEN_WIDTH; x++)
            game->img.addr[y * SCREEN_WIDTH + x] = game->buf[y][x];

    mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
}


/**
 * Player FOV will be 60
*/
void	check_ray_direction(t_vector rayDirection, t_rays *rays, t_game *game, int mapx, int mapy)
{
	if (rayDirection.x < 0)
	{
		rays->step.x = -1;
		rays->side_dist.x = (game->player.x - mapx) * rays->delta_dist.x;
	}
	else
	{
		rays->step.x = 1;
		rays->side_dist.x = (mapx + 1.0 - game->player.x) * rays->delta_dist.x;
	}
	if (rayDirection.y < 0)
	{
		rays->step.y = -1;
		rays->side_dist.y = (game->player.y - mapy) * rays->delta_dist.y;
	}
	else
	{
		rays->step.y = 1;
		rays->side_dist.y = (mapy + 1.0 - game->player.y) * rays->delta_dist.y;
	}
}

void	load_image(t_game *game, int *texture, char *path, t_img *img)
{
	(void)img;
	game->img.img = mlx_xpm_file_to_image(game->mlx, path, &game->img.img_width, &game->img.img_height);
	game->img.addr = (int *)mlx_get_data_addr(game->img.img, &game->img.bpp,
			&game->img.line_len, &game->img.endian);
	for (int y = 0; y < game->img.img_height; y++)
	{
		for (int x = 0; x < game->img.img_width; x++)
		{
			texture[game->img.img_width * y + x] = game->img.addr[game->img.img_width * y + x];
		}
	}
}

void	raycasting(t_game *game)
{
	int		i;
	t_rays	*rays = malloc(sizeof(t_rays));

	i = 0;
	while (i < SCREEN_WIDTH)
	{
		double cameraX = (2 * i / (double)(SCREEN_WIDTH)) - 1;
		t_vector	rayDirection;
		rayDirection.x = game->player.direction.x + game->plane.x * cameraX;
		rayDirection.y = game->player.direction.y + game->plane.y * cameraX;
		int	mapx = (int)(game->player.x) / WALL_SIZE;
		int	mapy = (int)(game->player.y) / WALL_SIZE;
		rays->delta_dist.x = fabs(1 / rayDirection.x);
		rays->delta_dist.y = fabs(1 / rayDirection.y);
		double perpWallDist;
		int hit = 0;
		int side;
		
		check_ray_direction(rayDirection, rays, game, mapx, mapy);
		printf("Side_sitX: %f\n", rays->side_dist.x);
		printf("SideDistY: %f\n", rays->side_dist.y);
		while (hit == 0)
		{
			if (rays->side_dist.x < rays->side_dist.y)
			{
				rays->side_dist.x += rays->delta_dist.x;
				mapx += rays->step.x;
				side = 0;
			}
			else
			{
				rays->side_dist.y += rays->delta_dist.y;
				mapy += rays->step.y;
				side = 1;
			}
			if (game->map_data.map[mapy][mapx] == '1')
			{
				hit = 1;
				printf("x: %d y: %d\n", mapx, mapy);
			}
		}
		if (side == 0)
			perpWallDist = (mapx - (game->player.x / WALL_SIZE) + (1 - rays->step.x) / 2) / rayDirection.x;
		else
			perpWallDist = (mapy - (game->player.y / WALL_SIZE) + (1 - rays->step.y) / 2) / rayDirection.y;

		int lineHeight = (int)(SCREEN_HEIGHT / perpWallDist);

		int drawStart = (-1 * lineHeight / 2) + (SCREEN_HEIGHT / 2);
		if (drawStart < 0)
			drawStart = 0;
		int drawEnd = (lineHeight / 2) * (SCREEN_HEIGHT / 2);
		if (drawEnd >= SCREEN_HEIGHT)
			drawEnd = SCREEN_HEIGHT - 1;
		printf("distance: %d\n", lineHeight / 64);
		game->camera.distance = lineHeight;
		ft_draw_wall(game, i);

		printf("_______________________________________\n");
		i++;
	}
}
