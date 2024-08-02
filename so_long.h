/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdacax-m <fdacax-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:28:48 by fdacax-m          #+#    #+#             */
/*   Updated: 2024/07/30 00:05:06 by fdacax-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "mlx/mlx.h"
# include <stdbool.h>
# include <stdio.h>
# include <X11/keysym.h>
# include <X11/Xlib.h>
# include <fcntl.h>

// Key Code
# define ESC 65307
# define W_KEY 119
# define S_KEY 115
# define D_KEY 100
# define A_KEY 97
# define R_ARROW 65363
# define L_ARROW 65361
# define U_ARROW 65362
# define D_ARROW 65364

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

typedef struct s_game
{
	char	**full_map;
	char	**map;
	int 	player_pos[2];
	int		lines;
	int		all_lines;
	int		total_len;
	int		player;
	int		coins;
	int		exit;
	int 	moves;

}	t_game;

typedef struct s_image
{
	void	*window;
	void	*w_init;
	int 	w_width;
	int 	w_height;
	void	*sources[7];
	int 	s_width;
	int 	s_height;
	int 	x;
	int 	y;


}	t_image;
/* ************************************************************************** */
/*                              check_error                                   */
/* ************************************************************************** */

bool		check_extension(char *file);
bool		check_file_exist(char *file);
void		check_file(char *file);
void		handler_errors(t_game *game, t_errors error);

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

void		find_player(t_game *game);
void		free_maps(t_game *game);
void		free_cp_map(char **cp_map);

void		tche_tche(char *file, t_game *game);


/* ************************************************************************** */
/*                                   mlx                                      */
/* ************************************************************************** */
int	test_mlx_hook(int key, t_game *game, t_image *image);

void		droga(t_game *game);
void		init_window(t_image **image, t_game *game);
void		p_error_mlx(char *str, t_game *game, t_image *image);
void		init_sources(t_image *image, t_game *game);
void		load_map(t_image *image, t_game *game);
void		load_sources(t_game *game, t_image *image, int i, int j);

void		refresh_map(t_game *game, t_image *image, int i,int j);

#endif
