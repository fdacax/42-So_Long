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
		NO_ENCLOSED,
		W_ENTITIES,
		I_ENTITIES,
		PATH,

}			t_errors;

typedef struct game
{
	char 	**full_map;
	char	**map;
	int 	lines;
	int 	all_lines;
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
void	handler_errors(t_game *game, t_errors error);

/* ************************************************************************** */
/*                              check_error2                                  */
/* ************************************************************************** */

void		count_lines(char *file, t_game *game);
void		count_letter(t_game *game);
int			ft_str_line(char *game);
void		check_map_enclosed(t_game *game);
void		check_entities(t_game *game);
void		check_invalid_entities(t_game *game);

void		init_full_map(char *file, t_game *game);
void		init(t_game **game);
void		init_map(t_game *game);
void		nl_finder_inside_map(t_game *game);

void		flood_fill(char **cp_map, int i, int j);
void		copy_map(t_game *game);
void		validate_path(char **cp_map, t_game *game);

void		find_player(t_game *game, int player[2]);
void		free_maps(t_game *game);
void		free_cp_map(char **cp_map);

#endif
