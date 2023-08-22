/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 10:04:21 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/06/19 08:57:45 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**fill_map(t_mapspecs *specs, char *map_name)
{
	char	**map;
	int		fd;
	int		i;

	map = (char **)malloc(sizeof(char *) * (specs->map_height + 1));
	if (!map)
	{
		free(specs);
		return (NULL);
	}
	i = -1;
	fd = open(map_name, O_RDONLY);
	while (++i < specs->map_height)
	{
		map[i] = get_next_line(fd);
		if (!(map[i]))
		{
			free(specs);
			free_map(map);
			return (NULL);
		}
	}
	close(fd);
	map[i] = NULL;
	return (map);
}

int	map_playable(char **map, t_mapspecs *specs)
{
	int		i;
	char	**map_to_check;

	map_to_check = (char **)malloc(sizeof(char *) * (specs->map_height + 1));
	if (!map_to_check)
	{
		ft_printf("Malloc failed\n");
		free_map(map);
		return (-1);
	}
	i = -1;
	while (map[++i])
		map_to_check[i] = ft_strdup(map[i]);
	map_to_check[i] = NULL;
	if (map_playable_rec(map_to_check, specs, \
	get_player_y(map), get_player_x(map)) == -1)
	{
		free_map(map);
		free_map(map_to_check);
		return (-1);
	}
	free_map(map_to_check);
	return (1);
}

int	map_playable_rec(char **map, t_mapspecs *specs, int i, int j)
{
	check_tile(&map[i][j], specs);
	if (map[i - 1][j] != '1')
		map_playable_rec(map, specs, i - 1, j);
	if (map[i + 1][j] != '1')
		map_playable_rec(map, specs, i + 1, j);
	if (map[i][j - 1] != '1')
		map_playable_rec(map, specs, i, j - 1);
	if (map[i][j + 1] != '1')
		map_playable_rec(map, specs, i, j + 1);
	if (specs->p + specs->e + specs->c == 0)
		return (1);
	else
		return (-1);
}

int	check_map(t_mapspecs *specs, char *map_name)
{
	char	*line;
	int		fd;

	fd = open(map_name, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		return (free_check_map(fd, line), -1);
	init_specs(specs, line);
	if (line_ones(line, specs->map_length) == -1)
		return (free_check_map(fd, line), -1);
	specs->map_height += 1;
	while ((int)ft_strlen(line) == specs->map_length + 1)
	{
		if (check_line(line, specs) < 1)
			return (free_check_map(fd, line), -1);
		line = get_next_line(fd);
	}
	if (line_ones(line, specs->map_length) == -1 || \
	specs->e != 1 || specs->p != 1 || specs->c < 1)
		return (free_check_map(fd, line), -1);
	free(line);
	close(fd);
	return (1);
}

t_map	*parsing(char *map_name)
{
	t_mapspecs	*specs;
	t_map		*mapstruct;

	if (check_mapname(map_name) < 0)
		return (NULL);
	specs = (t_mapspecs *)malloc(sizeof(t_mapspecs));
	if (!specs)
		return (NULL);
	mapstruct = (t_map *)malloc(sizeof(t_map));
	if (!mapstruct)
		return (free_parsing(specs, mapstruct, 0), NULL);
	if (check_map(specs, map_name) < 0)
		return (free_parsing(specs, mapstruct, 1), NULL);
	mapstruct->map = fill_map(specs, map_name);
	if (!(mapstruct->map))
		return (free_parsing(specs, mapstruct, 0), NULL);
	if (map_playable(mapstruct->map, specs) < 0)
		return (free_parsing(specs, mapstruct, 2), NULL);
	mapstruct->height = specs->map_height;
	mapstruct->len = specs->map_length;
	mapstruct->c = specs->c;
	free(specs);
	return (mapstruct);
}
