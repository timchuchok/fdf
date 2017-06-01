/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtymchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 10:25:12 by vtymchen          #+#    #+#             */
/*   Updated: 2017/01/25 19:27:06 by vtymchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		my_key_funct(int key, t_fdf *fdf)
{
	mlx_clear_window(fdf->mlx, fdf->win);
	if (key == QUIT)
		exit(3);
	if (key == 125)
		rot_x(fdf, M_PI / 10);
	if (key == 126)
		rot_x(fdf, -M_PI / 10);
	if (key == 123)
		rot_y(fdf, -M_PI / 10);
	if (key == 124)
		rot_y(fdf, M_PI / 10);
	if (key == 115)
		rot_z(fdf, -M_PI / 10);
	if (key == 119)
		rot_z(fdf, M_PI / 10);
	if (key == 78)
		scale_m(fdf);
	if (key == 69)
		scale_p(fdf);
	my_key_funct2(key, fdf);
	draw(fdf);
	return (0);
}

void	my_key_funct2(int key, t_fdf *fdf)
{
	if (key == 2)
		move_right(fdf);
	if (key == 0)
		move_left(fdf);
	if (key == 13)
		move_up(fdf);
	if (key == 1)
		move_down(fdf);
}

int		main(int ac, char **av)
{
	t_fdf *fdf;

	if (!(fdf = (t_fdf *)malloc(sizeof(t_fdf))))
		error();
	if (ac != 2)
	{
		ft_putendl("usage: ./fdf file");
		exit(3);
	}
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, "My first C Window");
	init(fdf, av[1]);
	rot_x(fdf, M_PI / 180 * 45);
	rot_y(fdf, M_PI / 5);
	rot_z(fdf, -M_PI / 10);
	draw(fdf);
	mlx_key_hook(fdf->win, my_key_funct, fdf);
	mlx_loop(fdf->mlx);
	return (0);
}
