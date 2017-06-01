/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtymchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 22:29:23 by vtymchen          #+#    #+#             */
/*   Updated: 2017/01/25 18:11:53 by vtymchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw(t_fdf *fdf)
{
	int	i;

	i = 0;
	while (fdf->points[i + 1])
	{
		if ((i + 1) % fdf->m_width != 0)
			print_line(fdf->points[i], fdf->points[i + 1], fdf);
		if (i + fdf->m_width < fdf->m_height * fdf->m_width)
			print_line(fdf->points[i], fdf->points[i + fdf->m_width], fdf);
		i++;
	}
}

void	print_line(t_point *a, t_point *b, t_fdf *fdf)
{
	float	x;
	float	y;
	float	cx;
	float	cy;
	int		color;

	cx = WIDTH / 3 - fdf->points[fdf->m_width / 2]->x + fdf->m;
	cy = HEIGHT / 2;
	x = (a->x < b->x ? a->x : b->x);
	while (x < (a->x > b->x ? a->x : b->x))
	{
		y = a->y + (x - a->x) * (b->y - a->y) / (b->x - a->x);
		color = make_color_x(x, a, b);
		mlx_pixel_put(fdf->mlx, fdf->win, x + cx, y + cy, color);
		x++;
	}
	y = a->y < b->y ? a->y : b->y;
	while (y < (a->y > b->y ? a->y : b->y))
	{
		x = a->x + (y - a->y) * (b->x - a->x) / (b->y - a->y);
		color = make_color_y(y, a, b);
		mlx_pixel_put(fdf->mlx, fdf->win, x + cx, y + cy, color);
		y++;
	}
}

int		make_color_x(int x, t_point *a, t_point *b)
{
	int r;
	int g;
	int bl;
	int color;

	if (a->color[0] == b->color[0] && a->color[1] == b->color[1])
		if (a->color[2] == b->color[2])
			return (a->color[0] << 16) | (a->color[1] << 8) | a->color[2];
	r = a->color[0] + (b->color[0] - a->color[0]) / (b->x - a->x) * (x - a->x);
	g = a->color[1] + (b->color[1] - a->color[1]) / (b->x - a->x) * (x - a->x);
	bl = a->color[2] + (b->color[2] - a->color[2]) / (b->x - a->x) * (x - a->x);
	color = (r << 16) | (g << 8) | bl;
	return (color);
}

int		make_color_y(int y, t_point *a, t_point *b)
{
	int r;
	int g;
	int bl;
	int color;

	if (a->color[0] == b->color[0] && a->color[1] == b->color[1])
		if (a->color[2] == b->color[2])
			return (a->color[0] << 16) | (a->color[1] << 8) | a->color[2];
	r = a->color[0] + (b->color[0] - a->color[0]) / (b->y - a->y) * (y - a->y);
	g = a->color[1] + (b->color[1] - a->color[1]) / (b->y - a->y) * (y - a->y);
	bl = a->color[2] + (b->color[2] - a->color[2]) / (b->y - a->y) * (y - a->y);
	color = (r << 16) | (g << 8) | bl;
	return (color);
}
