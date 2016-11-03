/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/12 14:58:11 by svassal           #+#    #+#             */
/*   Updated: 2016/09/12 14:58:13 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Clean everything allocated while parsing if an error is detected
*/

int			clean_parsing(t_env *e, t_list **l, int w)
{
	clean_lst(l, 1);
	clean_env(e);
	if (w == 0)
		ft_putendl("Error Reading File !");
	if (w == 1)
		ft_putendl("Map Error !");
	return (-1);
}

/*
** Clean the memory allocated to the whole environement
*/

void		clean_env(t_env *e)
{
	if (e->points_pro != 0)
		clean_tab(e->points_pro);
	e->points_pro = 0;
	if (e->points != 0)
		clean_tab(e->points);
	e->points = 0;
	if (e->camera != 0)
		free(e->camera);
	if (e->image != 0)
	{
		mlx_destroy_image(e->mlx, e->image->image);
		free(e->image);
	}
	e->image = 0;
	e->camera = 0;
	mlx_destroy_window(e->mlx, e->window);
	e->window = 0;
	free(e->mlx);
	e->mlx = 0;
	free(e);
	e = 0;
}

/*
** Clean memory allocated for the chained list (not its content)
*/

void		clean_lst(t_list **lst, int trig)
{
	t_list	*tmp;

	while (*lst != 0)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		if (trig == 1)
			free(tmp->content);
		free(tmp);
	}
}

/*
** Clean memory allocated to a table containing points (and its content)
*/

void		clean_tab(t_point **tab)
{
	int		index;

	index = (tab[0]->x + 1) * (tab[0]->y + 1) + 1;
	while (--index >= 0)
		free(tab[index]);
	free(tab);
}
