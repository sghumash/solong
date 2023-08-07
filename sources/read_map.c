/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghumash <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 22:24:18 by sghumash          #+#    #+#             */
/*   Updated: 2023/08/02 15:13:49 by sghumash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

static char	**func(char *holder_map, char **map, t_linee linee, int fd)
{
	char	*holder;
	int		i;

	i = 0;
	holder = holder_map;
	holder_map = ft_strtrim(holder_map, "\n");
	while (holder_map[i + 1])
	{
		if (holder_map[i] == '\n' && holder_map[i + 1] == '\n')
			ft_error();
		i++;
	}
	map = ft_split(holder_map, '\n');
	if (!map)
		return (0);
	if (!*map || !holder_map || linee.linesize < 3)
		ft_error();
	free(holder);
	free(holder_map);
	close(fd);
	return (map);
}

char	**read_map(char *path)
{
	int		fd;
	t_linee	linee;
	char	*holder_map;
	char	*holder;
	char	**map;

	map = NULL;
	linee.linesize = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	holder_map = ft_strdup("");
	while (1)
	{
		linee.line = get_next_line(fd);
		if (!linee.line)
			break ;
		linee.linesize++;
		holder = holder_map;
		holder_map = ft_strjoin(holder, linee.line);
		free(linee.line);
		free(holder);
	}
	map = func(holder_map, map, linee, fd);
	return (map);
}
