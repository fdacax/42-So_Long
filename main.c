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

void	init(t_game **game)
{
	(*game) = ft_calloc(sizeof(t_game), 1);
	(*game)->lines = 0;
	(*game)->all_lines = 0;
	(*game)->map = NULL;
	(*game)->full_map = NULL;
	(*game)->total_len = 0;
	(*game)->coins = 0;
	(*game)->player = 0;
	(*game)->exit = 0;
}

int	main(int argc, char *argv[])
{
	t_game	*game;

	if (argc == 2)
	{
		check_file(argv[1]);
		init(&game);
		tche_tche(argv[1], game);
		test_mlx();
	}
	return (0);
}
