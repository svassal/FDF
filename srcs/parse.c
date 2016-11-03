/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 15:49:05 by svassal           #+#    #+#             */
/*   Updated: 2016/09/18 15:49:08 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

/*
** Check if the map a rectangle
*/

static int		is_map_square(t_list **l)
{
	int		m[3];
	t_list	*tmp;

	tmp = *l;
	m[0] = ((t_point *)(*l)->content)->x;
	m[2] = ((t_point *)(*l)->content)->y;
	while ((*l)->next != 0)
	{
		m[1] = m[0] + 1;
		while (((t_point *)(*l)->content)->x == --m[1] && m[1] > 0)
			*l = (*l)->next;
		if (((t_point *)(*l)->content)->x != 0)
			return (-1);
		else if ((*l)->next != 0)
			*l = (*l)->next;
	}
	*l = tmp;
	return (1);
}

/*
** Convert a chained list of points into a table of points
*/

static t_point	**to_tab(t_list *lst)
{
	t_list		*tmp;
	t_point		**tab;
	t_point		*infos;
	int			total;

	tmp = lst;
	total = (GET_X + 1) * (GET_Y + 1);
	if ((tab = malloc(sizeof(t_point *) * (total + 1))) == 0)
		return (0);
	infos = make_point(GET_X, GET_Y, 0, -1);
	while (total > 0)
	{
		tab[total] = ((t_point *)lst->content);
		lst = lst->next;
		total--;
	}
	tab[0] = infos;
	lst = tmp;
	return (tab);
}

/*
** Parse the map, return 1 if succeed
*/

int				parse(t_env *e, int fd)
{
	char	*str;
	int		n[2];
	t_list	*l;

	n[1] = -1;
	l = 0;
	while ((n[0] = get_next_line(fd, &str)) != 0)
	{
		if (n[0] == -1)
			return (clean_parsing(e, &l, 0));
		if (*str == '\0')
		{
			return (clean_parsing(e, &l, 1));
		}
		if ((n[0] = sub_parse(str, ++n[1], &l)) == -1)
			return (clean_parsing(e, &l, 1));
		free(str);
	}
	if (l == 0 || (n[0] = is_map_square(&l)) == -1)
	{
		return (clean_parsing(e, &l, 1));
	}
	e->points = to_tab(l);
	clean_lst(&l, 0);
	return (1);
}
