/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarabia <jsarabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 12:39:59 by alaparic          #+#    #+#             */
/*   Updated: 2023/09/18 18:52:38 by jsarabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

int	map_width(char **map)
{
	int	len;
	int	i;

	i = 6;
	len = 0;
	while (map[i])
	{
		if ((int)ft_strlen(map[i]) > len)
			len = ft_strlen(map[i]);
		i++;
	}
	return (len);
}

static void	check_extension(char **argv)
{
	char	*file_ext;

	file_ext = ft_strrchr(argv[1], '.');
	if (!file_ext || ft_strncmp(file_ext + 1, "cub", ft_strlen(argv[1])) != 0)
		raise_error("Map with invalid extension.");
}

static char	*get_lines( int fd)
{
	char	*file;
	char	*line;

	line = get_next_line(fd);
	file = ft_calloc(1, 1);
	if (!file)
		exit(1);
	while (line != NULL)
	{
		file = ft_fstrjoin(file, line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	return (file);
}

static void	check_map(t_game *game)
{
	if (game->map_data.map[0][0] != 'N' || game->map_data.map[0][1] != 'O')
		raise_error("Invalid coordinates");
	if (game->map_data.map[1][0] != 'S' || game->map_data.map[1][1] != 'O')
		raise_error("Invalid coordinates");
	if (game->map_data.map[2][0] != 'W' || game->map_data.map[2][1] != 'E')
		raise_error("Invalid coordinates");
	if (game->map_data.map[3][0] != 'E' || game->map_data.map[3][1] != 'A')
		raise_error("Invalid coordinates");
	if (game->map_data.map[0][2] != ' ' || game->map_data.map[1][2] != ' '
		|| game->map_data.map[2][2] != ' ' || game->map_data.map[3][2] != ' ')
		raise_error("Invalid coordinates");
	if (game->map_data.map[4][0] != 'F' || game->map_data.map[4][1] != ' ')
		raise_error("Invalid coordinates");
	if (game->map_data.map[5][0] != 'C' || game->map_data.map[5][1] != ' ')
		raise_error("Invalid coordinates");
	check_walls(game);
	check_weird_char(game);
	check_config(game);
}

void	read_file(char **argv, t_game *game)
{
	char	*file;
	int		fd;

	check_extension(argv);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		raise_error("Error when opening file. Does the file exist?");
	if (read(fd, 0, 1) == 0)
		raise_error("Empty map file");
	file = get_lines(fd);
	close(fd);
	game->map_data.map = ft_split(file, '\n');
	check_map(game);
	free(file);
}
