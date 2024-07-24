/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdacax-m <fdacax-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 15:38:23 by fdacax-m          #+#    #+#             */
/*   Updated: 2024/07/15 15:38:23 by fdacax-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	count_lines(char *file, t_game *game)
{
	char	*line;
	int		fd;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		if (line[0] != '\n')
			game->lines++;
		game->all_lines++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

int	ft_str_line(char *game)
{
	int	i;
	int	total_len;

	i = 0;
	total_len = 0;
	if (game == NULL)
		return (0);
	while (game[i])
	{
		if (game[i] != '\n')
			total_len++;
		i++;
	}
	return (total_len);
}

void	dps_eu_penso(char *file, t_game *game)
{
	char	*line;
	int		fd;
	int		i;

	game->full_map = ft_calloc(sizeof(char *), game->all_lines + 1);
	if (!game->full_map)
		exit(1);
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	if (line == NULL)
		handler_errors(EMPTY);
	i = 0;
	while (line)
	{
		game->full_map[i] = ft_strdup(line);
		ft_printf("%s", game->full_map[i]);
		i++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	jaja_penso(game);
}

void	jaja_penso(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	ft_printf("\n");
	game->map = ft_calloc(sizeof(char *), game->lines + 1);
	if (!game->map)
		exit(1);
	while (game->full_map[i])
	{
		if (game->full_map[i][0] != '\n')
		{
			game->map[j] = ft_strdup(game->full_map[i]);
			ft_printf("%s", game->map[j]);
			j++;
		}
		i++;
	}
}

void	nl_finder_inside_map(t_game *game)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	while (game->full_map[i])
	{
		while ((ft_strcmp(game->full_map[i], game->map[j]) == 0) && j < game->lines - 1)
		{
			if (game->full_map[i + 1][0] == '\n')
			{
				ft_printf("Hugo viado\n");
				exit(1);
			}
			j++;
		}
		i++;
	}
}
