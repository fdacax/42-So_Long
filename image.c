/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdacax-m <fdacax-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 13:49:28 by fdacax-m          #+#    #+#             */
/*   Updated: 2024/08/01 13:49:28 by fdacax-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	refresh_map(t_game *game, t_image *image, int i, int j)
{
	if (game->map[i][j] != '1')
	{
		game->moves++;
		ft_printf("Total moves: %i\n", game->moves);
		if (game->map[i][j] == 'C')
			game->coins--;
		game->map[i][j] = 'P';
		game->map[game->player_pos[0]][game->player_pos[1]] = '0';
		game->player_pos[0] = i;
		game->player_pos[1] = j;
		if (game->coins == 0)
			game->map[game->exit_pos[0]][game->exit_pos[1]] = 'E';
		load_map(image, game);
	}
	if (game->map[i][j] == 'E' && game->coins == 0)
		p_error_mlx("Congratulations, you Win! q:)", game, image);
}

void	load_map(t_image *image, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	image->y = 0;
	while (game->map[i])
	{
		j = 0;
		image->x = 0;
		while (game->map[i][j])
		{
			load_sources(game, image, i, j);
			image->x++;
			j++;
		}
		image->y++;
		i++;
	}
}

void	init_image(t_game *game)
{
	t_image	*image;

	init_window(&image, game);
	init_sources(image, game);
	game->image = image;
	load_map(image, game);
	find_exit(game);
	mlx_hook(image->window, 2, 1L << 0, handler_mlx_hook, game);
	mlx_hook(image->window, 17, 1L << 17, close_win_on_x, game);
	mlx_loop(image->w_init);
}
