/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdacax-m <fdacax-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 21:03:48 by fdacax-m          #+#    #+#             */
/*   Updated: 2024/07/29 21:03:49 by fdacax-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void test_mlx(void)
{
	void *mlx_ptr;
	void *win_ptr;

	mlx_ptr = mlx_init();
	if (mlx_ptr == NULL)
		return;
	win_ptr = mlx_new_window(mlx_ptr, 800, 600, "Hello, World!");
	if (win_ptr == NULL)
		return;
	mlx_string_put(mlx_ptr, win_ptr, 375, 290, 0xF0FFFF, "EH Tudo PUTA!");


	mlx_loop(mlx_ptr);
}

