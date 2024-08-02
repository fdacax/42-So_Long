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

int	test_mlx_loop(int key, t_game *game)
{
	if (key == W_KEY || key == U_ARROW)
	{
		ft_printf("tentou ir para cima\n");
		game->player_pos[0] -= 1;
		game->moves++;
	}
	else if (key == A_KEY || key == L_ARROW)
	{
		ft_printf("tentou ir para esquerda\n");
		game->player_pos[1] -= 1;
		game->moves++;
	}
	else if (key == S_KEY || key == D_ARROW)
	{
		ft_printf("tentou ir para baixo\n");
		game->player_pos[0] += 1;
		game->moves++;
	}
	else if (key == D_KEY || key == R_ARROW)
	{
		ft_printf("tentou ir para direita\n");
		game->player_pos[1] += 1;
		game->moves++;
	}

	ft_printf("Total moves: %i\n", game->moves);
	return (0);
}
