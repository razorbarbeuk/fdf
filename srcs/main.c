/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/17 14:10:35 by gbourson          #+#    #+#             */
/*   Updated: 2016/08/22 17:16:50 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void ft_draw_pixel(t_env *data)
{
	t_point	*point_x;
	t_point	*point_y;
	t_list	*tmp;
	t_list	*tmp_list;
	int		screen_x;
	int		screen_y;
	int		cursor_x;
	int		cursor_y;

	point_x = NULL;
	point_y = NULL;
	tmp = NULL;
	tmp_list = NULL;
	tmp = data->map;
	screen_x = 0;
	screen_y = 0;
	cursor_x = 0;
	cursor_y = 0;
	while (tmp)
	{
		tmp_list = (t_list *)tmp->content;
		point_y = (t_point *)tmp_list->content;
		while (tmp_list)
		{
			cursor_x = 0;
			point_x = (t_point *)tmp_list->content;
			screen_x = point_x->x * SIZE_CASE;
			ft_putnbr(screen_x);
			ft_putchar(' ');
			while (cursor_y < screen_y)
			{
					mlx_pixel_put(data->mlx_ptr, data->mlx_win, screen_x, cursor_y, 0x00FFFFFF);
					cursor_y++;
			}
			while (cursor_x < screen_x)
			{
					cursor_y = 0;
					mlx_pixel_put(data->mlx_ptr, data->mlx_win, cursor_x, screen_y, 0x00FFFFFF);
					if (cursor_x == (screen_x - 1))
					{
						while (cursor_y < screen_y)
						{
								mlx_pixel_put(data->mlx_ptr, data->mlx_win, screen_x, cursor_y, 0x00FFFFFF);
								cursor_y++;
						}
					}
					cursor_x++;
			}
			tmp_list = tmp_list->next;
		}
		screen_y = point_y->y * SIZE_CASE;
		// ft_putnbr(screen_y);
		ft_putchar('\n');
		tmp_list = NULL;
		tmp = tmp->next;
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
    if ((data->mlx_win = mlx_new_window(data->mlx_ptr, 800, 600, "Hello world")) == NULL)
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
