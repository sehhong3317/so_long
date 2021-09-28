/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 10:52:02 by sehhong           #+#    #+#             */
/*   Updated: 2021/09/28 15:04:50 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	mlx_destroy_image(data->mlx_id, data->image1.image_id);
	mlx_destroy_image(data->mlx_id, data->image2.image_id);
	mlx_destroy_image(data->mlx_id, data->image3.image_id);
	mlx_destroy_image(data->mlx_id, data->image4.image_id);
	mlx_destroy_image(data->mlx_id, data->image5.image_id);
	mlx_destroy_image(data->mlx_id, data->image6.image_id);
	mlx_destroy_image(data->mlx_id, data->image7.image_id);
	mlx_destroy_image(data->mlx_id, data->image8.image_id);
	mlx_destroy_image(data->mlx_id, data->image9.image_id);
	mlx_destroy_image(data->mlx_id, data->image10.image_id);
	mlx_destroy_image(data->mlx_id, data->image11.image_id);
	mlx_destroy_image(data->mlx_id, data->image12.image_id);
	mlx_destroy_image(data->mlx_id, data->image13.image_id);
	mlx_destroy_image(data->mlx_id, data->image14.image_id);
	mlx_destroy_image(data->mlx_id, data->image15.image_id);
	mlx_destroy_image(data->mlx_id, data->image16.image_id);
	mlx_destroy_image(data->mlx_id, data->image17.image_id);
	mlx_destroy_image(data->mlx_id, data->image18.image_id);	
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
	if (error_num == 0)
	{
		free_allocated_map(&data);
		mlx_destroy_window(data.mlx_id, data.window_id);
		destroy_images(&data);
		exit(EXIT_SUCCESS);
	}
	print_error_messages(error_num);
	if (error_num > E_WRONG_LENGTH)
	{
		free_allocated_map(&data);
		if (error_num == E_NO_WINDOW)
			mlx_destroy_window(data.mlx_id, data.window_id);
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