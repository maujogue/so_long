/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maujogue <maujogue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:57:39 by maujogue          #+#    #+#             */
/*   Updated: 2023/02/24 13:04:52 by maujogue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	free_gnl(char *str, char *temp, char *line, t_game *game)
{
	if (!line)
	{
		free(str);
		get_next_line(-1);
		exit_error(game, "Error\nMalloc Error\n");
	}
	else if (!str)
	{
		free(line);
		free(temp);
		get_next_line(-1);
		exit_error(game, "Error\nMalloc Error\n");
	}
	else
	{
		free(str);
		free(line);
		get_next_line(-1);
		exit_error(game, "Error\nMap is not valid\n");
	}
}

void	free_gnl_bis(char *str, int fd, t_game *game)
{
	close(fd);
	free(str);
	get_next_line(-1);
	exit_error(game, "Error\nMap is not valid\n");
}

char	*parse_map(t_game *game)
{
	char	*str;
	char	*temp;
	char	*line;
	int		fd;

	fd = open(game->filename, O_RDONLY);
	str = get_next_line(fd);
	if (!str)
		exit_error(game, "Error\nMalloc Error\n");
	while (read(fd, NULL, 1))
	{
		temp = str;
		line = get_next_line(fd);
		if (!line || ft_strlen(line) < 3 || ft_strlen(str) < 3)
			free_gnl(str, temp, line, game);
		str = ft_strjoin(temp, line);
		if (!str)
			free_gnl(str, temp, line, game);
		free(line);
		free(temp);
	}
	if (str[ft_strlen(str) - 1] == '\n')
		free_gnl_bis(str, fd, game);
	close(fd);
	return (str);
}
