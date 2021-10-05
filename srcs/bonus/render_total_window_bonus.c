/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_total_window_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 11:27:55 by sehee             #+#    #+#             */
/*   Updated: 2021/10/05 13:41:48 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/so_long_bonus.h"

void	render_rotating_coins(t_data data, int i, int j)
{
	static int		cnt;

	if (cnt == 300)
		cnt = 0;
	if (cnt < 50)
		mlx_put_image_to_window(data.connect_id, data.window_id, \
			data.images[1].image_id, 64 * i, 64 * j);
	else if (cnt >= 50 && cnt < 100)
		mlx_put_image_to_window(data.connect_id, data.window_id, \
			data.images[2].image_id, 64 * i, 64 * j);
	else if (cnt >= 100 && cnt < 150)
		mlx_put_image_to_window(data.connect_id, data.window_id, \
			data.images[13].image_id, 64 * i, 64 * j);
	else if (cnt >= 150 && cnt < 200)
		mlx_put_image_to_window(data.connect_id, data.window_id, \
			data.images[14].image_id, 64 * i, 64 * j);
	else if (cnt >= 200 && cnt < 250)
		mlx_put_image_to_window(data.connect_id, data.window_id, \
			data.images[15].image_id, 64 * i, 64 * j);
	else
		mlx_put_image_to_window(data.connect_id, data.window_id, \
			data.images[16].image_id, 64 * i, 64 * j);
	cnt++;
}

void	render_crackling_enemy(t_data data, int i, int j)
{
	static int		cnt;

	if (cnt == 300)
		cnt = 0;
	if (cnt < 150)
		mlx_put_image_to_window(data.connect_id, data.window_id, \
			data.images[9].image_id, 64 * i, 64 * j);
	else
		mlx_put_image_to_window(data.connect_id, data.window_id, \
			data.images[10].image_id, 64 * i, 64 * j);
	cnt++;
}

int	render_exit_images(t_data *data)
{
	if (data->acquired_coins == data->total_coin \
		&& data->map[data->position_y][data->position_x] == 'E')
	{
		mlx_clear_window(data->connect_id, data->window_id);
		mlx_put_image_to_window(data->connect_id, data->window_id, \
			data->images[17].image_id, \
			32 * (data->width - 3), 32 * (data->height - 3));
		data->finish_flag++;
		return (1);
	}
	if (data->map[data->position_y][data->position_x] == 'V')
	{
		mlx_clear_window(data->connect_id, data->window_id);
		mlx_put_image_to_window(data->connect_id, data->window_id, \
			data->images[18].image_id, \
			32 * (data->width - 3), 32 * (data->height - 3));
		data->finish_flag++;
		return (1);
	}
	return (0);
}

void	render_the_default_map(t_data *data, int i, int j)
{
	if (data->map[j][i] == '1')
		mlx_put_image_to_window(data->connect_id, data->window_id,
			data->images[11].image_id, 64 * i, 64 * j);
	else if (data->map[j][i] == 'P')
		mlx_put_image_to_window(data->connect_id, data->window_id,
			data->images[12].image_id, 64 * i, 64 * j);
	else
	{
		mlx_put_image_to_window(data->connect_id, data->window_id,
			data->images[3].image_id, 64 * i, 64 * j);
		if (data->map[j][i] == 'E')
			mlx_put_image_to_window(data->connect_id, data->window_id,
				data->images[4].image_id, 64 * i, 64 * j);
		else if (data->map[j][i] == 'C')
			render_rotating_coins(*data, i, j);
		else if (data->map[j][i] == 'V')
			render_crackling_enemy(*data, i, j);
	}
}

void	render_player_image(t_data *data)
{
	if (data->direction == KEY_RIGHT)
		mlx_put_image_to_window(data->connect_id, data->window_id, \
			data->images[7].image_id, \
			64 * data->position_x, 64 * data->position_y);
	else if (data->direction == KEY_DOWN)
		mlx_put_image_to_window(data->connect_id, data->window_id, \
			data->images[5].image_id, \
			64 * data->position_x, 64 * data->position_y);
	else if (data->direction == KEY_LEFT)
		mlx_put_image_to_window(data->connect_id, data->window_id, \
			data->images[6].image_id, \
			64 * data->position_x, 64 * data->position_y);
	else if (data->direction == KEY_UP)
		mlx_put_image_to_window(data->connect_id, data->window_id, \
			data->images[8].image_id, \
			64 * data->position_x, 64 * data->position_y);
}
