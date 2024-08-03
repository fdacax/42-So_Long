/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdacax-m <fdacax-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 23:23:01 by fdacax-m          #+#    #+#             */
/*   Updated: 2024/08/02 23:23:01 by fdacax-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_sources(t_game *game, t_image *image, int i, int j)
{
	int	sum;

	sum = i + j;
	if (game->map[i][j] == '1')
		mlx_put_image_to_window(image->w_init, image->window,
			image->sources[0], image->x * 50, image->y * 50);
	if (game->map[i][j] == '0' || (game->map[i][j] == 'E' && game->coins > 0))
		mlx_put_image_to_window(image->w_init, image->window,
			image->sources[1], image->x * 50, image->y * 50);
	if (game->map[i][j] == 'P' && game->coins > 0)
		mlx_put_image_to_window(image->w_init, image->window,
			image->sources[2], image->x * 50, image->y * 50);
	if (game->map[i][j] == 'P' && game->coins == 0)
		mlx_put_image_to_window(image->w_init, image->window,
			image->sources[3], image->x * 50, image->y * 50);
	if (game->map[i][j] == 'C' && (sum % 2 == 0))
		mlx_put_image_to_window(image->w_init, image->window,
			image->sources[4], image->x * 50, image->y * 50);
	if (game->map[i][j] == 'C' && (sum % 2 != 0))
		mlx_put_image_to_window(image->w_init, image->window,
			image->sources[5], image->x * 50, image->y * 50);
	if (game->map[i][j] == 'E' && game->coins == 0)
		mlx_put_image_to_window(image->w_init, image->window,
			image->sources[6], image->x * 50, image->y * 50);
}

void	init_sources(t_image *image, t_game *game)
{
	int	i;

	image->sources[0] = mlx_xpm_file_to_image(image->w_init, "img/wall.xpm",
			&image->s_width, &image->s_height);
	image->sources[1] = mlx_xpm_file_to_image(image->w_init, "img/floor.xpm",
			&image->s_width, &image->s_height);
	image->sources[2] = mlx_xpm_file_to_image(image->w_init, "img/1player.xpm",
			&image->s_width, &image->s_height);
	image->sources[3] = mlx_xpm_file_to_image(image->w_init, "img/2player.xpm",
			&image->s_width, &image->s_height);
	image->sources[4] = mlx_xpm_file_to_image(image->w_init, "img/1coin.xpm",
			&image->s_width, &image->s_height);
	image->sources[5] = mlx_xpm_file_to_image(image->w_init, "img/2coin.xpm",
			&image->s_width, &image->s_height);
	image->sources[6] = mlx_xpm_file_to_image(image->w_init, "img/exit.xpm",
			&image->s_width, &image->s_height);
	i = 0;
	while (image->sources[i])
	{
		if (image->sources[i++] == NULL)
			p_error_mlx("Error\nFailed to load images", game, image);
	}
}

void	init_window(t_image **image, t_game *game)
{
	(*image) = ft_calloc(sizeof(t_image), 1);
	(*image)->w_width = game->total_len * 50;
	(*image)->w_height = game->lines * 50;
	(*image)->w_init = mlx_init();
	if ((*image)->w_init == NULL)
		p_error_mlx("Error\nFail init mlx", game, *image);
	(*image)->window = mlx_new_window((*image)->w_init, (*image)->w_width,
			(*image)->w_height, "So_Long");
	if ((*image)->window == NULL)
		p_error_mlx("Error\nFail creat window", game, *image);
}

int	handler_mlx_hook(int key, t_game *game)
{
	int	i;
	int	j;

	i = game->player_pos[0];
	j = game->player_pos[1];
	if (key == W_KEY || key == U_ARROW)
		i -= 1;
	else if (key == A_KEY || key == L_ARROW)
		j -= 1;
	else if (key == S_KEY || key == D_ARROW)
		i += 1;
	else if (key == D_KEY || key == R_ARROW)
		j += 1;
	if (key == ESC)
		p_error_mlx("ESC was press\nGame Over! q:(", game, game->image);
	refresh_map(game, game->image, i, j);
	return (0);
}

int	close_win_on_x(t_game *game)
{
	p_error_mlx("Closed window by Xs\nGame Over! q:(", game, game->image);
	return (0);
}
