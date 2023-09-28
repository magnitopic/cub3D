/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarabia <jsarabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 09:37:11 by alaparic          #+#    #+#             */
/*   Updated: 2023/09/28 13:01:30 by jsarabia         ###   ########.fr       */
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
	int		max_x;
	int		max_y;
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
	float		old_x;
	float		old_y;
	float		dx;
	float		dy;
	float		plane_x;
	float		plane_y;
	float		camera;
	float		direction;
}	t_player;

typedef struct s_camera
{
	double	fov;
	float	dx;
	float	dy;
	float	offset;
	float	distance;
	float	direction;
	float	vertical;
	float	horizontal;
	float	angle_tan;
}	t_camera;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_map_data	map_data;
	t_img		img;
	t_player	player;
	t_camera	camera;
}	t_game;

#endif
