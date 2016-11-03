/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/12 14:57:59 by svassal           #+#    #+#             */
/*   Updated: 2016/09/12 14:58:00 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Change camera's position
*/

void	move_cam(t_env *env, int axe, float d)
{
	if (axe == 0)
		env->camera->x += 1 / d;
	else
		env->camera->y += 1 / d;
}

/*
** Change the zoom of the camera
*/

void	zoom(t_env *env, float d)
{
	if (env->camera->scale + d <= 0)
		env->camera->scale = ft_abs(d);
	else
		env->camera->scale += d;
}

/*
** Scale the POV using height and width of the map
*/

void	scale_camera(t_env *env)
{
	float	c[2];

	c[0] = env->points[0]->x / (env->camera->offset_x);
	c[1] = env->points[0]->y / (env->camera->offset_y);
	env->camera->scale = (c[1] > c[0]) ? (1 / c[1]) : (1 / c[0]);
}

/*
** Initialize the camera with initial values or reset it
*/

void	init_cam(t_env *env, int trig)
{
	if (trig == 1)
		env->camera = (t_camera *)ft_memalloc(sizeof(t_camera));
	env->camera->x = 0.5;
	env->camera->y = 0.5;
	env->camera->offset_x = (env->win_width / 2);
	env->camera->offset_y = (env->win_height / 2);
	env->camera->scale = 20.0;
	if (trig == 0)
		scale_camera(env);
}
