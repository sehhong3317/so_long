/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehee <sehee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 18:40:08 by sehee             #+#    #+#             */
/*   Updated: 2021/09/29 19:32:36 by sehee            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/so_long.h"

void	move_player_based_on_keys(int key_num, t_data *data)
{
	data->direction = key_num;
	if (key_num == KEY_UP \
		&& data->map[data->position_y - 1][data->position_x] != '1')
		data->position_y--;
	else if (key_num == KEY_DOWN \
		&& data->map[data->position_y + 1][data->position_x] != '1')
		data->position_y++;
	else if (key_num == KEY_LEFT \
		&& data->map[data->position_y][data->position_x - 1] != '1')
		data->position_x--;
	else if (key_num == KEY_RIGHT \
		&& data->map[data->position_y][data->position_x + 1] != '1')
		data->position_x++;
	else
		return ;
	data->num_of_steps++;
	if (data->map[data->position_y][data->position_x] == 'C')
	{
		data->map[data->position_y][data->position_x] = '0';
		data->acquired_coins++;
	}
}

int	deal_with_keys(int key_num, t_data *data)
{
	if (key_num == KEY_ESC)
		print_error_and_exit(E_EXIT, *data);
	if (data->finish_flag == 0)
	{
		if (key_num == KEY_UP || key_num == KEY_LEFT || key_num == KEY_RIGHT \
			|| key_num == KEY_DOWN)
		{
			move_player_based_on_keys(key_num, data);
			ft_putnbr(data->num_of_steps);
			ft_putstr("\n");
		}
	}
	else
		ft_putstr("finished\n");
	return (0);
}

int	deal_with_close_button(t_data *data)
{
	print_error_and_exit(E_EXIT, *data);
}
