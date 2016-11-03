/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/22 14:30:17 by svassal           #+#    #+#             */
/*   Updated: 2016/08/03 11:18:24 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
# define POINT_H
# include "fdf.h"

t_point				*make_point(float x, float y, float height, int color);
t_point				*copy_point(t_point *src);

#endif
