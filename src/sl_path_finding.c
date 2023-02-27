/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_path_finding.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maujogue <maujogue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 13:17:15 by maujogue          #+#    #+#             */
/*   Updated: 2023/02/23 17:27:19 by maujogue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	find_path(t_game *game, char **cpy, int px, int py)
{
	if (cpy[py][px] == 'C')
		game->nb_collectibles--;
	cpy[py][px] = '1';
	if (cpy[py][px + 1] == 'E' || cpy[py][px - 1] == 'E'
		|| cpy[py - 1][px] == 'E' || cpy[py + 1][px] == 'E')
		game->nb_exit--;
	if (cpy[py][px + 1] == '0' || cpy[py][px + 1] == 'C')
		find_path(game, cpy, px + 1, py);
	if (cpy[py][px - 1] == '0' || cpy[py][px - 1] == 'C')
		find_path(game, cpy, px - 1, py);
	if (cpy[py + 1][px] == '0' || cpy[py + 1][px] == 'C')
		find_path(game, cpy, px, py + 1);
	if (cpy[py - 1][px] == '0' || cpy[py - 1][px] == 'C')
		find_path(game, cpy, px, py - 1);
	if (game->nb_exit < 0 && game->nb_collectibles == 0)
		return (0);
	return (1);
}

void	check_path(t_game *game)
{
	char	**cpy;

	cpy = ft_split(game->str, '\n');
	if (!cpy)
		exit_error(game, "Error\nMalloc Error");
	if (find_path(game, cpy, game->p_pos->x, game->p_pos->y))
	{
		free_str_array(cpy);
		exit_error(game, "Error\nMap does not have a winable path\n");
	}
	free_str_array(cpy);
}
