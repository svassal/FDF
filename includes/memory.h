/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/27 14:32:30 by svassal           #+#    #+#             */
/*   Updated: 2016/07/27 14:34:07 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMORY_H
# define MEMORY_H
# include "fdf.h"

void		clean_env(t_env *e);
void		clean_lst(t_list **lst, int trig);
void		clean_tab(t_point **tab);
int			clean_parsing(t_env *e, t_list **l, int w);

#endif
