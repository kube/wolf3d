/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/11 01:18:07 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/01/11 17:20:04 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# include <guava.h>
# include <libft.h>

typedef struct				s_map_square
{
	int						type;
	int						texture;
	int						color;
	int						height;
	int						opacity;
	int						reflexion;
}							t_map_square;

#endif
