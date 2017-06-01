/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtymchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 19:10:39 by vtymchen          #+#    #+#             */
/*   Updated: 2017/01/25 20:10:37 by vtymchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char		***parse_map(char *filename)
{
	char	*line;
	char	***points;
	int		fd;
	int		x;

	x = 1;
	if ((fd = open(filename, O_RDONLY)) < 0)
		error();
	while (get_next_line(fd, &line))
	{
		x++;
		free(line);
	}
	points = (char ***)malloc(x * sizeof(char **));
	close(fd);
	if ((fd = open(filename, O_RDONLY)) < 0)
		error();
	x = 0;
	while (get_next_line(fd, &line))
		points[x++] = ft_strsplit(line, ' ');
	points[x] = NULL;
	close(fd);
	return (points);
}

void		fill_points(char ***p, t_fdf *fdf)
{
	int		x;
	int		y;
	int		i;

	i = 0;
	y = 0;
	x = 0;
	while (p[x])
		x++;
	fdf->m_height = x;
	while (p[0][y])
		y++;
	fdf->m_width = y;
	fdf->points = (t_point **)malloc(sizeof(t_point *) * x * y + 1);
	x = 0;
	while (p[x])
	{
		y = -1;
		while (p[x][++y])
			fdf->points[i++] = new_point(y, x, ft_atoi(p[x][y]), col(p[x][y]));
		x++;
	}
	fdf->points[i] = NULL;
}

void		init(t_fdf *fdf, char *filename)
{
	char	***p;
	int		i;
	int		j;

	i = 0;
	p = parse_map(filename);
	fill_points(p, fdf);
	fdf->m = 0;
	if (!check(p, fdf))
	{
		ft_putstr("Not a valid file\n");
		exit(3);
	}
	while (p[i])
	{
		j = 0;
		while (p[i][j])
		{
			ft_memdel((void **)&p[i][j]);
			j++;
		}
		ft_memdel((void **)p[i]);
		i++;
	}
	scale(fdf);
}

int			*col(char *s)
{
	char	**colors;
	int		*new_color;
	int		index;

	index = 2;
	if (!(new_color = (int *)malloc(sizeof(int) * 3)))
		exit(3);
	new_color[0] = 0x00;
	new_color[1] = 0x00;
	new_color[2] = 0x00;
	colors = ft_strsplit(s, ',');
	if (colors[1])
	{
		colors[1] = colors[1] + ft_strlen(colors[1]) - 1;
		while (*colors[1] != 'x')
		{
			new_color[index] = indexof(colors[1] - 1) * 16;
			new_color[index--] += indexof(colors[1]);
			colors[1] = colors[1] - 2;
		}
	}
	else
		new_color[2] = 0x0000f1;
	return (new_color);
}

int			indexof(char *s)
{
	char	*hex1;
	char	*hex2;
	int		index;

	index = 0;
	hex1 = ft_strdup("0123456789abcdef");
	hex2 = ft_strdup("0123456789ABCDEF");
	while (*hex1 && *hex2)
	{
		if (*s == *hex1 || *s == *hex2)
			break ;
		hex1++;
		hex2++;
		index++;
	}
	return (index);
}
