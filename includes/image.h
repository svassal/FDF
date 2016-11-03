/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 13:42:02 by svassal           #+#    #+#             */
/*   Updated: 2016/09/19 13:42:04 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H
# include "fdf.h"

void		clear_image(t_env *e);
void		write_pixel_image(t_env *e, int x, int y, int color);

#endif
