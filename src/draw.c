/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarabia <jsarabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 10:01:04 by alaparic          #+#    #+#             */
/*   Updated: 2023/09/18 14:44:53 by jsarabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

static int	*set_floor(t_game *game)
{
	int		i;
	int		*rgb;
	char	**spl;

	i = 0;
	rgb = ft_calloc(4, sizeof(int));
	while (game->map_data.map[i])
	{
		if (ft_strchr(game->map_data.map[i], 'F'))
		{
			spl = ft_split(ft_strchr(game->map_data.map[i], 'F') + 1, ',');
			rgb[0] = ft_atoi(spl[0]);
			rgb[1] = ft_atoi(spl[1]);
			rgb[2] = ft_atoi(spl[2]);
			free_matrix(spl);
			return (rgb);
		}
		i++;
	}
	rgb[2] = 255;
	return (rgb);
}

static int	*set_ceiling(t_game *game)
{
	int		i;
	int		*rgb;
	char	**spl;

	i = 0;
	rgb = ft_calloc(4, sizeof(int));
	while (game->map_data.map[i])
	{
		if (ft_strchr(game->map_data.map[i], 'C'))
		{
			spl = ft_split(ft_strchr(game->map_data.map[i], 'C') + 1, ',');
			rgb[0] = ft_atoi(spl[0]);
			rgb[1] = ft_atoi(spl[1]);
			rgb[2] = ft_atoi(spl[2]);
			free_matrix(spl);
			return (rgb);
		}
		i++;
	}
	rgb[1] = 50;
	rgb[2] = 100;
	return (rgb);
}

void	draw_ceiling_floor(t_game *game)
{
	int	y;
	int	x;
	int	*rgb;
	int	*cei;

	y = -1;
	cei = NULL;
	rgb = NULL;
	cei = set_ceiling(game);
	rgb = set_floor(game);
	while (y++ < SCREEN_HEIGHT)
	{
		x = -1;
		while (x++ < SCREEN_WIDTH)
		{
			if (y < SCREEN_HEIGHT / 2)
				mlx_pixel_put(game->mlx, game->win, x, y, ft_rgba(rgb[0], rgb[1], rgb[2], rgb[3]));
			else
				mlx_pixel_put(game->mlx, game->win, x, y, ft_rgba(cei[0], cei[1], cei[2], cei[3]));
		}
	}
	free(rgb);
	free(cei);
	//mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
}
