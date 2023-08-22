/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 09:16:15 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/06/10 12:25:32 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_d(char **map, t_player *player, t_window *window, t_tiles *tiles)
{
	if (map[player->y][player->x] == 'E')
		mlx_put_image_to_window(window->mlx, window->win, \
		tiles->exit, player->x * tiles->width, player->y * tiles->height);
	else
		mlx_put_image_to_window(window->mlx, window->win, \
		tiles->grass, player->x * tiles->width, player->y * tiles->height);
	player->y += 1;
	mlx_put_image_to_window(window->mlx, window->win, \
	tiles->player, player->x * tiles->width, player->y * tiles->height);
	if (map[player->y][player->x] == 'C')
	{
		map[player->y][player->x] = '0';
		player->c -= 1;
	}
	player->moves += 1;
	ft_printf("Player moves : %d\n", player->moves);
}

void	move_u(char **map, t_player *player, t_window *window, t_tiles *tiles)
{
	if (map[player->y][player->x] == 'E')
		mlx_put_image_to_window(window->mlx, window->win, \
		tiles->exit, player->x * tiles->width, player->y * tiles->height);
	else
		mlx_put_image_to_window(window->mlx, window->win, \
		tiles->grass, player->x * tiles->width, player->y * tiles->height);
	player->y -= 1;
	mlx_put_image_to_window(window->mlx, window->win, \
	tiles->player, player->x * tiles->width, player->y * tiles->height);
	if (map[player->y][player->x] == 'C')
	{
		map[player->y][player->x] = '0';
		player->c -= 1;
	}
	player->moves += 1;
	ft_printf("Player moves : %d\n", player->moves);
}

void	move_l(char **map, t_player *player, t_window *window, t_tiles *tiles)
{
	if (map[player->y][player->x] == 'E')
		mlx_put_image_to_window(window->mlx, window->win, \
		tiles->exit, player->x * tiles->width, player->y * tiles->height);
	else
		mlx_put_image_to_window(window->mlx, window->win, \
		tiles->grass, player->x * tiles->width, player->y * tiles->height);
	player->x -= 1;
	mlx_put_image_to_window(window->mlx, window->win, \
	tiles->player, player->x * tiles->width, player->y * tiles->height);
	if (map[player->y][player->x] == 'C')
	{
		map[player->y][player->x] = '0';
		player->c -= 1;
	}
	player->moves += 1;
	ft_printf("Player moves : %d\n", player->moves);
}

void	move_r(char **map, t_player *player, t_window *window, t_tiles *tiles)
{
	if (map[player->y][player->x] == 'E')
		mlx_put_image_to_window(window->mlx, window->win, \
		tiles->exit, player->x * tiles->width, player->y * tiles->height);
	else
		mlx_put_image_to_window(window->mlx, window->win, \
		tiles->grass, player->x * tiles->width, player->y * tiles->height);
	player->x += 1;
	mlx_put_image_to_window(window->mlx, window->win, \
	tiles->player, player->x * tiles->width, player->y * tiles->height);
	if (map[player->y][player->x] == 'C')
	{
		map[player->y][player->x] = '0';
		player->c -= 1;
	}
	player->moves += 1;
	ft_printf("Player moves : %d\n", player->moves);
}
