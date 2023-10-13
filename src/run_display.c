/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:35:00 by jsarabia          #+#    #+#             */
/*   Updated: 2023/10/13 18:01:52 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	create_textures(t_game *game)
{
	printf("%s\n", game->map_data.texture_ea);
	printf("%s\n", game->map_data.texture_no);
	printf("%s\n", game->map_data.texture_so);
	printf("%s\n", game->map_data.texture_we);
	game->textu_n.img.img = mlx_xpm_file_to_image(game->mlx, game->map_data.texture_no, 
		&game->textu_n.img.width, &game->textu_n.img.height);
	game->textu_s.img.img = mlx_xpm_file_to_image(game->mlx, game->map_data.texture_so, 
		&game->textu_s.img.width, &game->textu_s.img.height);
	game->textu_w.img.img = mlx_xpm_file_to_image(game->mlx, game->map_data.texture_we, 
		&game->textu_w.img.width, &game->textu_w.img.height);
	game->textu_e.img.img = mlx_xpm_file_to_image(game->mlx, game->map_data.texture_ea, 
		&game->textu_e.img.width, &game->textu_e.img.height);
	if (!game->textu_n.img.img || !game->textu_s.img.img || !game->textu_w.img.img
		|| !game->textu_e.img.img)
		perror("malloc") ;
}

static void	load_textures(t_game *game)
{
	create_textures(game);
	game->textu_n.text_value = (int *)mlx_get_data_addr(game->textu_n.img.img,
	&game->textu_n.img.bpp, &game->textu_n.img.line_len, &game->textu_n.img.endian);
	game->textu_s.text_value = (int *)mlx_get_data_addr(game->textu_s.img.img,
	&game->textu_s.img.bpp, &game->textu_s.img.line_len, &game->textu_s.img.endian);
	game->textu_e.text_value = (int *)mlx_get_data_addr(game->textu_e.img.img,
	&game->textu_e.img.bpp, &game->textu_e.img.line_len, &game->textu_e.img.endian);
	game->textu_w.text_value = (int *)mlx_get_data_addr(game->textu_w.img.img,
	&game->textu_w.img.bpp, &game->textu_w.img.line_len, &game->textu_w.img.endian);
}

void	set_graphics(t_game *game)
{
	game->img.img = mlx_new_image(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bpp,
			&game->img.line_len, &game->img.endian);
	draw_ceiling_floor(game, game->map_data.ceiling, game->map_data.floor);
}

void	run_game(t_game *game, char *map_name)
{
	char	*aux;

	aux = ft_strjoin(PROGRAM_NAME, map_name);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, aux);
	free(aux);
	set_graphics(game);
	load_textures(game);
	start_game(game);
	mlx_hook(game->win, 17, 0, exit_game, game);
	mlx_hook(game->win, 2, 1L << 0, event_handler, game);
	mlx_loop(game->mlx);
}
