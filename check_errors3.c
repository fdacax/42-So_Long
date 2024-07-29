/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdacax-m <fdacax-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 18:15:55 by fdacax-m          #+#    #+#             */
/*   Updated: 2024/07/24 18:31:14 by fdacax-m         ###   ########.fr       */
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
	int	player[2];

	find_player(game, player);
	flood_fill(cp_map, player[0], player[1]);
	printf("\nMapa dps do flood\n");
	i = 0;
	while (i < game->lines)
	{
		j = 0;
		printf("%s", cp_map[i]);
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
	ft_printf("\ncopia do mapa\n\n");
	while (game->map[i])
	{
		cp_map[i] = ft_strdup(game->map[i]);
		ft_printf("%s", cp_map[i]);
		i++;
	}
	validate_path(cp_map, game);
}
