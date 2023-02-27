/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_keypress.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maujogue <maujogue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 17:27:25 by maujogue          #+#    #+#             */
/*   Updated: 2023/02/23 16:40:34 by maujogue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	check_collect_exit(t_game *game, char c)
{
	if (c == 'U' && game->map[game->p_pos->y - 1][game->p_pos->x] == 'C')
		game->nb_collectibles--;
	if (c == 'D' && game->map[game->p_pos->y + 1][game->p_pos->x] == 'C')
		game->nb_collectibles--;
	if (c == 'L' && game->map[game->p_pos->y][game->p_pos->x - 1] == 'C')
		game->nb_collectibles--;
	if (c == 'R' && game->map[game->p_pos->y][game->p_pos->x + 1] == 'C')
		game->nb_collectibles--;
	if (game->nb_collectibles == 0)
		game->win = 1;
	if (c == 'U' && game->map[game->p_pos->y - 1][game->p_pos->x] == 'E'
		&& game->win == 1)
		game->win = 0;
	if (c == 'D' && game->map[game->p_pos->y + 1][game->p_pos->x] == 'E'
		&& game->win == 1)
		game->win = 0;
	if (c == 'L' && game->map[game->p_pos->y][game->p_pos->x - 1] == 'E'
		&& game->win == 1)
		game->win = 0;
	if (c == 'R' && game->map[game->p_pos->y][game->p_pos->x + 1] == 'E'
		&& game->win == 1)
		game->win = 0;
	if (game->win == 0)
		return (0);
	return (1);
}

void	move_bro(t_game *game, char c)
{
	if (check_collect_exit(game, c) == 1)
	{
		game->map[game->p_pos->y][game->p_pos->x] = '0';
		if (c == 'U')
			game->map[--game->p_pos->y][game->p_pos->x] = 'P';
		if (c == 'D')
			game->map[++game->p_pos->y][game->p_pos->x] = 'P';
		if (c == 'L')
		{
			game->map[game->p_pos->y][--game->p_pos->x] = 'P';
			game->p_pos->data = 'L';
		}
		if (c == 'R')
		{
			game->map[game->p_pos->y][++game->p_pos->x] = 'P';
			game->p_pos->data = 'R';
		}
	}
	draw_images(game);
}

int	ft_keypress(int keycode, t_game *game)
{
	if (keycode == 65307 || game->win == 0)
		close_win(game);
	if (keycode == 119 && game->map[game->p_pos->y - 1][game->p_pos->x] != '1'
		&& (game->map[game->p_pos->y - 1][game->p_pos->x] != 'E'
			|| game->win == 1))
		move_bro(game, 'U');
	if (keycode == 115 && game->map[game->p_pos->y + 1][game->p_pos->x] != '1'
		&& (game->map[game->p_pos->y + 1][game->p_pos->x] != 'E'
			|| game->win == 1))
		move_bro(game, 'D');
	if (keycode == 97 && game->map[game->p_pos->y][game->p_pos->x - 1] != '1'
		&& (game->map[game->p_pos->y][game->p_pos->x - 1] != 'E'
			|| game->win == 1))
		move_bro(game, 'L');
	if (keycode == 100 && game->map[game->p_pos->y][game->p_pos->x + 1] != '1'
		&& (game->map[game->p_pos->y][game->p_pos->x + 1] != 'E'
			|| game->win == 1))
		move_bro(game, 'R');
	if (keycode == 100 || keycode == 97 || keycode == 115 || keycode == 119)
		if (draw_count(game) == 1)
			return (1);
	return (0);
}

int	close_win(t_game *game)
{
	free_exit(game);
	return (0);
}

void	check_keypress(t_game *game)
{
	mlx_hook(game->mlx_win, 17, 1L << 17, close_win, game);
	mlx_hook(game->mlx_win, 2, 1L << 0, ft_keypress, game);
}
