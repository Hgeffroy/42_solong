/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 13:57:30 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/06/19 08:57:32 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_map(char **map, t_args *args)
{
	int		i;
	int		j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] && map[i][j] != '\n')
		{
			display_tile(map[i][j], args, i, j);
			j++;
		}
		i++;
	}
}

void	display_tile(char tile, t_args *args, int i, int j)
{
	if (tile == 'P')
		mlx_put_image_to_window(args->window->mlx, args->window->win, \
		args->tiles->player, j * args->tiles->width, i * args->tiles->height);
	else if (tile == '1')
		mlx_put_image_to_window(args->window->mlx, args->window->win, \
		args->tiles->wall, j * args->tiles->width, i * args->tiles->height);
	else if (tile == 'C')
		mlx_put_image_to_window(args->window->mlx, args->window->win, \
		args->tiles->collectible, j * args->tiles->width, \
		i * args->tiles->height);
	else if (tile == 'E')
		mlx_put_image_to_window(args->window->mlx, args->window->win, \
		args->tiles->exit, j * args->tiles->width, i * args->tiles->height);
	if (tile == '0')
		mlx_put_image_to_window(args->window->mlx, args->window->win, \
		args->tiles->grass, j * args->tiles->width, i * args->tiles->height);
}
