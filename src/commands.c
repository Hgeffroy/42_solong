/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 08:30:46 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/06/10 19:05:59 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	mlx_close(t_args *args)
{
	clean (args);
	exit (0);
}

int	mlx_play(int keycode, t_args *args)
{
	if (keycode == up_key
		&& args->map->map[args->player->y - 1][args->player->x] != '1')
		move_u(args->map->map, args->player, args->window, args->tiles);
	else if (keycode == left_key
		&& args->map->map[args->player->y][args->player->x - 1] != '1')
		move_l(args->map->map, args->player, args->window, args->tiles);
	else if (keycode == down_key
		&& args->map->map[args->player->y + 1][args->player->x] != '1')
		move_d(args->map->map, args->player, args->window, args->tiles);
	else if (keycode == right_key
		&& args->map->map[args->player->y][args->player->x + 1] != '1')
		move_r(args->map->map, args->player, args->window, args->tiles);
	else if (keycode == esc_key)
		mlx_close(args);
	if (args->map->map[args->player->y][args->player->x] == 'E'
		&& args->player->c == 0)
	{
		ft_printf("Je mets un message car Clemence l'a demande\n");
		mlx_close(args);
	}
	return (0);
}
