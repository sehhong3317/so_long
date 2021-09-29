/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehee <sehee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 09:53:32 by sehee             #+#    #+#             */
/*   Updated: 2021/09/29 20:02:20 by sehee            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# define E_EXIT				0
# define E_NO_MAP			1
# define E_EXTRA_ARG		2
# define E_WRONG_FORMAT		3
# define E_WRONG_WIDTH		4
# define E_WRONG_LENGTH		5
# define E_WRONG_WALL		6
# define E_WRONG_CHAR		7
# define E_MIN_ELEMENT		8
# define E_CONNECT_FAIL		9
# define E_NO_WINDOW		10
# define MAP_INDEX			1
# define EXIT_SUCCESS		0
# define EXIT_FAILURE		1
# define KEY_RIGHT			2
# define KEY_DOWN			1
# define KEY_LEFT			0
# define KEY_UP				13
# define KEY_ESC			53
# define PRESS_KEY_EVENT	2
# define PRESS_EXIT_BUTTON	17

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "mlx.h"
# include "get_next_line.h"
# include "libft.h"

typedef struct s_map
{
	int	is_p;
	int	is_e;
	int	is_c;
	int	is_zero;
	int	is_w;
}				t_map;

typedef struct s_image
{
	void	*image_id;
	int		width;
	int		height;
}				t_image;

typedef struct s_data
{
	void	*connect_id;
	void	*window_id;
	char	**map;
	int		width;
	int		height;
	int		position_x;
	int		position_y;
	int		num_of_steps;
	int		direction;
	int		acquired_coins;
	int		total_coin;
	int		finish_flag;
	t_image	images[19];	
}				t_data;

/*check_and_parse_map_bonus, check_and_parse_map2_bonus*/
void	check_map_extension(char *str, t_data data);
void	read_1st_line_of_map(int fd, char **line, t_data *data);
void	check_map_size(char *map_str, t_data *data);
void	allocate_map_memory(char *map_str, t_data *data);
void	assign_starting_point(t_data *data, int i, int j);
int		isvalid_element(char c, t_map *map);
void	check_individual_elements(int i, int j, t_data data, t_map *map_info);
void	inspect_map_details(t_data *data);
void	add_enemy_on_map(t_data *data);
void	check_and_parse_map(int argc, char **argv, t_data *data);

/*exit_utils_bonus*/
void	free_allocated_map(t_data *data);
void	destroy_images(t_data *data);
void	print_error_messages(int error_num);
void	print_error_and_exit(int error_num, t_data data);
void	print_syscall_error_and_exit(char *error_str);

/*upload_images_bonus*/
void	upload_images1(t_data *data);
void	upload_images2(t_data *data);
void	upload_images3(t_data *data);
void	upload_images(t_data *data);

/*render_total_window_bonus, render_total_window2_bonus*/
void	render_rotating_coins(t_data data, int i, int j);
void	render_crackling_enemy(t_data data, int i, int j);
int		render_exit_images(t_data *data);
void	render_the_default_map(t_data *data, int i, int j);
void	render_player_image(t_data *data);
void	render_steps_on_window(t_data *data);
int		render_total_window(t_data *data);

/*mlx_hook_functions_bonus*/
void	move_player_based_on_keys(int key_num, t_data *data);
int		deal_with_keys(int key_num, t_data *data);
int		deal_with_close_button(t_data *data);

#endif