/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghumash <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 12:32:29 by sghumash          #+#    #+#             */
/*   Updated: 2023/08/06 12:32:31 by sghumash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_search2(char **str)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	while (str[i])
	{
		j = 1;
		while (str[i][j])
		{
			if (str[i][j] == 'E')
			{
				if (str[i + 1][j] != '-' && str[i - 1][j] != '-' &&
					str[i][j - 1] != '-' && str[i][j + 1] != '-')
					ft_error();
			}
			j++;
		}
		i++;
	}
}

void	player_can_win(char **map)
{
	int	i;
	int	j;

	j = 0;
	while (map[j] != NULL)
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == 'P' || map[j][i] == 'C')
				ft_error();
			i++;
		}
		j++;
	}
	ft_search2(map);
}
