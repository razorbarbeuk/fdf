/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/17 14:10:35 by gbourson          #+#    #+#             */
/*   Updated: 2016/08/25 22:46:11 by RAZOR            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int ft_center_map(t_list *map, int *top, int *left)
{
	int x1;
	int x2;
	int y1;
	t_list	*tmp;

	y1 = 0;
	x1 = 0;
	x2 = 0;
	tmp = NULL;
	ft_lstiter_coord(map, &x2, 0, &ft_elem_num);
	while (map->next)
		map = map->next;
	tmp = (t_list *)map->content;
	ft_elem_num(tmp, &x1, 1);
	ft_lstiter_coord(map, &y1, 2, &ft_elem_num);
	(*left) = (WIN_W - (x1 + x2))/2;
	(*top) = (WIN_H - y1)/2;
	return (0);
}

void ft_draw_line(t_env *data, int screen_x, int screen_x_next)
{
	int cursor;

	cursor = screen_x;
	while (cursor < screen_x_next)
	{
		mlx_pixel_put(data->mlx_ptr, data->mlx_win, cursor, cursor, 0x00FFCB0D);
		cursor++;
	}
}

void ft_draw_pixel(t_env *data)
{
	t_list	*tmp_list;
	int		screen_x;
	// int		y_tmp;
	double	tab[2];
	int		screen_y;

	tmp_list = NULL;
	tab[0] = 0;
	tab[1] = 0;
	screen_x = 0;
	screen_y = 0;
	ft_center_map(data->map, &data->top, &data->left);
	while (data->map)
	{
		tmp_list = data->map->content;

		while (tmp_list)
		{
			tab[0] = screen_x + data->left;
			tab[1] = screen_y + data->top;
			ft_elem_num(tmp_list, &screen_x, 1);
			ft_elem_num(tmp_list, &screen_y, 2);
			while (tab[0] < (screen_x + data->left))
			{
				while (tab[1] < (screen_y + data->top)) {
					mlx_pixel_put(data->mlx_ptr, data->mlx_win, tab[0], tab[1], 0x00FFCB0D);
					tab[1]++;
				}
				tab[0]++;
			}
			mlx_pixel_put(data->mlx_ptr, data->mlx_win, screen_x + data->left, screen_y + data->top, 0x00FFCB0D);
			//ft_draw_line(data, screen_x + data->left, screen_x_next + data->left);
			tmp_list = tmp_list->next;
		}

		tmp_list = NULL;
		data->map = data->map->next;
	}
}

int	ft_create_map(t_list **map, t_list *list_line)
{
	t_list *tmp_map;

	tmp_map = NULL;
	tmp_map = *map;
	if (list_line)
	{
		ft_lstadd_back(&tmp_map, ft_lstnew(list_line, sizeof(t_list)));
		*map = tmp_map;
		tmp_map = NULL;
		return (1);
	}
	else
		return (0);
}

void ft_init_point(t_point **pts)
{
	t_point *tmp;

	tmp = NULL;
	tmp = *pts;

	tmp->x = 0;
	tmp->y = 0;
	tmp->z = 0;
	*pts = tmp;
}

int ft_parse_line(char *line, int *count_line, t_list **list_line)
{
	t_point	*point;
	t_list	*tmp;
	char	**tmp_read;
	int		i;


	tmp = NULL;
	tmp = *list_line;
	point = NULL;
	tmp_read = ft_strsplit(line, ' ');
	i = 0;
	while (tmp_read[i])
	{
		point = (t_point *)malloc(sizeof(t_point));
		ft_init_point(&point);
		point->x = i;
		point->y = (*count_line);
		point->z = ft_atoi(tmp_read[i]);
		ft_lstadd_back(&tmp, ft_lstnew(point, sizeof(t_point)));
		ft_memdel((void **)&point);
		ft_strdel(&tmp_read[i]);
		i++;
	}
	ft_strdel_double(tmp_read);
	*list_line = tmp;
	tmp = NULL;
	return (1);
}

int ft_open_file(char *av, t_env *data)
{
	int fd;
	char *line;
	int	 count_line;

	fd = 0;
	line = NULL;
	count_line = 0;
	fd = open(av, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		if ((*line) && ft_parse_line(line, &count_line, &data->list_line))
		{
			ft_create_map(&data->map, data->list_line);
			count_line++;
		}
		// else
		// {
		// 	print_err("List fault");
		// 	return (0);
		// }
		ft_memdel((void **)&data->list_line);
		ft_strdel(&line);
	}
	ft_strdel(&line);
	return (1);
}

int ft_mlx_init(t_env *data)
{
	if ((data->mlx_ptr = mlx_init()) == NULL)
        return (0);
    if ((data->mlx_win = mlx_new_window(data->mlx_ptr, WIN_W, WIN_H, "Hello world")) == NULL)
        return (0);
	return (1);
}

int ft_init_data(t_env *data)
{
	data->mlx_ptr = NULL;
	data->mlx_win = NULL;
	data->list_line = NULL;
	data->map = NULL;
	return (1);
}

int main(int ac, char **av, char **env)
{
    t_env        data;

	ft_init_data(&data);
	if ((env) && (ac < 3))
	{
		ft_open_file(av[1], &data);
		//ft_print_list(&data.map);
		if (!ft_mlx_init(&data))
			return (0);
		ft_draw_pixel(&data);
	    mlx_loop(data.mlx_ptr);
	}
	else
		print_err("Env is empty");
    return (0);
}
