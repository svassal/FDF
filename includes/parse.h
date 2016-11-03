/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/21 13:41:18 by svassal           #+#    #+#             */
/*   Updated: 2016/07/27 13:29:26 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H
# include "fdf.h"

int			parse(t_env *e, int fd);
int			sub_parse(char *str, int y, t_list **lst);

#endif
