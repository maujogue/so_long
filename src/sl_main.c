/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maujogue <maujogue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:03:16 by maujogue          #+#    #+#             */
/*   Updated: 2023/02/24 14:20:03 by maujogue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	clear_fd(void)
{
	int	fd;

	fd = -1;
	while (++fd < 1023)
		close(fd);
}

int	get_check_fd(t_game *game)
{
	int		fd;
	char	*c;

	c = malloc(sizeof(char));
	if (!c)
		exit_error(game, "Error\nMalloc Error\n");
	fd = open(game->filename, O_RDONLY);
	if (fd < 0 || fd > 1023)
	{
		free(c);
		exit_error(game, "Error\nCannot open map\n");
	}
	if (ft_strlen(ft_strnstr(game->filename, ".ber", ft_strlen(game->filename)))
		!= 4 || !read(fd, c, 1) || close (fd) < 0)
	{
		free(c);
		exit_error(game, "Error\nCannot open map\n");
	}
	fd = open(game->filename, O_RDONLY);
	free(c);
	return (fd);
}

void	init_struct_game_window(t_game *game)
{
	game->nb_collectibles = get_nb_occurences(game, 'C');
	game->height = 0;
	while (game->map[game->height])
		game->height++;
	game->nb_move = 0;
	game->img_height = 50;
	game->img_width = 50;
	game->big_img_height = 200;
	game->big_img_width = 400;
	game->win = 2;
	game->mlx = mlx_init();
	if (!game->mlx)
		exit_error(game, "Error\nMalloc Error\n");
	game->status++;
	game->mlx_win = mlx_new_window(game->mlx, game->width * 100,
			game->height * 100, "BROFORCE");
	if (!game->mlx_win)
		exit_error(game, "Error\nMalloc Error\n");
	game->status++;
	game->images = malloc(sizeof(t_images));
	if (!game->images)
		exit_error(game, "Error\nMalloc Error\n");
	game->status++;
	init_images(game);
}

void	init_struct_game(t_game *game, char *filename)
{
	game->filename = ft_strdup(filename);
	if (!game->filename)
		exit_error(game, "Error\nMalloc Error\n");
	game->status++;
	game->fd = get_check_fd(game);
	game->status++;
	game->str = parse_map(game);
	if (!game->str)
		exit_error(game, "Error\nMalloc Error\n");
	game->status++;
	game->map = ft_split(game->str, '\n');
	if (!game->map)
		exit_error(game, "Error\nMalloc Error\n");
	game->status++;
	game->nb_collectibles = get_nb_occurences(game, 'C');
	game->nb_exit = 0;
	check_map_content(game);
	game->p_pos = get_point(game, 'P');
	if (!game->p_pos)
		exit_error(game, "Error\nMalloc Error\n");
	game->status++;
	check_path(game);
	init_struct_game_window(game);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 2)
	{
		init_struct_game(&game, argv[1]);
		draw_images(&game);
		check_keypress(&game);
		mlx_loop(game.mlx);
		free_exit(&game);
	}
	else if (argc < 2)
		ft_putstr_fd("Error\nNot enough arguments (1 required)\n", 2);
	else if (argc > 2)
		ft_putstr_fd("Error\nToo much arguments (1 required)\n", 2);
	return (0);
}
