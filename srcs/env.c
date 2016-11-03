/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/12 14:58:05 by svassal           #+#    #+#             */
/*   Updated: 2016/09/12 14:58:06 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Change color mode (base, from map, auto-colored)
*/

void	color_enabler(t_env *e)
{
	if (e->color == NONE)
		e->color = BASE;
	else if (e->color == BASE)
		e->color = AUTO;
	else if (e->color == AUTO)
		e->color = NONE;
}

/*
** Calcul the difference between the highest and lowest point of the map
*/

void	height_calc(t_env *e)
{
	float	h[2];
	int		index;

	index = (e->points[0]->y + 1) * (e->points[0]->x + 1) + 1;
	h[0] = e->points[index - 1]->z;
	h[1] = e->points[index - 1]->z;
	while (--index > 0)
	{
		(h[0]) = (h[0] > e->points[index]->z) ? (e->points[index]->z) : (h[0]);
		(h[1]) = (h[1] < e->points[index]->z) ? (e->points[index]->z) : (h[1]);
	}
	e->points[0]->z = h[1];
	e->points[0]->color = h[0];
}

/*
** Initialze image to draw
*/

t_image	*init_image(void)
{
	t_image *img;

	img = malloc(sizeof(t_image));
	img->beg = malloc(sizeof(int *));
	return (img);
}

/*
** Initialize work environment
*/

t_env	*init_env(void)
{
	t_env	*e;

	if ((e = malloc(sizeof(t_env))) == 0)
		return (0);
	e->win_height = 600;
	e->win_width = 800;
	e->mlx = mlx_init();
	e->window = mlx_new_window(e->mlx, e->win_width, e->win_height, "FDF");
	e->image = init_image();
	e->image->image = mlx_new_image(e->mlx, e->win_width, e->win_height);
	e->image->beg = (int *)mlx_get_data_addr(e->image->image, &(e->image->bpp),
		&(e->image->size_l), &(e->image->endian));
	e->color = NONE;
	e->points = 0;
	e->points_pro = 0;
	e->camera = 0;
	return (e);
}
