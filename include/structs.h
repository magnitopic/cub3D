/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 09:37:11 by alaparic          #+#    #+#             */
/*   Updated: 2023/09/18 10:26:57 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

/**
 * Main program struct containing the mlx vars
*/
typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	t_img	img;
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
