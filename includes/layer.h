/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   layer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 13:14:47 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/01/19 13:56:46 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LAYER_H
# define LAYER_H

# include <color.h>

# define NORMAL_BLEND 0
# define XOR_BLEND 1
# define AND_BLEND 2
# define OR_BLEND 3
# define ADD_BLEND 4
# define SUB_BLEND 5
# define TINT_BLEND 6

typedef struct			s_layer
{
	int					display;
	int					blend_mode;
	unsigned int		width;
	unsigned int		height;
	t_pixel				*data;
	float				opacity;
}						t_layer;

#endif