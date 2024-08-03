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

typedef struct s_image
{
	void	*window;
	void	*w_init;
	int		w_width;
	int		w_height;
	void	*sources[7];
	int		s_width;
	int		s_height;
	int		x;
	int		y;
}	t_image;

typedef struct s_game
{
	t_image	*image;
	char	**full_map;
	char	**map;
	int		player_pos[2];
	int		exit_pos[2];
	int		lines;
	int		all_lines;
	int		total_len;
	int		player;
	int		coins;
	int		exit;
	int		moves;

}	t_game;

/* ************************************************************************** */
/*                              map_check                                     */
/* ************************************************************************** */

void		check_file(char *file);
bool		check_file_exist(char *file);
bool		check_extension(char *file);
void		map_checker(char *file, t_game *game);

/* ************************************************************************** */
/*                              map_check2                                    */
/* ************************************************************************** */

void		check_invalid_entities(t_game *game);
void		check_entities(t_game *game);
void		check_map_enclosed(t_game *game);
void		count_letter(t_game *game);

/* ************************************************************************** */
/*                              map_check3                                    */
/* ************************************************************************** */

void		flood_fill(char **cp_map, int i, int j);
void		validate_path(char **cp_map, t_game *game);
void		copy_map(t_game *game);

/* ************************************************************************** */
/*                              map_utils                                     */
/* ************************************************************************** */

void		nl_finder_inside_map(t_game *game);
void		init_map(t_game *game);
void		init_full_map(char *file, t_game *game);
int			ft_strlen_nl(char *game);
void		count_lines(char *file, t_game *game);

/* ************************************************************************** */
/*                              map_utils2                                    */
/* ************************************************************************** */

void		find_player(t_game *game);
void		find_exit(t_game *game);

/* ************************************************************************** */
/*                              map_utils2                                    */
/* ************************************************************************** */

void		free_maps(t_game *game);
void		free_cp_map(char **cp_map);

/* ************************************************************************** */
/*                                  image                                     */
/* ************************************************************************** */

void		refresh_map(t_game *game, t_image *image, int i, int j);
void		load_map(t_image *image, t_game *game);
void		init_image(t_game *game);

/* ************************************************************************** */
/*                             image_utils                                    */
/* ************************************************************************** */

int			handler_mlx_hook(int key, t_game *game);
int			close_win_on_x(t_game *game);
void		load_sources(t_game *game, t_image *image, int i, int j);
void		init_sources(t_image *image, t_game *game);
void		init_window(t_image **image, t_game *game);

/* ************************************************************************** */
/*                                   mlx                                      */
/* ************************************************************************** */

void		free_cp_map(char **cp_map);
void		free_maps(t_game *game);
void		free_images(t_image *image);
void		p_error_mlx(char *str, t_game *game, t_image *image);
void		handler_errors(t_game *game, t_errors error);

#endif
