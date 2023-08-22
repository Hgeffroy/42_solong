/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 17:26:24 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/06/10 17:35:40 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_tiles_to_null(t_tiles *tiles)
{
	tiles->grass = NULL;
	tiles->wall = NULL;
	tiles->player = NULL;
	tiles->collectible = NULL;
	tiles->exit = NULL;
}
