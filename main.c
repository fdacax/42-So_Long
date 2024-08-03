/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdacax-m <fdacax-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:28:14 by fdacax-m          #+#    #+#             */
/*   Updated: 2024/06/17 15:28:14 by fdacax-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_game	*game;

	if (argc == 2)
	{
		check_file(argv[1]);
		game = ft_calloc(sizeof(t_game), 1);
		map_checker(argv[1], game);
		init_image(game);
	}
	return (0);
}
