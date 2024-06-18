/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdacax-m <fdacax-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:28:14 by fdacax-m          #+#    #+#             */
/*   Updated: 2024/06/17 15:28:14 by fdacax-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(void)
{
	void *mlx;
	void *mlx_win;

	mlx = mlx_init();
	if (!mlx)
	{
		fprintf(stderr, "Error: Failed to initialize MiniLibX\n");
		return 1;
	}

	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	if (!mlx_win)
	{
		fprintf(stderr, "Error: Failed to create window\n");
		return 1;
	}

	mlx_loop(mlx);

	return 0;
}