/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtymchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 17:38:30 by vtymchen          #+#    #+#             */
/*   Updated: 2017/01/25 18:13:49 by vtymchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	move_right(t_fdf *fdf)
{
	fdf->m += MOVE;
}

void	move_left(t_fdf *fdf)
{
	fdf->m -= MOVE;
}

void	move_up(t_fdf *fdf)
{
	int i;

	i = 0;
	while (fdf->points[i])
	{
		fdf->points[i]->y -= MOVE;
		i++;
	}
}

void	move_down(t_fdf *fdf)
{
	int i;

	i = 0;
	while (fdf->points[i])
	{
		fdf->points[i]->y += MOVE;
		i++;
	}
}
