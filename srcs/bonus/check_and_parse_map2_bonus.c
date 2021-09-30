/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_parse_map2_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 15:35:21 by sehee             #+#    #+#             */
/*   Updated: 2021/09/30 10:15:30 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/so_long_bonus.h"

int	isvalid_element(char c, t_map *map)
{
	if (c == 'P')
		map->is_p++;
	else if (c == 'E')
		map->is_e++;
	else if (c == 'C')
		map->is_c++;
	else if (c == '0')
		map->is_zero++;
	else if (c == '1')
		map->is_w++;
	else
		return (-1);
	return (0);
}

void	check_individual_elements(int i, int j, t_data data, t_map *map_info)
{
	if (i == 0 || i == data.height - 1)
	{
		if (data.map[i][j] != '1')
			print_error_and_exit(E_WRONG_WALL, data);
	}
	else
	{
		if (data.map[i][0] != '1' || data.map[i][data.width - 1] != '1')
			print_error_and_exit(E_WRONG_WALL, data);
	}
	if (isvalid_element(data.map[i][j], map_info) == -1)
		print_error_and_exit(E_WRONG_CHAR, data);
}

void	inspect_map_details(t_data *data)
{
	t_map	map_info;
	int		i;
	int		j;

	ft_memset(&map_info, 0, sizeof(map_info));
	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			assign_starting_point(data, i, j);
			check_individual_elements(i, j, *data, &map_info);
			j++;
		}
		i++;
	}
	data->total_coin = map_info.is_c;
	if (!(map_info.is_p >= 1 && map_info.is_e >= 1 && map_info.is_c >= 1 \
		&& map_info.is_zero >= 1 && map_info.is_w >= 1))
		print_error_and_exit(E_MIN_ELEMENT, *data);
}

void	add_enemy_on_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			if ((i % 5 == 1) && (j % 7 == 6) && data->map[i][j] == '0')
				data->map[i][j] = 'V';
			j++;
		}
		i++;
	}
}

void	check_and_parse_map(int argc, char **argv, t_data *data)
{
	if (argc == 1)
		print_error_and_exit(E_NO_MAP, *data);
	else if (argc == 2)
	{
		check_map_extension(argv[MAP_INDEX], *data);
		check_map_size(argv[MAP_INDEX], data);
		allocate_map_memory(argv[MAP_INDEX], data);
		inspect_map_details(data);
		add_enemy_on_map(data);
	}
	else
		print_error_and_exit(E_EXTRA_ARG, *data);
}
