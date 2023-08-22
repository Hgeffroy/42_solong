/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 12:58:17 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/06/10 19:09:49 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_specs(t_mapspecs *specs, char *line)
{
	specs->e = 0;
	specs->p = 0;
	specs->c = 0;
	specs->map_height = 0;
	specs->map_length = ft_strlen(line) - 1;
	return ;
}

int	init_tiles(t_window *window, t_tiles *tiles)
{
	init_tiles_to_null(tiles);
	tiles->collectible = mlx_xpm_file_to_image(window->mlx, \
	"img/chest_close.xpm", &(tiles->width), &(tiles->height));
	if (!(tiles->collectible))
		return (-1);
	tiles->exit = mlx_xpm_file_to_image(window->mlx, \
	"img/door_close.xpm", &(tiles->width), &(tiles->height));
	if (!(tiles->exit))
		return (-1);
	tiles->player = mlx_xpm_file_to_image(window->mlx, \
	"img/player.xpm", &(tiles->width), &(tiles->height));
	if (!(tiles->player))
		return (-1);
	tiles->grass = mlx_xpm_file_to_image(window->mlx, \
	"img/grass.xpm", &(tiles->width), &(tiles->height));
	if (!(tiles->grass))
		return (-1);
	tiles->wall = mlx_xpm_file_to_image(window->mlx, \
	"img/walls.xpm", &(tiles->width), &(tiles->height));
	if (!(tiles->wall))
		return (-1);
	return (1);
}

void	init_player(char **map, t_player *player)
{
	int	i;
	int	j;

	player->c = 0;
	player->moves = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] && map[i][j] != '\n')
		{
			if (map[i][j] == 'C')
				player->c += 1;
			else if (map[i][j] == 'P')
			{
				player->x = j;
				player->y = i;
			}
			j++;
		}
		i++;
	}
	return ;
}

void	malloc_struct(t_args *args)
{
	args->tiles = (t_tiles *)malloc(sizeof(t_tiles));
	if (!(args->tiles))
		return ;
	args->window = (t_window *)malloc(sizeof(t_window));
	if (!(args->window))
	{
		free(args->tiles);
		return ;
	}
	args->player = (t_player *)malloc(sizeof(t_player));
	if (!(args->player))
	{
		free(args->tiles);
		free(args->window);
		return ;
	}
}

int	init_all(t_args *args)
{
	malloc_struct(args);
	if (!(args->tiles))
		return (0);
	args->window->mlx = mlx_init();
	if (!(args->window->mlx))
		return (-1);
	if (init_tiles(args->window, args->tiles) == -1)
		return (-2);
	args->window->win = mlx_new_window(args->window->mlx, \
	args->map->len * args->tiles->width, \
	args->map->height * args->tiles->height, "So_long");
	if (!(args->window->win))
		return (-3);
	init_player(args->map->map, args->player);
	return (1);
}
