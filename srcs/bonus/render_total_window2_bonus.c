/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_total_window2_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehee <sehee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 15:50:13 by sehee             #+#    #+#             */
/*   Updated: 2021/09/29 16:03:21 by sehee            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/so_long_bonus.h"

void	render_steps_on_window(t_data *data)
{
	char	*step;

	step = ft_itoa(data->num_of_steps);
	mlx_string_put(data->connect_id, data->window_id, 8, \
		64 * data->height - 16, 0xFFFFFF, step);
	free(step);
	step = NULL;
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
	render_steps_on_window(data);
	return (0);
}
