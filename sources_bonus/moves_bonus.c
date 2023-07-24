#include "so_long_bonus.h"

void	display_moves(t_game *game)
{
	char	*str;

	str = ft_itoa(game->moves);
	mlx_string_put(game->mlx, game->win, 25, 20, 0xFFFFFF, "MOVES: ");
	mlx_string_put(game->mlx, game->win, 70, 20, 0xFFFFFF, str);
	free(str);
}
