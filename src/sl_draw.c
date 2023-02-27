/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maujogue <maujogue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:21:41 by maujogue          #+#    #+#             */
/*   Updated: 2023/02/23 17:31:17 by maujogue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	choose_image_bro(t_game *game, int i, int j)
{
	if (game->map[j][i] == 'P'
		&& game->map[j + 1][i] == '1' && game->p_pos->data == 'R')
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->images->bro_r, 100 * i, 100 * j);
	else if (game->map[j][i] == 'P'
		&& game->map[j + 1][i] == '1' && game->p_pos->data == 'L')
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->images->bro_l, 100 * i, 100 * j);
	else if (game->map[j][i] == 'P' && game->p_pos->data == 'R')
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->images->bro_jetpack_r, 100 * i, 100 * j);
	else if (game->map[j][i] == 'P' && game->p_pos->data == 'L')
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->images->bro_jetpack_l, 100 * i, 100 * j);
	if (game->map[j][i] == 'E')
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->images->exit, 100 * i, 100 * j);
	if (game->map[j][i] == 'E' && (game->win == 1 || game->win == 0))
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->images->exit_flag, 100 * i, 100 * j);
	if (game->win == 0)
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->images->exit_title, (game->width * 100 - 400) / 2,
			(game->height * 100 - 100) / 2);
}

void	choose_image(t_game *game, int i, int j)
{
	if (game->map[j][i] == '1' && j == game->height - 1)
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->images->grass, 100 * i, 100 * j);
	if (game->map[j][i] == '1' && (i == 0 || i == game->width - 1))
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->images->earth, 100 * i, 100 * j);
	else if (game->map[j][i] == '1'
		&& i > 0 && j > 0 && j < game->height - 1 && i < game->width - 1)
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->images->block, 100 * i, 100 * j);
	if (game->map[j][i] == '0' || game->map[j][i] == 'P'
		|| game->map[j][i] == 'E' || (j == 0 && i > 0 && i < game->width - 1))
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->images->sky, 100 * i, 100 * j);
	if (game->map[j][i] == '1' && j == 0 && i > 0 && i < game->width - 1)
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->images->cloud, 100 * i, 100 * j);
	if (game->map[j][i] == 'C')
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->images->collectible, 100 * i, 100 * j);
	choose_image_bro(game, i, j);
}

int	draw_count(t_game *game)
{
	char	*str;

	game->nb_move++;
	str = ft_itoa(game->nb_move);
	if (!str)
		exit_error(game, "Error\nMalloc Error\n");
	ft_printf("%d\n", game->nb_move);
	draw_images(game);
	mlx_string_put(game->mlx, game->mlx_win, 30, 30, 0xFF0000, str);
	free(str);
	return (0);
}

void	draw_images(t_game *game)
{
	int		i;
	int		j;

	j = 0;
	while (game->map[j])
	{
		i = 0;
		while (game->map[j][i])
		{
			choose_image(game, i, j);
			i++;
		}
		j++;
	}
}
