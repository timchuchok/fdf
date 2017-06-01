/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtymchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 18:20:17 by vtymchen          #+#    #+#             */
/*   Updated: 2017/01/25 19:42:17 by vtymchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#define SQR(x)  x * x

t_point		*new_point(float x, float y, float z, int *color)
{
	t_point *point;

	point = (t_point *)malloc(sizeof(t_point));
	if (!point)
		return (NULL);
	point->x = x;
	point->y = y;
	point->z = z;
	point->color[0] = color[0];
	point->color[1] = color[1];
	point->color[2] = color[2];
	return (point);
}

void		error(void)
{
	perror("Error");
	exit(3);
}

void		scale(t_fdf *fdf)
{
	float	scale;
	float	m_d;
	int		i;
	int		w;
	int		h;

	w = WIDTH;
	h = HEIGHT;
	w -= 200;
	h -= 300;
	m_d = sqrt(SQR(fdf->m_width) + SQR(fdf->m_height));
	scale = sqrt(SQR(h) + SQR(w)) / m_d;
	i = 0;
	while (fdf->points[i])
	{
		fdf->points[i]->x *= scale;
		fdf->points[i]->y *= scale;
		fdf->points[i]->z *= scale / 4;
		i++;
	}
}

int			check(char ***p, t_fdf *fdf)
{
	int x;
	int y;

	x = 0;
	while (p[x])
	{
		y = 0;
		while (p[x][y])
			y++;
		if (y != fdf->m_width)
			return (0);
		x++;
	}
	return (1);
}
