/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/12 14:58:21 by svassal           #+#    #+#             */
/*   Updated: 2016/09/12 14:58:56 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Make the point projection to the window
*/

static t_point	*conv(t_env *e, int i, t_camera *camera)
{
	t_point	*tmp;
	float	z;
	int		p[3];

	p[0] = e->points[i]->x - (int)(e->points[0]->x / 2);
	p[1] = e->points[i]->y - (int)(e->points[0]->y / 2);
	p[2] = e->points[i]->z;
	if ((tmp = malloc(sizeof(t_point))) == 0)
		return (0);
	z = -sin(camera->y) * p[0] + cos(camera->y) * p[2];
	tmp->x = (int)(((cos(camera->y) * p[0] + sin(camera->y) * p[2])
	* camera->scale) + camera->offset_x);
	tmp->y = (int)(((cos(camera->x) * p[1] - sin(camera->x) * z)
	* camera->scale) + camera->offset_y);
	return (tmp);
}

/*
** Convert the whole 3D points (X, Y, Z) table into its 2D counterpart
*/

t_point			**projection(t_env *env)
{
	t_point		**ret;
	int			index;

	index = (env->points[0]->x + 1) * (env->points[0]->y + 1) + 1;
	if ((ret = malloc(sizeof(t_point *) * index)) == 0)
		return (0);
	while (--index > 0)
		ret[index] = conv(env, index, env->camera);
	ret[index] = copy_point(env->points[index]);
	return (ret);
}

/*
** Recalcul the whole map projection
*/

void			re_projection(t_env *env)
{
	clean_tab(env->points_pro);
	env->points_pro = projection(env);
}

/*
** Draw the projected map to the window
*/

void			draw_pro_map(t_env *env)
{
	int			index;
	int			n[3];

	index = 0;
	n[1] = env->points[0]->x;
	n[2] = env->points[0]->y;
	n[0] = (n[1] + 1) * (n[2] + 1);
	while (++index <= n[0])
	{
		if (env->points[index]->x != n[1])
			draw_line(env, index, index + 1);
		if (env->points[index]->y != n[2])
			draw_line(env, index, index + n[1] + 1);
	}
}
