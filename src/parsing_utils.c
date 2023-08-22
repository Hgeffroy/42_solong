/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 14:59:34 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/06/19 08:57:40 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	line_ones(char *line, int map_length)
{
	int	i;

	i = -1;
	if (!line)
		return (-1);
	while (++i < map_length)
	{
		if (line[i] != '1')
			return (-1);
	}
	if (line[i] != 0 && line[i] != '\n')
		return (-1);
	return (1);
}

int	check_line(char *line, t_mapspecs *specs)
{
	int	i;

	i = -1;
	while (++i < specs->map_length)
	{
		if (line[i] != '0' && line[i] != '1' && line[i] != 'C' \
			&& line[i] != 'P' && line[i] != 'E')
			return (-1);
		else if ((i == 0 || i == specs->map_length - 1) && line[i] != '1')
			return (-1);
		else if (line[i] == 'C')
			specs->c += 1;
		else if (line[i] == 'P')
			specs->p += 1;
		else if (line[i] == 'E')
			specs->e += 1;
	}
	specs->map_height += 1;
	free(line);
	return (1);
}

void	check_tile(char *tile, t_mapspecs *specs)
{
	if (*tile == 'P')
		specs->p -= 1;
	else if (*tile == 'C')
		specs->c -= 1;
	else if (*tile == 'E')
		specs->e -= 1;
	*tile = '1';
}

int	check_mapname(char *map_name)
{
	int	len;

	len = ft_strlen(map_name);
	if (ft_strncmp(map_name + len - 4, ".ber", 5) != 0)
	{
		ft_printf("Wrong map name\n");
		return (-1);
	}
	return (1);
}
