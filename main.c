/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/11 01:16:45 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/01/11 22:33:04 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

static void			display_map(t_map_square ***map)
{
	int				i;
	int				j;

	i = 0;
	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			printf("%d ", map[j][i]->type);
			i++;
		}
		printf("\n");
		j++;
	}
}

int					main(int argc, char **argv)
{
	t_env			env;

	(void)argc;
	(void)argv;

	env.map = get_wolf_map("maps/example.wolfmap");
	display_map(env.map);
	return (0);
}
