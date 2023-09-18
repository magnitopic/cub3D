/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:35:00 by jsarabia          #+#    #+#             */
/*   Updated: 2023/09/18 12:49:11 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	set_graphics(t_game *game)
{
	game->img.img = mlx_new_image(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bpp, &game->img.line_length,&game->img.endian);
	//ft_memcpy(game->img.addr, "sfv5sfv5sfv5sfv5sfv5sfv5sfv5sfv5sfv5sfv5sfv5sfv5sfv5sfv5sfv5sfv5", 16*4);
	//mlx_put_image_to_window(game->mlx, game->win, game->img.img, 10, 10);
	draw_ceiling_floor(game);
}

void	run_game(t_game *game, char *map_name)
{
	char	*name_aux;

	name_aux = ft_strjoin(PROGRAM_NAME, map_name);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, name_aux);
	free(name_aux);
	set_graphics(game);
	mlx_hook(game->win, 17, 0, exit_game, game);
	mlx_hook(game->win, 2, 1L << 0, event_handler, game);
	mlx_loop(game->mlx);
}
