/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdacax-m <fdacax-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 23:04:03 by fdacax-m          #+#    #+#             */
/*   Updated: 2024/08/02 23:04:03 by fdacax-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	free_images(t_image *image)
{
	int	i;

	i = 0;
	while (i < 7)
	{
		if (image->sources[i])
			mlx_destroy_image(image->w_init, image->sources[i]);
		i++;
	}
	if (image->window)
	{
		mlx_destroy_window(image->w_init, image->window);
		mlx_destroy_display(image->w_init);
	}
	if (image->w_init)
		free(image->w_init);
	free(image);
}

void	p_error_mlx(char *str, t_game *game, t_image *image)
{
	free_maps(game);
	free_images(image);
	ft_putendl_fd(str, 1);
	exit(1);
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
