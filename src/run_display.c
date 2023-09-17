/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:35:00 by jsarabia          #+#    #+#             */
/*   Updated: 2023/09/17 13:15:01 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	set_graphics(t_game *game)
{
	t_texture	img;

	img.img = mlx_new_image(game->mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_length,
			&img.endian);
}

void	run_game(t_game *game, char *map_name)
{
	char	*name_aux;

	name_aux = ft_strjoin(PROGRAM_NAME, map_name);
	game->mlx = mlx_init();
	//game->win = mlx_new_window(game->mlx, 1920, 1080, name_aux);
	free(name_aux);
	set_graphics(game);
	mlx_hook(game->win, 17, 0, exit_game, game);
	mlx_hook(game->win, 2, 1L << 0, event_handler, game);
	//mlx_loop(game->mlx);
}
