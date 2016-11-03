/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/12 14:58:17 by svassal           #+#    #+#             */
/*   Updated: 2016/09/12 14:58:18 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Create a point
*/

t_point		*make_point(float x, float y, float z, int color)
{
	t_point	*tmp;

	if ((tmp = malloc(sizeof(t_point))) == 0)
		return (0);
	tmp->x = x;
	tmp->y = y;
	tmp->z = z;
	tmp->color = color;
	return (tmp);
}

/*
** Copy a point to a new one
*/

t_point		*copy_point(t_point *src)
{
	t_point		*ret;

	if ((ret = malloc(sizeof(src))) == 0)
		return (0);
	ret->x = src->x;
	ret->y = src->y;
	ret->z = src->z;
	ret->color = src->color;
	return (ret);
}
