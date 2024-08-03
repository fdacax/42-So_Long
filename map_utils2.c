/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdacax-m <fdacax-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 23:30:20 by fdacax-m          #+#    #+#             */
/*   Updated: 2024/08/02 23:30:43 by fdacax-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_player(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->lines)
	{
		j = 0;
		while (j < game->total_len - 1)
		{
			if (game->map[i][j] == 'P')
			{
				game->player_pos[0] = i;
				game->player_pos[1] = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	find_exit(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->lines)
	{
		j = 0;
		while (j < game->total_len - 1)
		{
			if (game->map[i][j] == 'E')
			{
				game->exit_pos[0] = i;
				game->exit_pos[1] = j;
				return ;
			}
			j++;
		}
		i++;
	}
}
