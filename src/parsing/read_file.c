/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 12:39:59 by alaparic          #+#    #+#             */
/*   Updated: 2023/10/16 15:04:03 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static void	check_extension(char **argv)
{
	char	*file_ext;

	file_ext = ft_strrchr(argv[1], '.');
	if (!file_ext || ft_strncmp(file_ext + 1, "cub", ft_strlen(argv[1])) != 0)
		raise_error("Map with invalid extension.");
}

static void	check_map_empty_line(char *line)
{
	static int	count = 0;
	static int	flag_enter = 0;
	static int	flag_exit = 0;

	printf("Line: %zu\n", ft_strlen(line));
	if (count == 6 && ft_strlen(line) > 1 && !flag_enter)
		flag_enter = 1;
	if (count < 6 && ft_strlen(line) > 1)
		count++;
	if (flag_enter && ft_strlen(line) == 1 && !flag_exit)
		flag_exit++;
	if ((ft_strlen(line) > 1 || *line !='\n') && flag_exit)
		raise_error("Empty line in map");
}

static char	*get_lines(int fd)
{
	char	*file;
	char	*line;

	line = get_next_line(fd);
	file = ft_calloc(1, 1);
	if (!file)
		exit(1);
	while (line != NULL)
	{
		check_map_empty_line(line);
		file = ft_fstrjoin(file, line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	return (file);
}

char	**read_file(char **argv)
{
	char	*file;
	int		fd;
	char	**file_con;

	check_extension(argv);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		raise_error("Error when opening file. Does the file exist?");
	if (read(fd, 0, 1) == 0)
		raise_error("Empty map file");
	file = get_lines(fd);
	close(fd);
	file_con = ft_split(file, '\n');
	free(file);
	return (file_con);
}
