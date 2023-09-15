/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 09:37:11 by alaparic          #+#    #+#             */
/*   Updated: 2023/09/15 10:02:48 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

/**
 * Main program struct containing the mlx vars
*/
typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
}	t_game;

typedef struct s_camera
{
	int	fov;
}	t_camera;

/**
 * Player position and direction
*/
typedef struct s_player
{
	int		x;
	int		y;
	int		direction;
}	t_player;

#endif