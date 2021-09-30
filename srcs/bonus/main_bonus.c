/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 09:53:04 by sehee             #+#    #+#             */
/*   Updated: 2021/09/30 10:44:44 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	initialize_data(t_data *data)
{
	data->num_of_steps = 0;
	data->direction = KEY_RIGHT;
	data->width = 0;
	data->height = 0;
	data->acquired_coins = 0;
	data->finish_flag = 0;
}

int	main(int argc, char **argv)
{
	t_data	data;

	initialize_data(&data);
	check_and_parse_map(argc, argv, &data);
	data.connect_id = mlx_init();
	if (!data.connect_id)
		print_error_and_exit(E_CONNECT_FAIL, data);
	data.window_id = mlx_new_window(data.connect_id, 64 * data.width, \
		64 * data.height, "SO_LONG");
	if (!data.window_id)
		print_error_and_exit(E_NO_WINDOW, data);
	upload_images(&data);
	mlx_loop_hook(data.connect_id, render_total_window, &data);
	mlx_hook(data.window_id, PRESS_KEY_EVENT, 0, deal_with_keys, &data);
	mlx_hook(data.window_id, PRESS_EXIT_BUTTON, 0, deal_with_close_button, \
		&data);
	mlx_loop(data.connect_id);
	return (0);
}
