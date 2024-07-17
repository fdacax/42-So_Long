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
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

int	ft_str_line(char *game)
{
	int i;
	int total_len;

	i = 0;
	total_len = 0;

	if (game == NULL)
		return (0) ;
	while (game[i])
	{
	 	if (game[i]  != '\n')
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

	game->map = ft_calloc(sizeof(char *), game->lines + 1);
	if (!game->map)
		exit(1);
	fd = open(file, O_RDONLY);
	i = 0;
	line = get_next_line(fd);
	if (line == NULL)
		handler_errors(EMPTY);
	while (line)
	{
		if (line[0] != '\n')
		{
			game->map[i] = ft_strdup(line);
			ft_printf("%s", game->map[i]);
			i++;
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}
