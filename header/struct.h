/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 10:04:25 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/06/10 14:46:55 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "so_long.h"

// GNL
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

// Parsing
typedef struct s_mapspecs
{
	int	c;
	int	p;
	int	e;
	int	map_height;
	int	map_length;
	int	error;
}	t_mapspecs;

typedef struct s_map
{
	char	**map;
	int		len;
	int		height;
	int		c;
}	t_map;

//Affichage
typedef struct s_window
{
	void	*mlx;
	void	*win;
}	t_window;

typedef struct s_tiles
{
	void	*grass;
	void	*wall;
	void	*collectible;
	void	*exit;
	void	*player;
	int		width;
	int		height;
}	t_tiles;

//Jeu
typedef struct s_player
{
	int	x;
	int	y;
	int	c;
	int	moves;
}	t_player;

typedef struct s_args
{
	t_map		*map;
	t_window	*window;
	t_player	*player;
	t_tiles		*tiles;
}	t_args;

#endif
