/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 15:49:23 by svassal           #+#    #+#             */
/*   Updated: 2016/09/18 15:49:25 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Skip the spaces before the point datas
*/

static void		skip_space(char *str, int *i)
{
	while (str[*i] == ' ')
		(*i)++;
}

/*
** Parse the height of the point
*/

static int		get_height(char *str, int *i, int *e)
{
	int index;

	index = 0;
	while ((ft_isdigit(str[index]) && str[index + 1] != '-') || (str[index] == '-' &&
		ft_isdigit(str[index + 1])))
		index++;
	if (index == 0)
		*e = -1;
	else if (str[index] != ' ' && str[index] != ',' && str[index] != '\0')
		*e = -1;
	else
		*e = 0;
	*i = *i + index;
	return (ft_atoi(str));
}

/*
** Check if a coma is present or not
*/

static int		check_coma(char *str)
{
	if (*str == ',')
		return (1);
	return (0);
}

/*
** Parse the color of the point (if any)
*/

static int		get_color(char *str, int *i)
{
	int			index;
	int			tmp;

	index = 0;
	while (str[index] != ' ' && str[index] != '\0')
		index++;
	if (index > 8 || index < 3)
		return (-2);
	if (str[0] != '0' || str[1] != 'x')
		return (-2);
	tmp = index;
	while (--index >= 2)
		if (!ft_ishexa(str[index]))
			return (-2);
	*i = *i + tmp;
	return (ft_atoibase(str + 2, 16));
}

/*
** Parse a line from the map
*/

int				sub_parse(char *str, int y, t_list **lst)
{
	int		index;
	int		x;
	int		res[3];

	index = 0;
	x = -1;
	while (str[index] != '\0')
	{
		res[1] = -1;
		skip_space(str, &index);
		res[0] = get_height(str + index, &index, &res[2]);
		if (check_coma(str + index))
			res[1] = get_color(str + ++index, &index);
		if (res[2] == -1 || res[1] == -2)
			return (-1);
		else
			ft_lstadd(lst, ft_lstnew(make_point(++x, y, res[0],
			res[1]), sizeof(t_point)));
		skip_space(str, &index);
	}
	return (1);
}
