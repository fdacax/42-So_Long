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

void find_player(t_game *game, int player[2])
{
	int i;
	int j;

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