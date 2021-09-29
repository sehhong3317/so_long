/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehee <sehee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 10:52:02 by sehhong           #+#    #+#             */
/*   Updated: 2021/09/29 16:02:27 by sehee            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/so_long_bonus.h"

void	free_allocated_map(t_data *data)
{
	int	idx;

	idx = 0;
	while (idx < data->height)
	{
		free(data->map[idx]);
		idx++;
	}
	free(data->map);
}

void	destroy_images(t_data *data)
{
	mlx_destroy_image(data->connect_id, data->images[1].image_id);
	mlx_destroy_image(data->connect_id, data->images[2].image_id);
	mlx_destroy_image(data->connect_id, data->images[3].image_id);
	mlx_destroy_image(data->connect_id, data->images[4].image_id);
	mlx_destroy_image(data->connect_id, data->images[5].image_id);
	mlx_destroy_image(data->connect_id, data->images[6].image_id);
	mlx_destroy_image(data->connect_id, data->images[7].image_id);
	mlx_destroy_image(data->connect_id, data->images[8].image_id);
	mlx_destroy_image(data->connect_id, data->images[9].image_id);
	mlx_destroy_image(data->connect_id, data->images[10].image_id);
	mlx_destroy_image(data->connect_id, data->images[11].image_id);
	mlx_destroy_image(data->connect_id, data->images[12].image_id);
	mlx_destroy_image(data->connect_id, data->images[13].image_id);
	mlx_destroy_image(data->connect_id, data->images[14].image_id);
	mlx_destroy_image(data->connect_id, data->images[15].image_id);
	mlx_destroy_image(data->connect_id, data->images[16].image_id);
	mlx_destroy_image(data->connect_id, data->images[17].image_id);
	mlx_destroy_image(data->connect_id, data->images[18].image_id);
}

void	print_error_messages(int error_num)
{
	if (error_num == E_NO_MAP)
		ft_putstr_fd("Error\nNo map is given as an argument.\n", 2);
	else if (error_num == E_EXTRA_ARG)
		ft_putstr_fd("Error\nOnly one argument is required.\n", 2);
	else if (error_num == E_WRONG_FORMAT)
		ft_putstr_fd("Error\nMap Error: The map is not in *.ber format.\n", 2);
	else if (error_num == E_WRONG_WIDTH)
		ft_putstr_fd("Error\nMap Error: Width of the map is inconsistent.\n", \
			2);
	else if (error_num == E_WRONG_LENGTH)
		ft_putstr_fd("Error\nMap Error: Length of the map has to be at least 4\
			.\n", 2);
	else if (error_num == E_WRONG_WALL)
		ft_putstr_fd("Error\nMap Error: The map must be surrouned by walls.\n"\
			, 2);
	else if (error_num == E_WRONG_CHAR)
		ft_putstr_fd("Error\nMap Error: Invalid character is in the map.\n", 2);
	else if (error_num == E_MIN_ELEMENT)
		ft_putstr_fd("Error\nMap Error: At least one character for each element\
			 is needed.\n", 2);
	else if (error_num == E_CONNECT_FAIL)
		ft_putstr_fd("Error\nConnection has failed.\n", 2);
	else if (error_num == E_NO_WINDOW)
		ft_putstr_fd("Error\nFail to create a new window on the screen.\n", 2);
}

void	print_error_and_exit(int error_num, t_data data)
{
	if (error_num == E_EXIT)
	{
		free_allocated_map(&data);
		mlx_destroy_window(data.connect_id, data.window_id);
		destroy_images(&data);
		exit(EXIT_SUCCESS);
	}
	print_error_messages(error_num);
	if (error_num > E_WRONG_LENGTH)
	{
		free_allocated_map(&data);
		if (error_num == E_NO_WINDOW)
			mlx_destroy_window(data.connect_id, data.window_id);
		exit(EXIT_FAILURE);
	}
}

void	print_syscall_error_and_exit(char *error_str)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(error_str, 2);
	ft_putstr_fd("\n", 2);
	exit(EXIT_FAILURE);
}
