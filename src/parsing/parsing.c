/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 09:18:28 by alaparic          #+#    #+#             */
/*   Updated: 2023/09/19 13:06:04 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	identify_line_value(char *line)
{
	
}

static t_color	get_color_value(char *line)
{
	t_color	color;
	

	color.alpha = 0;
	while (*line && ft_isprint(*line))
		line++;
	line++;
	
	while (line)
	{
		line++;
	}
	return (color);
}

static void	get_values(t_game *game, char **file_con)
{
	int				i;
	enum e_values	value_type;

	i = -1;
	while (file_con[++i])
	{
		value_type = identify_line_value(file_con[i]);
		if (value_type == ERROR)
			raise_error("Invalid value for textures and colors");
		if (value_type == NO)
			game->map_data.texture_no = file_con[i];
		else if (value_type == SO)
			game->map_data.texture_so = file_con[i];
		else if (value_type == WE)
			game->map_data.texture_we = file_con[i];
		else if (value_type == EA)
			game->map_data.texture_ea = file_con[i];
		else if (value_type == C)
			game->map_data.celling = get_color_value(file_con[i]);
		else if (value_type == F)
			game->map_data.floor = get_color_value(file_con[i]);
	}
}

void	parsing(char **argv, t_game *game)
{
	char	**file_content;

	file_content = read_file(argv, game);
	//get_values(game, file_content, &map);
	/* handle_map();
	   -	check_map(map);
	get_values(values); */
}
