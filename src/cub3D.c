/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 10:28:02 by alaparic          #+#    #+#             */
/*   Updated: 2023/09/05 12:19:57 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

char	**read_file(char **argv)
{
	char	**map;
	char	*map_aux;
	char	*line;
	int		fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (NULL);
	line = get_next_line(fd);
	while (line)
	{
		
	}
	return (ft_split(map_aux, '\n'));
}

int	main(int argc, char **argv)
{
	char	**map;

	if (argc != 2)
		return (1);
	map = read_file(argv);
	if (!map)
		return (1);
	ft_printmatrix();
	return (0);
}
