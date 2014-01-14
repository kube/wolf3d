/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   layer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 13:14:47 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/01/14 19:32:02 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LAYER_H
# define LAYER_H

# define NORMAL_FUSION 0
# define XOR_FUSION 1
# define AND_FUSION 2
# define OR_FUSION 3
# define ADD_FUSION 4
# define SUB_FUSION 5
# define TINT_FUSION 6

typedef struct			s_layer
{
	int					fusion_mode;
	unsigned int		width;
	unsigned int		height;
	int					*data;
	float				opacity;
}						t_layer;

#endif