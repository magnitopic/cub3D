/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarabia <jsarabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 09:37:11 by alaparic          #+#    #+#             */
/*   Updated: 2023/09/25 16:27:05 by jsarabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

/**
 * Main program struct containing the mlx vars
*/

typedef struct s_color
{
	int	red;
	int	green;
	int	blue;
	int	alpha;
}	t_color;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_map_data
{
	char	**map;
	char	*texture_no;
	char	*texture_so;
	char	*texture_we;
	char	*texture_ea;
	t_color	floor;
	t_color	ceiling;
}	t_map_data;

/**
 * Player position and direction
*/
typedef struct s_player
{
	float		x;
	float		y;
	float		dx;
	float		dy;
	float		old_x;
	float		old_y;
	float		direction;
}	t_player;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_map_data	map_data;
	t_img		img;
	t_player	player;
}	t_game;

typedef struct s_camera
{
	int	fov;
}	t_camera;

#endif
