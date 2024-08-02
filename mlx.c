/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdacax-m <fdacax-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 21:03:48 by fdacax-m          #+#    #+#             */
/*   Updated: 2024/07/29 21:03:49 by fdacax-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	test_mlx_hook(int key, t_game *game, t_image *image)
{
	int	i;
	int j;

	i = game->player_pos[0];
	j = game->player_pos[1];
	if (key == W_KEY || key == U_ARROW)
	{
		ft_printf("tentou ir para cima\n");
		i -= 1;
		game->moves++;
		refresh_map(game,image, i, j);
	}
	else if (key == A_KEY || key == L_ARROW)
	{
		ft_printf("tentou ir para esquerda\n");
		j -= 1;
		game->moves++;
		refresh_map(game,image, i, j);
	}
	else if (key == S_KEY || key == D_ARROW)
	{
		ft_printf("tentou ir para baixo\n");
		i += 1;
		game->moves++;
		refresh_map(game,image, i, j);
	}
	else if (key == D_KEY || key == R_ARROW)
	{
		ft_printf("tentou ir para direita\n");
		j += 1;
		game->moves++;
		refresh_map(game,image, i, j);
	}
	if (key == ESC)
		exit(0);

	//ft_printf("Total moves: %i\n", game->moves);
	return (0);
}


void	refresh_map(t_game *game, t_image *image, int i,int j)
{
	int k = 0;
	int l;
	(void)image;
	if (game->map[i][j] == '0' || game->map[i][j] == 'C')
	{
		game->map[i][j] = 'P';
		game->map[game->player_pos[0]][game->player_pos[1]] = '0';
		game->player_pos[0] = i;
		game->player_pos[1] = j;
		while (game->map[k])
		{
			l = 0;
			printf("%s", game->map[k]);
			while (game->map[k][l])
				l++;
			k++;
		}
		//ft_printf("x = %i, y = %i\n", j, i);

	}

}
