/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdacax-m <fdacax-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 23:29:18 by fdacax-m          #+#    #+#             */
/*   Updated: 2024/08/02 23:29:41 by fdacax-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(char **cp_map, int i, int j)
{
	if (cp_map[i][j] == '1' || cp_map[i][j] == 'f')
		return ;
	cp_map[i][j] = 'f';
	flood_fill(cp_map, i + 1, j);
	flood_fill(cp_map, i - 1, j);
	flood_fill(cp_map, i, j + 1);
	flood_fill(cp_map, i, j - 1);
}

void	validate_path(char **cp_map, t_game *game)
{
	int	i;
	int	j;

	find_player(game);
	flood_fill(cp_map, game->player_pos[0], game->player_pos[1]);
	i = 0;
	while (i < game->lines)
	{
		j = 0;
		while (j < game->total_len - 1)
		{
			if (cp_map[i][j] != '1' && cp_map[i][j] != 'f')
			{
				free_cp_map(cp_map);
				handler_errors(game, PATH);
			}
			j++;
		}
		i++;
	}
	free_cp_map(cp_map);
}

void	copy_map(t_game *game)
{
	char	**cp_map;
	int		i;

	i = 0;
	cp_map = ft_calloc(sizeof(char *), game->lines + 1);
	if (!cp_map)
		exit (1);
	while (game->map[i])
	{
		cp_map[i] = ft_strdup(game->map[i]);
		i++;
	}
	validate_path(cp_map, game);
}
