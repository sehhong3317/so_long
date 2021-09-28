/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 19:59:15 by sehhong           #+#    #+#             */
/*   Updated: 2021/09/28 13:28:53 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	SO_LONG_H
# define E_NO_MAP		1
# define E_EXTRA_ARG	2
# define E_WRONG_FORMAT	3
# define E_WRONG_WIDTH	4
# define E_WRONG_LENGTH	5
# define E_WRONG_WALL	6
# define E_WRONG_CHAR	7
# define E_MIN_ELEMENT	8
# define E_CONNECT_FAIL	9
# define E_NO_WINDOW	10
# define MAP_INDEX		1
# define EXIT_SUCCESS	0
# define EXIT_FAILURE	1

# include <unistd.h>

typedef struct	s_map
{
	int	is_p;
	int	is_e;
	int	is_c;
	int	is_zero;
	int	is_w;
}				t_map;

typedef struct	s_image
{
	void	*image_id;
	int		width;
	int		height;
}				t_image;

typedef	struct	s_data
{
	void	*mlx_id;
	void	*window_id;
	char	**map;
	int		width;
	int		height;
	int		pos_x;
	int		pos_y;
	int		num_of_steps;
	int		direction;
	int		coin_rotate_count;
	int		total_coin;
	int		finish_flag;
	t_image	image1;
	t_image	image2;
	t_image	image3;
	t_image	image4;
	t_image	image5;
	t_image	image6;
	t_image	image7;
	t_image	image8;
	t_image	image9;
	t_image	image10;
	t_image	image11;
	t_image	image12;
	t_image	image13;
	t_image	image14;
	t_image	image15;
	t_image	image16;
	t_image	image17;
	t_image	image18;	
}				t_data;

char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strrchr(const char *s, int c);
size_t	ft_strlen(const char *s);

#endif