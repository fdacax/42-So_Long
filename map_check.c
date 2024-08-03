/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdacax-m <fdacax-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 23:28:27 by fdacax-m          #+#    #+#             */
/*   Updated: 2024/08/02 23:28:32 by fdacax-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_checker(char *file, t_game *game)
{
	count_lines(file, game);
	init_full_map(file, game);
	count_letter(game);
	check_invalid_entities(game);
	check_map_enclosed(game);
	check_entities(game);
	copy_map(game);
}

bool	check_extension(char *file)
{
	char	*extension;

	extension = ft_strrchr(file, '.');
	if (ft_strcmp(extension, ".ber") == 0)
		return (true);
	return (false);
}

bool	check_file_exist(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (false);
	close(fd);
	return (true);
}

void	check_file(char *file)
{
	if (!check_extension(file))
		handler_errors(NULL, EXTENSION);
	if (!check_file_exist(file))
		handler_errors(NULL, NO_FILE);
}
