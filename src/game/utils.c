/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 12:30:12 by alaparic          #+#    #+#             */
/*   Updated: 2023/10/08 12:30:27 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

double 	deg_to_rad(double degrees)
{
	return (degrees * (PI / 180));
}

// radians to degrees
double 	rad_to_deg(double radians)
{
	return (radians * (180 / PI));
}
