/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upload_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehee <sehee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 10:37:10 by sehee             #+#    #+#             */
/*   Updated: 2021/09/29 19:33:34 by sehee            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/so_long.h"

void	upload_images1(t_data *data)
{
	data->images[1].image_id = mlx_xpm_file_to_image(data->connect_id,
			"./images/coin1.xpm", &data->images[1].width, \
			&data->images[1].height);
	data->images[2].image_id = mlx_xpm_file_to_image(data->connect_id,
			"./images/coin2.xpm", &data->images[2].width, \
			&data->images[2].height);
	data->images[3].image_id = mlx_xpm_file_to_image(data->connect_id,
			"./images/empty_space.xpm", &data->images[3].width, \
			&data->images[3].height);
	data->images[4].image_id = mlx_xpm_file_to_image(data->connect_id,
			"./images/end_point.xpm", &data->images[4].width, \
			&data->images[4].height);
	data->images[5].image_id = mlx_xpm_file_to_image(data->connect_id,
			"./images/ghost_down.xpm", &data->images[5].width, \
			&data->images[5].height);
	data->images[6].image_id = mlx_xpm_file_to_image(data->connect_id,
			"./images/ghost_left.xpm", &data->images[6].width, \
			&data->images[6].height);
}

void	upload_images2(t_data *data)
{
	data->images[7].image_id = mlx_xpm_file_to_image(data->connect_id,
			"./images/ghost_right.xpm", &data->images[7].width, \
			&data->images[7].height);
	data->images[8].image_id = mlx_xpm_file_to_image(data->connect_id,
			"./images/ghost_up.xpm", &data->images[8].width, \
			&data->images[8].height);
	data->images[9].image_id = mlx_xpm_file_to_image(data->connect_id,
			"./images/pacman1.xpm", &data->images[9].width, \
			&data->images[9].height);
	data->images[10].image_id = mlx_xpm_file_to_image(data->connect_id,
			"./images/pacman2.xpm", &data->images[10].width, \
			&data->images[10].height);
	data->images[11].image_id = mlx_xpm_file_to_image(data->connect_id,
			"./images/wall.xpm", &data->images[11].width, \
			&data->images[11].height);
	data->images[12].image_id = mlx_xpm_file_to_image(data->connect_id,
			"./images/start.xpm", &data->images[12].width, \
			&data->images[12].height);
}

void	upload_images3(t_data *data)
{
	data->images[13].image_id = mlx_xpm_file_to_image(data->connect_id,
			"./images/coin3.xpm", &data->images[13].width, \
			&data->images[13].height);
	data->images[14].image_id = mlx_xpm_file_to_image(data->connect_id,
			"./images/coin4.xpm", &data->images[14].width, \
			&data->images[14].height);
	data->images[15].image_id = mlx_xpm_file_to_image(data->connect_id,
			"./images/coin5.xpm", &data->images[15].width, \
			&data->images[15].height);
	data->images[16].image_id = mlx_xpm_file_to_image(data->connect_id,
			"./images/coin6.xpm", &data->images[16].width, \
			&data->images[16].height);
	data->images[17].image_id = mlx_xpm_file_to_image(data->connect_id,
			"./images/hooray.xpm", &data->images[17].width, \
			&data->images[17].height);
	data->images[18].image_id = mlx_xpm_file_to_image(data->connect_id,
			"./images/game_over.xpm", &data->images[18].width, \
			&data->images[18].height);
}

void	upload_images(t_data *data)
{
	upload_images1(data);
	upload_images2(data);
	upload_images3(data);
}
