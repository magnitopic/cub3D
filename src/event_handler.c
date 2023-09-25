/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 14:50:34 by alaparic          #+#    #+#             */
/*   Updated: 2023/09/22 10:05:48 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	event_handler(enum e_keys key, t_game *game)
{
	if (key == ESC)
		exit_game(game);
	/* else if (key == W)
	else if (key == A)
	else if (key == S)
	else if (key == D)
	else if (key == UP)
	else if (key == LEFT)
	else if (key == DOWN)
	else if (key == RIGHT) */
	return (0);
}
