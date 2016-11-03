/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/12 14:59:26 by svassal           #+#    #+#             */
/*   Updated: 2016/09/12 14:59:27 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROJECTION_H
# define PROJECTION_H
# include "fdf.h"

t_point		**projection(t_env *env);
void		draw_pro_map(t_env *env);
void		re_projection(t_env *env);

#endif
