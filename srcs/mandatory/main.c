/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 19:56:37 by sehhong           #+#    #+#             */
/*   Updated: 2021/09/28 15:04:55 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_cases(int)

void	initialize_data(t_data *data)
{
	data->num_of_steps = 0;
	data->direction = 2;
	data->width = 0;
	data->height = 0;
	data->coin_rotate_count = 0;
	data->finish_flag = 0;
}

int		main(int argc, char **argv)
{
	t_data	data;

	initialize_data(&data);
}