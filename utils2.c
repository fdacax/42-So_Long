/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdacax-m <fdacax-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 19:06:36 by fdacax-m          #+#    #+#             */
/*   Updated: 2024/07/24 19:06:36 by fdacax-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_player(t_game *game, int player[2])
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
				player[0] = i;
				player[1] = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	free_maps(t_game *game)
{
	int	i;

	i = 0;
	if (game->full_map)
	{
		while (game->full_map[i])
			free(game->full_map[i++]);
		free(game->full_map);
	}
	i = 0;
	if (game->map)
	{
		while (game->map[i])
			free(game->map[i++]);
		free(game->map);
	}
	free(game);
}

void	free_cp_map(char **cp_map)
{
	int	i;

	i = 0;
	if (cp_map)
	{
		while (cp_map[i])
			free(cp_map[i++]);
		free(cp_map);
	}
}
