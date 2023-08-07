/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghumash <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 12:02:51 by sghumash          #+#    #+#             */
/*   Updated: 2023/08/07 20:06:30 by sghumash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill(char **tab, t_coord size, t_coord cur, char to_fill)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x
		|| (tab[cur.y][cur.x] != to_fill && tab[cur.y][cur.x] != 'C'
			&& tab[cur.y][cur.x] != '0'))
		return ;
	tab[cur.y][cur.x] = '-';
	fill(tab, size, (t_coord){cur.x - 1, cur.y}, to_fill);
	fill(tab, size, (t_coord){cur.x + 1, cur.y}, to_fill);
	fill(tab, size, (t_coord){cur.x, cur.y - 1}, to_fill);
	fill(tab, size, (t_coord){cur.x, cur.y + 1}, to_fill);
}

void	flood_fill(char **tab, t_coord size, t_coord begin)
{
	fill(tab, size, begin, tab[begin.y][begin.x]);
}
