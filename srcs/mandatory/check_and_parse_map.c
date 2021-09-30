/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_parse_map.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 12:39:17 by sehhong           #+#    #+#             */
/*   Updated: 2021/09/30 11:10:18 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/so_long.h"

void	check_map_extension(char *str, t_data data)
{
	if (ft_strlen(str) == 4 && !ft_strncmp(str, ".ber", 4))
		print_error_and_exit(E_WRONG_FORMAT, data);
	str = ft_strrchr(str, '.');
	if (ft_strlen(str) == 4 && !ft_strncmp(str, ".ber", 4))
		return ;
	print_error_and_exit(E_WRONG_FORMAT, data);
}

void	read_1st_line_of_map(int fd, char **line, t_data *data)
{
	int	gnl_value;

	gnl_value = get_next_line(fd, line);
	if (gnl_value < 0)
		print_syscall_error_and_exit("read() has failed.");
	else if (!gnl_value)
		print_syscall_error_and_exit("Format of the map is invalid.");
	data->width = ft_strlen(*line);
	data->height++;
	if (*line)
		free(*line);
	*line = NULL;
}

void	check_map_size(char *map_str, t_data *data)
{
	int		map_fd;
	char	*line;

	map_fd = open(map_str, O_RDONLY);
	if (map_fd == -1)
		print_syscall_error_and_exit("open() has failed.");
	read_1st_line_of_map(map_fd, &line, data);
	while ((get_next_line(map_fd, &line)) >= 0)
	{
		if (ft_strlen(line) == 0)
			break ;
		if (ft_strlen(line) != (size_t)data->width)
			print_error_and_exit(E_WRONG_WIDTH, *data);
		data->height++;
		free(line);
		line = NULL;
	}
	free(line);
	line = NULL;
	close(map_fd);
	if (!(data->width >= 4 && data->height >= 4))
		print_error_and_exit(E_WRONG_LENGTH, *data);
}

void	allocate_map_memory(char *map_str, t_data *data)
{
	int		map_fd;
	int		idx;
	char	*line;

	map_fd = open(map_str, O_RDONLY);
	if (map_fd == -1)
		print_syscall_error_and_exit("open() has failed.");
	data->map = (char **)malloc(data->height * sizeof(char *));
	if (!data->map)
		print_syscall_error_and_exit("malloc() has failed.");
	idx = 0;
	while (idx < data->height)
	{
		get_next_line(map_fd, &line);
		data->map[idx] = line;
		idx++;
	}
	close(map_fd);
}

void	assign_starting_point(t_data *data, int i, int j)
{
	if (data->map[i][j] == 'P')
	{
		data->position_x = j;
		data->position_y = i;
	}
}
