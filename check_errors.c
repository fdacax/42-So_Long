/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdacax-m <fdacax-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 15:56:36 by fdacax-m          #+#    #+#             */
/*   Updated: 2024/06/25 15:56:36 by fdacax-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	tche_tche(char *file, t_game *game)
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

void	handler_errors(t_game *game, t_errors error)
{
	if (game)
		free_maps(game);
	if (error == EXTENSION)
		ft_printf("Error\nInvalid extension\n");
	if (error == NO_FILE)
		ft_printf("Error\nCan't open this file\n");
	if (error == EMPTY)
		ft_printf("Error\nThe file is empty\n");
	if (error == NO_RECTANGULAR)
		ft_printf("Error\nThe map must be rectangular\n");
	if (error == NO_ENCLOSED)
		ft_printf("Error\nThe map must be enclosed by walls\n");
	if (error == W_ENTITIES)
		ft_printf("Error\nWrong number of coin/exit/player\n");
	if (error == I_ENTITIES)
		ft_printf("Error\nWrong input characters");
	if (error == PATH)
		ft_printf("Error\nInvalid path\n");
	exit (1);
}
