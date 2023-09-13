/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarabia <jsarabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:35:00 by jsarabia          #+#    #+#             */
/*   Updated: 2023/09/13 17:45:51 by jsarabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	exit_game(t_game *game)
{
	mlx_clear_window(game->mlx, game->win);
	mlx_destroy_window(game->mlx, game->win);
	free_matrix(game->map);
	exit(0);
}

void	run_game(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, 921, 600, "cub3D");
	mlx_hook(game->win, 17, 0, exit_game, game);
	mlx_loop(game->mlx);
}
