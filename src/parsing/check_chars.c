/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_chars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarabia <jsarabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 18:16:43 by jsarabia          #+#    #+#             */
/*   Updated: 2023/09/18 18:32:28 by jsarabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	check_weird_char(t_game *game)
{
	int		n;
	int		count;
	char	*aux;

	n = 6;
	count = 0;
	aux = NULL;
	while (n < ft_get_matrix_size(game->map_data.map))
	{
		aux = ft_strtrim(game->map_data.map[n], "01 ");
		if (aux && ft_strlen(aux) > 0)
		{
			if (ft_strlen(aux) > 1 || (aux[0] != 'N' && aux[0] != 'W'
					&& aux[0] != 'E' && aux[0] != 'S'))
			{
				free(aux);
				raise_error("Invalid characters");
			}
			free(aux);
			count++;
		}
		n++;
	}
	if (count != 1)
		raise_error("Invalid number of players");
}
