/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghumash <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 22:39:10 by sghumash          #+#    #+#             */
/*   Updated: 2023/08/02 14:50:10 by sghumash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	argv_checker(char *argv)
{
	int	i;

	if (!argv)
		return (0);
	i = 0;
	while (argv[i])
		i++;
	i -= 1;
	if (argv[i] == 'r' && argv[i - 1] == 'e' && argv[i - 2] == 'b'
		&& argv [i - 3] == '.')
		return (1);
	return (0);
}

int	ft_errorr(int n)
{
	if (n == 1)
	{
		write(2, "Error\nInvalid Map\n", 18);
		exit(1);
	}
	else if (n == 0)
	{
		write(2, "Error\nInvalid Sytax\n", 20);
		exit(1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 2)
	{
		game.map = read_map(argv[1]);
		game.tab = read_map(argv[1]);
		if (map_checker(&game) && argv_checker(argv[1]))
		{
			map_cord_finder(&game);
			flood_fill(game.tab, game.cords.exitt, game.cords.player);
			player_can_win(game.tab);
			game_init(&game);
			gameplay(&game);
			mlx_loop(game.mlx);
		}
		else
		{
			if (game.map)
				free_map(game.map);
			ft_errorr(1);
		}
	}
	else
		ft_errorr(0);
	return (0);
}
