/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtymchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 09:46:16 by vtymchen          #+#    #+#             */
/*   Updated: 2017/01/25 19:42:39 by vtymchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <fcntl.h>
# include "libft/libft.h"
# include "libft/get_next_line.h"
# include "minilibx_macos/mlx.h"
# include <math.h>
# include <stdio.h>
# define QUIT 53
# define SCALE_P 1.1
# define SCALE_M 0.9
# define WIDTH 1024
# define HEIGHT 768
# define MOVE 100

typedef struct	s_point
{
	float	x;
	float	y;
	float	z;
	int		color[3];
}				t_point;

typedef struct	s_fdf
{
	void	*mlx;
	void	*win;
	t_point	**points;
	int		m_width;
	int		m_height;
	float	scale;
	int		m;
}				t_fdf;

void			print_line(t_point *a, t_point *b, t_fdf *fdf);
t_point			*new_point(float x, float y, float z, int *color);
char			***parse_map(char *filename);
void			fill_points(char ***points, t_fdf *fdf);
void			draw(t_fdf *fdf);
void			rot_x(t_fdf *fdf, double angle);
void			rot_y(t_fdf *fdf, double angle);
void			rot_z(t_fdf *fdf, double angle);
void			scale_p(t_fdf *fdf);
void			scale_m(t_fdf *fdf);
void			init(t_fdf *fdf, char *filename);
int				*col(char *s);
void			scale(t_fdf *fdf);
int				indexof(char *s);
int				make_color_x(int x, t_point *a, t_point *b);
int				make_color_y(int y, t_point *a, t_point *b);
void			error();
void			move_right(t_fdf *fdf);
void			move_left(t_fdf *fdf);
void			move_up(t_fdf *fdf);
void			move_down(t_fdf *fdf);
void			my_key_funct2(int key, t_fdf *fdf);
int				check(char ***p, t_fdf *fdf);
#endif
