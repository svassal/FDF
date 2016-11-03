/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/12 14:59:30 by svassal           #+#    #+#             */
/*   Updated: 2016/09/12 14:59:32 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H
# include <stdlib.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;
typedef enum		e_bool
{
	FALSE, TRUE
}					t_bool;
typedef	struct		s_point
{
	float			x;
	float			y;
	float			z;
	int				color;
}					t_point;
typedef	struct		s_camera
{
	float			x;
	float			offset_x;
	float			y;
	float			offset_y;
	float			scale;
}					t_camera;
typedef enum		e_color
{
	NONE, BASE, AUTO
}					t_color;
typedef struct		s_image
{
	void			*image;
	int				*beg;
	int				bpp;
	int				size_l;
	int				endian;
}					t_image;
typedef struct		s_env
{
	void			*mlx;
	void			*window;
	int				win_width;
	int				win_height;
	t_image			*image;
	t_camera		*camera;
	t_point			**points;
	t_point			**points_pro;
	t_color			color;
}					t_env;
#endif
