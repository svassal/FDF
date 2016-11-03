/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/12 14:59:16 by svassal           #+#    #+#             */
/*   Updated: 2016/09/12 14:59:17 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H
# include "fdf.h"

t_env	*init_env(void);
void	color_enabler(t_env *e);
void	height_calc(t_env *e);

#endif
