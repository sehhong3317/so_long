/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_total_window.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehee <sehee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 11:27:36 by sehee             #+#    #+#             */
/*   Updated: 2021/09/29 20:06:44 by sehee            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/so_long.h"

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
	return (0);
}

void	render_the_default_map(t_data *data, int i, int j)
{
	if (data->map[j][i] == '1')
		mlx_put_image_to_window(data->connect_id, data->window_id, \
			data->images[11].image_id, 64 * i, 64 * j);
	else if (data->map[j][i] == 'P')
		mlx_put_image_to_window(data->connect_id, data->window_id, \
			data->images[12].image_id, 64 * i, 64 * j);
	else
	{
		mlx_put_image_to_window(data->connect_id, data->window_id, \
			data->images[3].image_id, 64 * i, 64 * j);
		if (data->map[j][i] == 'E')
			mlx_put_image_to_window(data->connect_id, data->window_id, \
				data->images[4].image_id, 64 * i, 64 * j);
		else if (data->map[j][i] == 'C')
			mlx_put_image_to_window(data->connect_id, data->window_id, \
				data->images[1].image_id, 64 * i, 64 * j);
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

int	render_total_window(t_data *data)
{
	int		i;
	int		j;

	if (render_exit_images(data))
		return (0);
	j = 0;
	while (j < data->height)
	{
		i = 0;
		while (i < data->width)
		{
			render_the_default_map(data, i, j);
			i++;
		}
		j++;
	}
	render_player_image(data);
	return (0);
}
