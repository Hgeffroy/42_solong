/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 13:55:58 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/06/19 08:57:56 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_args		*args;
	int			err;

	args = (t_args *)malloc(sizeof(t_args));
	if (argc != 2 || !args)
	{
		ft_printf("Merci d'arreter les tests a la con, Cordialement\n");
		return (free(args), -1);
	}
	args->map = parsing(argv[1]);
	if (!(args->map))
		return (free(args), -1);
	err = init_all(args);
	if (err == -1)
		return (free_map(args->map->map), -1);
	else if (err < -1)
		return (clean(args), -1);
	display_map(args->map->map, args);
	mlx_key_hook(args->window->win, &mlx_play, args);
	mlx_hook(args->window->win, 17, 1L << 17, &mlx_close, args);
	mlx_loop(args->window->mlx);
}
