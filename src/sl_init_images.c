/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_init_images.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maujogue <maujogue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:23:39 by maujogue          #+#    #+#             */
/*   Updated: 2023/02/23 17:28:14 by maujogue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

static void	init_images_bro(t_game *game)
{
	game->images->bro_l = mlx_xpm_file_to_image(game->mlx,
			"./images/bro_l.xpm", &game->img_height, &game->img_height);
	game->images->bro_r = mlx_xpm_file_to_image(game->mlx,
			"./images/bro_r.xpm", &game->img_height, &game->img_height);
	game->images->bro_jetpack_l = mlx_xpm_file_to_image(game->mlx,
			"./images/bro_jetpack_l.xpm", &game->img_height, &game->img_height);
	game->images->bro_jetpack_r = mlx_xpm_file_to_image(game->mlx,
			"./images/bro_jetpack_r.xpm", &game->img_height, &game->img_height);
	game->images->collectible = mlx_xpm_file_to_image(game->mlx,
			"./images/collectible.xpm", &game->img_height, &game->img_height);
	game->images->exit = mlx_xpm_file_to_image(game->mlx,
			"./images/exit.xpm", &game->img_height, &game->img_height);
	game->images->exit_flag = mlx_xpm_file_to_image(game->mlx,
			"./images/exit_flag.xpm", &game->img_height, &game->img_height);
	game->images->exit_title = mlx_xpm_file_to_image(game->mlx,
			"./images/exit_title.xpm",
			&game->big_img_height, &game->big_img_height);
}

int	init_images(t_game *game)
{
	game->images->block = mlx_xpm_file_to_image(game->mlx,
			"./images/block.xpm", &game->img_height, &game->img_height);
	game->images->grass = mlx_xpm_file_to_image(game->mlx,
			"./images/grass.xpm", &game->img_height, &game->img_height);
	game->images->earth = mlx_xpm_file_to_image(game->mlx,
			"./images/earth.xpm", &game->img_height, &game->img_height);
	game->images->cloud = mlx_xpm_file_to_image(game->mlx,
			"./images/cloud.xpm", &game->img_height, &game->img_height);
	game->images->sky = mlx_xpm_file_to_image(game->mlx,
			"./images/sky.xpm", &game->img_height, &game->img_height);
	init_images_bro(game);
	if (!game->images->sky || !game->images->cloud || !game->images->earth
		|| !game->images->grass || !game->images->block || !game->images->bro_l
		|| !game->images->bro_r || !game->images->bro_jetpack_l
		|| !game->images->bro_jetpack_r || !game->images->collectible
		|| !game->images->exit || !game->images->exit_flag
		|| !game->images->exit_title)
		exit_error(game, "Error\nMalloc Error\n");
	return (0);
}

static void	clear_images_textures(t_game *game)
{
	if (game->images->exit_flag)
		mlx_destroy_image(game->mlx, game->images->exit_flag);
	if (game->images->exit_title)
		mlx_destroy_image(game->mlx, game->images->exit_title);
	if (game->images->block)
		mlx_destroy_image(game->mlx, game->images->block);
	if (game->images->grass)
		mlx_destroy_image(game->mlx, game->images->grass);
	if (game->images->earth)
		mlx_destroy_image(game->mlx, game->images->earth);
	if (game->images->cloud)
		mlx_destroy_image(game->mlx, game->images->cloud);
	if (game->images->sky)
		mlx_destroy_image(game->mlx, game->images->sky);
}

void	clear_images(t_game *game)
{
	if (game->images->bro_l)
		mlx_destroy_image(game->mlx, game->images->bro_l);
	if (game->images->bro_r)
		mlx_destroy_image(game->mlx, game->images->bro_r);
	if (game->images->bro_jetpack_l)
		mlx_destroy_image(game->mlx, game->images->bro_jetpack_l);
	if (game->images->bro_jetpack_r)
		mlx_destroy_image(game->mlx, game->images->bro_jetpack_r);
	if (game->images->collectible)
		mlx_destroy_image(game->mlx, game->images->collectible);
	if (game->images->exit)
		mlx_destroy_image(game->mlx, game->images->exit);
	clear_images_textures(game);
}
