/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maujogue <maujogue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:04:30 by maujogue          #+#    #+#             */
/*   Updated: 2023/02/23 16:42:31 by maujogue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../minilibx_linux/mlx.h"
# include <unistd.h>
# include <fcntl.h>

typedef struct point
{
	int		x;
	int		y;
	char	data;
}	t_point;

typedef struct images
{
	void	*photo;
	void	*grass;
	void	*block;
	void	*earth;
	void	*ladder;
	void	*collectible;
	void	*bro_l;
	void	*bro_r;
	void	*bro_jetpack_l;
	void	*bro_jetpack_r;
	void	*sky;
	void	*cloud;
	void	*cloud2;	
	void	*exit;
	void	*exit_flag;
	void	*exit_title;
}	t_images;

typedef struct game
{
	int			status;
	int			fd;
	int			height;
	int			width;
	int			win;
	int			nb_collectibles;
	int			nb_exit;
	int			nb_move;
	char		*filename;
	char		*str;
	char		**map;
	void		*mlx;
	void		*mlx_win;
	t_point		*p_pos;
	t_images	*images;
	int			img_height;
	int			img_width;
	int			big_img_height;
	int			big_img_width;
}	t_game;

void	free_str_array(char **array);
void	free_exit(t_game *game);
void	clear_fd(void);
void	exit_error(t_game *game, char *str);
void	clear_images(t_game *game);

t_point	*get_point(t_game *game, char c);
int		get_nb_occurences(t_game *game, char c);

char	*parse_map(t_game *game);
int		get_check_fd(t_game *game);
void	check_map_content(t_game *game);
int		find_path(t_game *game, char **cpy, int px, int py);
void	check_path(t_game *game);

int		init_images(t_game *game);
void	choose_image(t_game *game, int i, int j);
int		draw_count(t_game *game);
void	draw_images(t_game *game);

int		close_win(t_game *game);
void	check_keypress(t_game *game);
#endif