/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 15:55:02 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/06/11 09:04:22 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_check_map(int fd, char *line)
{
	free(line);
	close(fd);
}

void	free_parsing(t_mapspecs *specs, t_map *mapstruct, int i)
{
	if (mapstruct)
		free(mapstruct);
	if (specs)
		free(specs);
	if (i == 0)
		ft_printf("Error\nMap error, malloc failed\n");
	if (i == 1)
		ft_printf("Error\nMap error, wrong map format\n");
	if (i == 2)
		ft_printf("Error\nMap error, items not reachable\n");
}

void	clean_tiles(t_args *args)
{
	if (args->tiles->exit)
		mlx_destroy_image(args->window->mlx, args->tiles->exit);
	if (args->tiles->grass)
		mlx_destroy_image(args->window->mlx, args->tiles->grass);
	if (args->tiles->collectible)
		mlx_destroy_image(args->window->mlx, args->tiles->collectible);
	if (args->tiles->player)
		mlx_destroy_image(args->window->mlx, args->tiles->player);
	if (args->tiles->wall)
		mlx_destroy_image(args->window->mlx, args->tiles->wall);
	free(args->tiles);
}

void	clean(t_args *args)
{
	if (args->tiles)
		clean_tiles(args);
	if (args->player)
		free(args->player);
	if (args->map)
	{
		if (args->map->map)
			free_map(args->map->map);
		free(args->map);
	}
	if (args->window)
	{
		if (args->window->win)
			mlx_destroy_window(args->window->mlx, args->window->win);
		mlx_destroy_display(args->window->mlx);
		free(args->window->mlx);
		free(args->window);
	}
	free(args);
}
