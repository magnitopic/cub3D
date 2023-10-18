/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 12:41:25 by alaparic          #+#    #+#             */
/*   Updated: 2023/10/18 16:17:00 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	ft_leaks(void)
{
	system("Leaks -q cub3D");
}

int	main(int argc, char **argv)
{
	t_game	*game;

	//atexit(ft_leaks);
	if (argc != 2)
		raise_error("Expected one parameter");
	game = ft_calloc(1, sizeof(t_game));
	if (!game)
		return (1);
	parsing(argv, game);
	start_game(game, argv[1]);
	return (0);
}
