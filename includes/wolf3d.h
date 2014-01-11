/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/11 01:18:07 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/01/11 20:45:50 by cfeijoo          ###   ########.fr       */
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

typedef	struct				s_env
{
	void					*mlx;
	void					*win;
	void					*img;
	int						bpp;
	int						size_line;
	int						endian;
	int						*data;
	float					angle;
	int						antialiased;
	int						blured;
	int						horizon;
	float					horizon_z;
	int						rotation;
	float					angle_x;
	t_pressed_keys			pressed_keys;
	t_point					***map;
	t_point					center;
}							t_env;

#endif
