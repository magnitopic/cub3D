/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 12:37:30 by alaparic          #+#    #+#             */
/*   Updated: 2023/09/20 08:07:16 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	exit_game(t_game *game)
{
	mlx_clear_window(game->mlx, game->win);
	mlx_destroy_window(game->mlx, game->win);
	//free_matrix(game->map_data.map);
	exit(0);
}

void	raise_error(char *message)
{
	ft_printf("\033[0;31mError\n%s\n\033[0m", message);
	exit (1);
}

int	ft_rgba(int r, int g, int b, int alpha)
{
	if (alpha > 255 || r > 255 || g > 255 || b > 255)
		return (0);
	return (alpha << 24 | r << 16 | g << 8 | b);
}
