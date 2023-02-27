/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maujogue <maujogue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 13:19:05 by maujogue          #+#    #+#             */
/*   Updated: 2023/02/23 16:42:09 by maujogue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	get_nb_occurences(t_game *game, char c)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (game->str[i])
	{
		if (game->str[i] == c)
			nb++;
		i++;
	}
	return (nb);
}

t_point	*get_point(t_game *game, char c)
{
	t_point	*point;

	point = malloc(sizeof(t_point));
	if (!point)
		exit_error(game, "Error\nMalloc Error\n");
	point->x = 0;
	point->y = 0;
	point->data = 'R';
	while (game->map[point->y][point->x])
	{
		if (game->map[point->y][point->x] == c)
			break ;
		point->x++;
		if (!game->map[point->y][point->x])
		{
			point->x = 0;
			point->y++;
		}
	}
	return (point);
}

void	free_str_array(char **array)
{
	int	i;

	if (!array)
		return ;
	i = -1;
	while (array[++i])
		free(array[i]);
	free(array);
}

void	exit_error(t_game *game, char *str)
{
	if (game->status >= 1)
		free(game->filename);
	if (game->status >= 2)
		close(game->fd);
	if (game->status >= 3)
		free(game->str);
	if (game->status >= 4)
		free_str_array(game->map);
	if (game->status >= 5)
		free(game->p_pos);
	if (game->status >= 7)
		mlx_clear_window(game->mlx, game->mlx_win);
	if (game->status >= 7)
		mlx_destroy_window(game->mlx, game->mlx_win);
	if (game->status >= 8)
		free(game->images);
	if (game->status >= 8)
		clear_images(game);
	if (game->status >= 6)
		mlx_destroy_display(game->mlx);
	if (game->status >= 6)
		free(game->mlx);
	write(2, str, ft_strlen(str));
	clear_fd();
	exit(EXIT_FAILURE);
}

void	free_exit(t_game *game)
{
	free(game->filename);
	close(game->fd);
	free_str_array(game->map);
	free(game->str);
	free(game->p_pos);
	clear_images(game);
	free(game->images);
	mlx_clear_window(game->mlx, game->mlx_win);
	mlx_destroy_window(game->mlx, game->mlx_win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	clear_fd();
	exit(EXIT_SUCCESS);
}
