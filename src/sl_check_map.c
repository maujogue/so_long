/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maujogue <maujogue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 13:18:09 by maujogue          #+#    #+#             */
/*   Updated: 2023/02/13 13:57:31 by maujogue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

static int	check_map_wall(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[0][++i])
	{
		if (map[0][i] != '1')
			return (EXIT_FAILURE);
	}
	i--;
	j = -1;
	while (map[++j])
	{
		if (map[j][0] != '1' || map[j][i] != '1')
			return (EXIT_FAILURE);
	}
	i = 0;
	j--;
	while (map[j][i])
	{
		if (map[j][i] != '1')
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

static int	check_map_values(t_game *game)
{
	int		i;
	char	*str;

	str = game->str;
	i = 0;
	game->width = ft_strlen(game->map[0]);
	while (game->map[i])
	{
		if ((int)ft_strlen(game->map[i]) != game->width)
			return (EXIT_FAILURE);
		i++;
	}
	i = -1;
	while (str[++i])
	{
		if (!(str[i] == 'P' || str[i] == 'E' || str[i] == 'C'
				|| str[i] == '0' || str[i] == '1' || str[i] == '\n'))
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

void	check_map_content(t_game *game)
{
	if (get_nb_occurences(game, 'P') == 0)
		exit_error(game, "Error\n- No players\n");
	if (get_nb_occurences(game, 'P') > 1)
		exit_error(game, "Error\n- Multiple players\n");
	if (get_nb_occurences(game, 'E') == 0)
		exit_error(game, "Error\n- No exit\n");
	if (get_nb_occurences(game, 'E') > 1)
		exit_error(game, "Error\n- Multiple exits\n");
	if (get_nb_occurences(game, 'C') < 1)
		exit_error(game, "Error\n- No collectible\n");
	if (check_map_values(game) == EXIT_FAILURE)
		exit_error(game, "Error\n- Map content is not valid\n");
	if (check_map_wall(game->map) == EXIT_FAILURE)
		exit_error(game, "Error\n- Map is not surrounded by walls\n");
}
