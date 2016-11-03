/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 13:40:21 by svassal           #+#    #+#             */
/*   Updated: 2016/09/19 13:40:23 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Clear the image content and put it to a defined color
*/

void		clear_image(t_env *e)
{
	int		max;
	int		index;

	max = (e->win_height * e->win_width);
	index = -1;
	while (++index < max)
		*(e->image->beg + index) = 0x55333333;
}

/*
** Write a pixel in the image
*/

void		write_pixel_image(t_env *e, int x, int y, int color)
{
	int		pos;

	pos = x + (y * e->win_width);
	*(e->image->beg + pos) = color;
}
