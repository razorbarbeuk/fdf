/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/17 14:10:35 by gbourson          #+#    #+#             */
/*   Updated: 2016/08/21 23:36:37 by RAZOR            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void ft_print_list(t_list **map)
{
	t_point	*point;
	t_list	*tmp;
	t_list	*tmp_list;

	point = NULL;
	tmp = NULL;
	tmp_list = NULL;
	tmp = *map;
	while (tmp)
	{

		tmp_list = (t_list *)tmp->content;
		while (tmp_list)
		{
			point = (t_point *)tmp_list->content;
			//ft_putnbr(point->x);
			// ft_putnbr(point->y);
			if (ft_count_number(point->z) < 2)
			{
				ft_putchar(' ');
				ft_putchar(' ');
			}
			else
				ft_putchar(' ');
			ft_putnbr(point->z);
			point = NULL;
			tmp_list = tmp_list->next;

		}
		tmp_list = NULL;
		point = NULL;
		tmp = tmp->next;
		ft_putchar('\n');
	}
	tmp = NULL;
	ft_putendl("END");
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

int ft_parse_line(char *line, int count_line, t_list **list_line)
{
	t_point	*point;
	t_list	*tmp;
	int i;

	tmp = NULL;
	tmp = *list_line;
	point = NULL;
	i = 0;
	while (line[i])
	{
		if (line[i] == ' ')
			i++;
		point = (t_point *)malloc(sizeof(t_point));
		ft_init_point(&point);
		point->x = i;
		point->y = count_line;
		point->z = ft_atoi(&line[i]);
		ft_lstadd_back(&tmp, ft_lstnew(point, sizeof(t_point)));
		ft_memdel((void **)&point);
		i++;
	}
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
		if (line && ft_parse_line(line, count_line, &data->list_line))
			ft_create_map(&data->map, data->list_line);
		else
		{
			print_err("List fault");
			return (0);
		}
		ft_memdel((void **)&data->list_line);
		ft_strdel(&line);
		count_line++;
	}
	ft_strdel(&line);
	return (1);
}

int ft_mlx_init(t_env *data)
{
	if ((data->mlx_ptr = mlx_init()) == NULL)
        return (0);
    if ((data->mlx_win = mlx_new_window(data->mlx_ptr, 640, 480, "Hello world")) == NULL)
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
		ft_print_list(&data.map);
		if (!ft_mlx_init(&data))
			return (0);
	    mlx_loop(data.mlx_ptr);
	}
	else
		print_err("Env is empty");
    return (0);
}
