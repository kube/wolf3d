/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/11 01:18:07 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/01/11 22:32:12 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
// # include <guava.h>
# include <libft.h>
# include <get_next_line.h>

# include <stdio.h>
# include <fcntl.h>

typedef struct			s_point
{
	float				x;
	float				y;
	float				z;
}						t_point;

typedef struct			s_vector
{
	t_point				*a;
	t_point				*b;
}						t_vector;

typedef union
{
	struct
	{
		unsigned char	blue;
		unsigned char	green;
		unsigned char	red;
		char			opacity;
	};
	int					color;
}						u_color;

typedef struct			s_pressed_keys
{
	int					up;
	int					down;
	int					left;
	int					right;
}						t_pressed_keys;

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
	t_pressed_keys			pressed_keys;
	t_map_square			***map;
	t_point					center;
}							t_env;

t_map_square		***get_wolf_map(char *file_name);

#endif
