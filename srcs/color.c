/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 13:34:54 by svassal           #+#    #+#             */
/*   Updated: 2016/09/15 13:35:03 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#define R1	drgb[0]
#define G1	drgb[1]
#define B1	drgb[2]
#define R2	drgb[3]
#define G2	drgb[4]
#define B2	drgb[5]
#define DR	drgb[6]
#define DG	drgb[7]
#define DB	drgb[8]
#define R3	rgb[0]
#define G3	rgb[1]
#define B3	rgb[2]
#define P	((n[6] * 100) / n[7])

/*
** Calcul the color according to height and length of the line drawn
*/

static int		color_a(t_env *e, int i1, int i2, int n[8])
{
	int		m[3];
	float	f[3];

	m[0] = e->points[0]->color;
	m[1] = e->points[0]->z - m[0];
	f[0] = (e->points[i1]->z) - m[0];
	f[1] = (e->points[i2]->z) - m[0];
	if (f[0] > f[1])
		f[2] = f[0] - ((f[0] - f[1]) * n[6] / n[7]);
	else
		f[2] = ((f[1] - f[0]) * n[6] / n[7]) + f[0];
	m[2] = (((f[2] * 100) / m[1]) / 100) * 511;
	if (m[2] == 256)
		return (255);
	if (m[2] > 256)
		return (255 + ((m[2] - 256) * 16 * 16));
	return (16711935 - (m[2] * 16 * 16 * 16 * 16));
}

/*
** Check if a point color is defined by the map or not
*/

static int		check_p(t_env *e, int i1, int i2, int s)
{
	if (s == 1)
		e->points[i1]->color = -1;
	if (s == 2)
		e->points[i2]->color = -1;
	if (e->points[i1]->color == -1 && s == -1)
	{
		e->points[i1]->color = 0xFFFFFF;
		return (1);
	}
	if (e->points[i2]->color == -1 && s == -1)
	{
		e->points[i2]->color = 0xFFFFFF;
		return (2);
	}
	return (0);
}

/*
** Choose color according to the map data
*/

static int		color_na(t_env *e, int i1, int i2, int n[8])
{
	int		rgb[3];
	float	drgb[9];
	int		tmp;

	if (e->points[i1]->color == -1 && e->points[i2]->color == -1)
		return (0xFFFFFF);
	tmp = check_p(e, i1, i2, -1);
	if (e->points[i1]->color == e->points[i2]->color)
		return (e->points[i1]->color);
	R1 = (e->points[i1]->color & 0xFF0000) >> 16;
	R2 = (e->points[i2]->color & 0xFF0000) >> 16;
	G1 = (e->points[i1]->color & 0x00FF00) >> 8;
	G2 = (e->points[i2]->color & 0x00FF00) >> 8;
	B1 = (e->points[i1]->color & 0x0000FF);
	B2 = (e->points[i2]->color & 0x0000FF);
	DR = ft_abs(R2 - R1);
	DG = ft_abs(G2 - G1);
	DB = ft_abs(B2 - B1);
	R3 = (R2 > R1) ? (R1 + n[6] * (DR / n[7])) : (R1 - n[6] * (DR / n[7]));
	G3 = (G2 > G1) ? (G1 + n[6] * (DG / n[7])) : (G1 - n[6] * (DG / n[7]));
	B3 = (B2 > B1) ? (B1 + n[6] * (DB / n[7])) : (B1 - n[6] * (DB / n[7]));
	tmp = check_p(e, i1, i2, tmp);
	return ((R3 * 65536) + (G3 * 256) + B3);
}

/*
** Calcul the color
*/

int				color(t_env *e, int i1, int i2, int n[8])
{
	if (e->color == AUTO)
		return (color_a(e, i1, i2, n));
	if (e->color == BASE)
		return (color_na(e, i1, i2, n));
	return (0xFFFFFF);
}
