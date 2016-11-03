/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/03 11:29:39 by svassal           #+#    #+#             */
/*   Updated: 2016/08/03 12:52:18 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Initialize some numbers used for drawing a line
*/

static void	init_count(int n[8], t_point *p1, t_point *p2)
{
	t_point	t;
	int		nt[7];

	nt[6] = -1;
	while (++nt[6] < 6)
		nt[nt[6]] = n[nt[6]];
	t = *p1;
	while (1)
	{
		n[7]++;
		if (t.x == p2->x && t.y == p2->y)
			break ;
		nt[5] = nt[4];
		if (nt[5] > -(nt[0]))
		{
			nt[4] -= nt[1];
			t.x = t.x + nt[2];
		}
		if (nt[5] < nt[1])
		{
			nt[4] += nt[0];
			t.y = t.y + nt[3];
		}
	}
}

/*
** Sub function called by "draw_line" to initialize some numbers
*/

static void	init_nbr(int n[8], t_point *p1, t_point *p2)
{
	n[0] = ft_abs(p1->x - p2->x);
	n[1] = ft_abs(p1->y - p2->y);
	n[2] = (p1->x < p2->x) ? (1) : (-1);
	n[3] = (p1->y < p2->y) ? (1) : (-1);
	n[4] = ((n[0] > n[1]) ? (n[0]) : -(n[1])) / 2;
	n[6] = 0;
	n[7] = 0;
}

/*
** Draw a line (bresenham)
*/

void		draw_line(t_env *e, int i1, int i2)
{
	t_point		t;
	int			n[8];

	t = *e->points_pro[i1];
	init_nbr(n, &t, e->points_pro[i2]);
	init_count(n, e->points_pro[i1], e->points_pro[i2]);
	while (1)
	{
		if (t.x >= 0 && t.x < e->win_width && t.y >= 0 && t.y < e->win_height)
			write_pixel_image(e, t.x, t.y, color(e, i1, i2, n));
		n[6]++;
		if (t.x == e->points_pro[i2]->x && t.y == e->points_pro[i2]->y)
			break ;
		n[5] = n[4];
		if (n[5] > -(n[0]))
		{
			n[4] -= n[1];
			t.x = t.x + n[2];
		}
		if (n[5] < n[1])
		{
			n[4] += n[0];
			t.y = t.y + n[3];
		}
	}
}
