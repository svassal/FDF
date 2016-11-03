/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/21 14:13:27 by svassal           #+#    #+#             */
/*   Updated: 2016/08/03 12:38:05 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include <stdio.h>

/*
** Exit program
*/

static int			exit_program(t_env *e)
{
	clean_env(e);
	exit(1);
}

/*
** Expose Hook
*/

static int			exp_h(void *p)
{
	mlx_clear_window(((t_env *)p)->mlx, ((t_env *)p)->window);
	clear_image(((t_env *)p));
	re_projection((t_env *)p);
	draw_pro_map((t_env *)p);
	mlx_put_image_to_window(((t_env *)p)->mlx, ((t_env *)p)->window,
		((t_env *)p)->image->image, 0, 0);
	return (0);
}

/*
** Key Hook
** 8 = C
** 53 = ESC
** 69 = +
** 78 = -
** 83 = PAV_NUM_1
** 84 = PAV_NUM_2
** 85 = PAV_NUM_3
** 86 = PAV_NUM_4
** 87 = PAV_NUM_5
** 88 = PAV_NUM_6
** 89 = PAV_NUM_7
** 91 = PAV_NUM_8
** 92 = PAV_NUM_9
** 123 = LEFT-ARROW
** 124 = RIGHT-ARROW
** 125 = DOWN-ARROW
** 126 = UP-ARROW
*/

static int			key_h(int kc, void *p)
{
	if (kc == 53)
		exit_program((t_env *)p);
	if (kc == 8)
		color_enabler((t_env *)p);
	if (kc == 15)
		init_cam((t_env *)p, 0);
	if (kc == 69)
		zoom((t_env *)p, 0.5);
	if (kc == 78)
		zoom((t_env *)p, -0.5);
	if (kc == 123)
		move_cam((t_env *)p, 1, 50);
	if (kc == 124)
		move_cam((t_env *)p, 1, -50);
	if (kc == 125)
		move_cam((t_env *)p, 0, 50);
	if (kc == 126)
		move_cam((t_env *)p, 0, -50);
	exp_h(p);
	return (0);
}

/*
** Manage MLX events
*/

static void			mlx_event(t_env *env)
{
	mlx_key_hook(env->window, key_h, (void *)env);
	mlx_hook(env->window, 17, 0, exit_program, (void *)env);
	mlx_expose_hook(env->window, exp_h, (void *)env);
	mlx_loop(env->mlx);
}

int					main(int argc, char **argv)
{
	t_env		*env;
	int			fd;

	if (argc != 2)
	{
		ft_putendl("Usage : fdf [filename]");
		return (0);
	}
	if ((fd = open(argv[1], O_RDONLY)) < 3)
	{
		ft_putendl("Error opening file");
		return (0);
	}
	env = init_env();
	if (parse(env, fd) == -1)
		return (0);
	init_cam(env, 1);
	close(fd);
	height_calc(env);
	env->points_pro = projection(env);
	scale_camera(env);
	mlx_event(env);
	return (0);
}
