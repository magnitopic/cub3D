/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:57:14 by alaparic          #+#    #+#             */
/*   Updated: 2023/10/18 15:42:32 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static void	add_textures_to_imgs(t_game *game)
{
	game->textu_n.img.img = mlx_xpm_file_to_image(game->mlx, game->map_data
			.texture_no, &game->textu_n.img.width, &game->textu_n.img.height);
	game->textu_s.img.img = mlx_xpm_file_to_image(game->mlx, game->map_data
			.texture_so, &game->textu_s.img.width, &game->textu_s.img.height);
	game->textu_w.img.img = mlx_xpm_file_to_image(game->mlx, game->map_data
			.texture_we, &game->textu_w.img.width, &game->textu_w.img.height);
	game->textu_e.img.img = mlx_xpm_file_to_image(game->mlx, game->map_data
			.texture_ea, &game->textu_e.img.width, &game->textu_e.img.height);
	if (!game->textu_n.img.img || !game->textu_s.img.img
		|| !game->textu_w.img.img || !game->textu_e.img.img)
		raise_error("Path to textures does not exist or cannot be accessed");
}

void	create_texture_imgs(t_game *game)
{
	game->textu_n.text_value = (int *)mlx_get_data_addr(game->textu_n.img.img,
			&game->textu_n.img.bpp, &game->textu_n.img.line_len,
			&game->textu_n.img.endian);
	game->textu_s.text_value = (int *)mlx_get_data_addr(game->textu_s.img.img,
			&game->textu_s.img.bpp, &game->textu_s.img.line_len,
			&game->textu_s.img.endian);
	game->textu_e.text_value = (int *)mlx_get_data_addr(game->textu_e.img.img,
			&game->textu_e.img.bpp, &game->textu_e.img.line_len,
			&game->textu_e.img.endian);
	game->textu_w.text_value = (int *)mlx_get_data_addr(game->textu_w.img.img,
			&game->textu_w.img.bpp, &game->textu_w.img.line_len,
			&game->textu_w.img.endian);
	add_textures_to_imgs(game);
}
