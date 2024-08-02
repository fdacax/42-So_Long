/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdacax-m <fdacax-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 13:49:28 by fdacax-m          #+#    #+#             */
/*   Updated: 2024/08/01 13:49:28 by fdacax-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	init_sources(t_image *image, t_game *game)
{
	image->sources[0] = mlx_xpm_file_to_image(image->w_init,
			"sources/1 wall.xpm", &image->s_width, &image->s_height);
	if (image->sources[0] == NULL)
		p_error_mlx("Error\nFailed to load wall", game, image);
	image->sources[1] = mlx_xpm_file_to_image(image->w_init,
			"sources/1 floor.xpm", &image->s_width, &image->s_height);
	if (image->sources[1] == NULL)
		p_error_mlx("Error\nFailed to load floor", game, image);
	image->sources[2] = mlx_xpm_file_to_image(image->w_init,
			"sources/1 player.xpm", &image->s_width, &image->s_height);
	image->sources[3] = mlx_xpm_file_to_image(image->w_init,
			"sources/2 player.xpm", &image->s_width, &image->s_height);
	if (image->sources[3] == NULL || image->sources[2] == NULL)
		p_error_mlx("Error\nFailed to load player", game, image);
	image->sources[4] = mlx_xpm_file_to_image(image->w_init,
			"sources/1 coin.xpm", &image->s_width, &image->s_height);
	image->sources[5] = mlx_xpm_file_to_image(image->w_init,
			"sources/2 coin.xpm", &image->s_width, &image->s_height);
	if (image->sources[5] == NULL || image->sources[4] == NULL)
		p_error_mlx("Error\nFailed to load player.xpm", game, image);
	image->sources[6] = mlx_xpm_file_to_image(image->w_init,
			"sources/1 exit.xpm", &image->s_width, &image->s_height);
	if (image->sources[6] == NULL)
		p_error_mlx("Error\nFailed to load exit.xpm", game, image);
}

void	load_map(t_image *image, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	image->y = 0;
	while (game->map[i])
	{
		j = 0;
		image->x = 0;
		while (game->map[i][j])
		{
			load_sources(game, image, i, j);
			image->x += 50;
			j++;
		}
		image->y += 50;
		i++;
	}
}

void	load_sources(t_game *game, t_image *image, int i, int j)
{
	int	sum;

	printf("image->x = %i, image->y = %i\n", image->x, image->y);
	sum = i + j;
	if (game->map[i][j] == '1')
		mlx_put_image_to_window(image->w_init, image->window,
			image->sources[0], image->x, image->y);
	if (game->map[i][j] == '0')
		mlx_put_image_to_window(image->w_init, image->window,
			image->sources[1], image->x, image->y);
	if (game->map[i][j] == 'P' && game->coins > 0)
		mlx_put_image_to_window(image->w_init, image->window,
			image->sources[2], image->x, image->y);
	if (game->map[i][j] == 'P' && game->coins == 0)
		mlx_put_image_to_window(image->w_init, image->window,
			image->sources[3], image->x, image->y);
	if (game->map[i][j] == 'C' && (sum % 2 == 0))
		mlx_put_image_to_window(image->w_init, image->window,
			image->sources[4], image->x, image->y);
	if (game->map[i][j] == 'C' && (sum % 2 != 0))
		mlx_put_image_to_window(image->w_init, image->window,
			image->sources[5], image->x, image->y);
	if (game->map[i][j] == 'E')
		mlx_put_image_to_window(image->w_init, image->window,
			image->sources[6], image->x, image->y);


}

void	droga(t_game *game)
{
	t_image	*image;

	init_window(&image, game);
	init_sources(image, game);
	load_map(image, game);
	mlx_key_hook(image->window, test_mlx_hook, game);
	mlx_loop(image->w_init);
}

void	p_error_mlx(char *str, t_game *game, t_image *image)
{
	free_maps(game);
	free(image);
	ft_putendl_fd(str, 1);
	exit(1);
}

/*
 * se for a tecla manda pra func q vai rec a prox posicao  da tecla
 * verificar na se esse esta dentro do do chao, e se essa prox pos n é 1
 * se n for 0 ou c ele avança, se for E, exit (0)
 * deixa a pos anterior a 0
 *
 */