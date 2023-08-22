/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 10:46:35 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/06/11 09:04:43 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

# include "struct.h"
# include "../libprintf/src/ft_printf.h"

//GNL
int			isbreak(char *buffer);
char		*malloc_str(t_strlist *list, char *buffer, int sz);
char		*fill_str(t_strlist *list, char *buffer, int sz, char *res);
char		*get_next_line(int fd);
char		*return_error(t_strlist *list, char *buffer, int sz, int cleanbuff);
void		ft_lstadd_back_gnl(t_strlist **alst, t_strlist *new);
void		ft_lstclear_gnl(t_strlist **lst);
void		ft_buffmove(char *buffer, int sz);
t_strlist	*ft_lstnew_gnl(char *content);

//Parsing
int			line_ones(char *line, int map_length);
int			map_playable(char **map, t_mapspecs *specs);
int			map_playable_rec(char **map, t_mapspecs *specs, int i, int j);
int			get_player_x(char **map);
int			get_player_y(char **map);
int			check_map(t_mapspecs *specs, char *map_name);
int			check_line(char *line, t_mapspecs *specs);
int			check_mapname(char *map_name);
void		init_specs(t_mapspecs *specs, char *line);
void		check_tile(char *tile, t_mapspecs *specs);
void		free_check_map(int fd, char *line);
void		free_parsing(t_mapspecs *specs, t_map *mapstruct, int i);
char		**fill_map(t_mapspecs *specs, char *map_name);
t_map		*parsing(char *map_name);

//Display
void		display_map(char **map, t_args *args);
void		display_tile(char tile, t_args *args, int i, int j);

//Utils
int			init_tiles(t_window *window, t_tiles *tiles);
int			init_all(t_args *args);
void		init_tiles_to_null(t_tiles *tiles);
void		init_player(char **map, t_player *player);
void		malloc_struct(t_args *args);
void		free_map(char **map);
void		clean(t_args *args);
void		clean_tiles(t_args *args);

//Commands
int			mlx_close(t_args *args);
int			mlx_play(int keycode, t_args *args);
void		move_d(char **map, t_player *player, \
			t_window *window, t_tiles *tiles);
void		move_u(char **map, t_player *player, \
			t_window *window, t_tiles *tiles);
void		move_l(char **map, t_player *player, \
			t_window *window, t_tiles *tiles);
void		move_r(char **map, t_player *player, \
			t_window *window, t_tiles *tiles);

#endif