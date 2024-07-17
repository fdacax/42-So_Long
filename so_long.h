/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdacax-m <fdacax-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:28:48 by fdacax-m          #+#    #+#             */
/*   Updated: 2024/06/17 15:28:48 by fdacax-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

# include "libft/libft.h"
# include "mlx/mlx.h"
# include <stdbool.h>
# include <stdio.h>
# include <X11/keysym.h>
# include <X11/Xlib.h>
#include <fcntl.h>

typedef enum errors
{
		EXTENSION,
		NO_FILE,
		EMPTY,
		NO_RECTANGULAR,
		NO_CLOSED,
		W_ENTITIES,
		I_ENTITIES,

}			t_errors;

typedef struct game
{
	char	**map;
	int 	lines;
	int 	total_len;
	int 	player;
	int		coins;
	int		exit;

}	t_game;
/* ************************************************************************** */
/*                              check_error                                   */
/* ************************************************************************** */

bool		check_extension(char *file);
bool		check_file_exist(char *file);
void		check_file(char *file);
void		handler_errors(t_errors error);

/* ************************************************************************** */
/*                              check_error2                                  */
/* ************************************************************************** */

void		count_lines(char *file, t_game *game);
void		count_letter(t_game *game);
int			ft_str_line(char *game);
void		check_map_close(t_game *game);
void		check_entities(t_game *game);
void		check_invalid_entities(t_game *game);

void	dps_eu_penso(char *file, t_game *game);
void	init(t_game **game);
#endif
