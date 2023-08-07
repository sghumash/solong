/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghumash <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 22:24:18 by sghumash          #+#    #+#             */
/*   Updated: 2023/07/25 22:24:28 by sghumash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include "../libraries/libft/libft.h"
# include <fcntl.h>
# include <unistd.h>

typedef struct s_coord
{
	int		x;
	int		y;
}	t_coord;

typedef struct s_linee
{
	char	*line;
	int		linesize;
}	t_linee;

typedef struct s_cord
{
	t_coord	player;
	t_coord	exitt;
}	t_cord;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	char	**tab;
	void	*img_backg;
	void	*img_wall;
	void	*img_player;
	void	*img_colect;
	void	*img_exit;
	int		map_w;
	int		map_h;
	int		img_w;
	int		img_h;
	int		n_colect;
	int		n_player;
	int		n_exit;
	int		x_player;
	int		y_player;
	int		moves;
	int		endgame;
	t_cord	cords;
}	t_game;

# define KEY_ESC 53
# define KEY_Q 12

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

# define KEY_UP 126
# define KEY_LEFT 123
# define KEY_DOWN 125
# define KEY_RIGHT 124

void	img_draw(t_game *game, void *image, int x, int y);
int		map_draw(t_game *game);
void	game_init(t_game *game);
char	**read_map(char *path);
int		map_checker(t_game *game);
void	gameplay(t_game *game);
void	player_w(t_game *game);
void	player_d(t_game *game);
void	player_s(t_game *game);
void	player_a(t_game *game);
int		exit_game(t_game *game);
void	free_map(char **map);
void	ft_error(void);
void	map_cord_finder(t_game *game);
void	flood_fill(char **tab, t_coord size, t_coord begin);
void	player_can_win(char **map);

#endif
