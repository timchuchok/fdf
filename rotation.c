/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtymchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 23:36:14 by vtymchen          #+#    #+#             */
/*   Updated: 2017/01/19 17:43:08 by vtymchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rot_x(t_fdf *fdf, double angle)
{
	float	new_y;
	float	new_z;
	int		i;

	i = 0;
	while (fdf->points[i])
	{
		new_y = fdf->points[i]->y * cos(angle) - fdf->points[i]->z * sin(angle);
		new_z = fdf->points[i]->y * sin(angle) + fdf->points[i]->z * cos(angle);
		fdf->points[i]->y = new_y;
		fdf->points[i]->z = new_z;
		i++;
	}
}

void	rot_y(t_fdf *fdf, double angle)
{
	float	new_x;
	float	new_z;
	int		i;

	i = 0;
	while (fdf->points[i])
	{
		new_x = fdf->points[i]->x * cos(angle) + fdf->points[i]->z * sin(angle);
		new_z = fdf->points[i]->z * cos(angle) - fdf->points[i]->x * sin(angle);
		fdf->points[i]->x = new_x;
		fdf->points[i]->z = new_z;
		i++;
	}
}

void	rot_z(t_fdf *fdf, double angle)
{
	float	new_x;
	float	new_y;
	int		i;

	i = 0;
	while (fdf->points[i])
	{
		new_x = fdf->points[i]->x * cos(angle) - fdf->points[i]->y * sin(angle);
		new_y = fdf->points[i]->x * sin(angle) + fdf->points[i]->y * cos(angle);
		fdf->points[i]->x = new_x;
		fdf->points[i]->y = new_y;
		i++;
	}
}

void	scale_p(t_fdf *fdf)
{
	int i;

	i = 0;
	while (fdf->points[i])
	{
		fdf->points[i]->x = fdf->points[i]->x * SCALE_P;
		fdf->points[i]->y = fdf->points[i]->y * SCALE_P;
		fdf->points[i]->z = fdf->points[i]->z * SCALE_P;
		i++;
	}
}

void	scale_m(t_fdf *fdf)
{
	int i;

	i = 0;
	while (fdf->points[i])
	{
		fdf->points[i]->x = fdf->points[i]->x * SCALE_M;
		fdf->points[i]->y = fdf->points[i]->y * SCALE_M;
		fdf->points[i]->z = fdf->points[i]->z * SCALE_M;
		i++;
	}
}
