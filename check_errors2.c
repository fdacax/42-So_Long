/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdacax-m <fdacax-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 16:03:35 by fdacax-m          #+#    #+#             */
/*   Updated: 2024/06/25 16:03:35 by fdacax-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	count_letter(t_game *game)
{
	int	i;

	game->total_len = ft_str_line(game->map[0]);
	i = 1;
	while (game->map[i])
	{
		if (ft_str_line(game->map[i]) == game->total_len)
			i++;
		else
			handler_errors(NO_RECTANGULAR);
	}
}

void	check_map_close(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[0][i] && game->map[0][i] != '\n')
	{
		if (game->map[0][i] != '1')
			handler_errors(NO_CLOSED);
		i++;
	}

	i = 0;
	while (game->map[game->lines - 1][i] && game->map[game->lines - 1][i] != '\n')
	{
		if (game->map[game->lines - 1][i] != '1')
			handler_errors(NO_CLOSED);
		i++;
	}
	i = 1;
	while (i < game->lines)
	{
		if (game->map[i][0] != '1' || game->map[i][game->total_len - 1] != '1')
			handler_errors(NO_CLOSED);
		i++;
	}
}

void	check_entities(t_game *game)
{
	int		i;
	int		j;

	i = 1;
	while (i < game->lines)
	{
		j = 1;
		while (j < game->total_len - 1)
		{
			if (game->map[i][j] == 'C')
				game->coins++;
			if (game->map[i][j] == 'P')
				game->player++;
			if (game->map[i][j] == 'E')
				game->exit++;
			j++;
		}
		i++;
	}
	if (game->coins < 1 || game->player != 1 || game->exit != 1)
		handler_errors(W_ENTITIES);
}

void	check_invalid_entities(t_game *game)
{
	int	i;
	int j;

	i = 0;
	while (i < game->lines)
	{
		j = 0;
		while (j < game->total_len - 1)
		{
			if (game->map[i][j] != '1' && game->map[i][j] != '0' && game->map[i][j] != 'P'
				&& game->map[i][j] != 'E' && game->map[i][j] != 'C')
				handler_errors(I_ENTITIES);
			j++;
		}
		i++;
	}
}
