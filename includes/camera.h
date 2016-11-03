/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/04 14:03:52 by svassal           #+#    #+#             */
/*   Updated: 2016/08/04 14:04:18 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H
# include "fdf.h"

void	zoom(t_env *env, float d);
void	move_cam(t_env *env, int axe, float d);
void	init_cam(t_env *env, int trig);
void	scale_camera(t_env *env);

#endif
