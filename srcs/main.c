/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/17 14:10:35 by gbourson          #+#    #+#             */
/*   Updated: 2016/08/18 17:53:14 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int ft_init_list(t_list **lst)
{
	t_list *tmp;

	tmp = NULL;
	tmp = *lst;
	if ((tmp = (t_list *)malloc(sizeof(t_list))) == NULL)
		return (0);
	*lst = tmp;
	return (1);
}

// t_list	*ft_create_map(t_list **map)
// {
// 	t_list *tmp_map;
//
// 	tmp_map = NULL;
// 	tmp_map = *map;
// 	if (tmp_map)
// 	{
// 		ft_lstadd_back(map, ft_lstnew(list_line, sizeof(t_list)));
// 		return (map);
// 	}
// 	else
// 		return (NULL);
// }

void ft_print_list(t_list **lst)
{
	t_point	*point;
	t_list	*tmp;

	point = NULL;
	tmp = NULL;
	tmp = *lst;
	while (tmp)
	{
		ft_putstr("ddd\n");
		point = ((t_point *)tmp->content);
		// ft_putnbr(point->x);
		// ft_putnbr(point->y);
		//ft_putnbr(point->z);
		tmp = tmp->next;
	}
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
	while (line[i] == '\n')
	{
		point = (t_point *)malloc(sizeof(t_point));
		point->x = i;
		point->y = count_line;
		point->z = ft_atoi(&line[i]);
		ft_lstadd_back(&tmp, ft_lstnew(point, sizeof(t_point)));
		ft_memdel((void **)&point);
		i++;
	}
	*list_line = tmp;
	return (1);
}

int ft_open_file(char *av, t_env *data)
{
	int fd;
	char *line;
	int	 count_line;

	(void)data;
	line = NULL;
	count_line = 0;
	fd = open(av, O_RDONLY);

	ft_init_list(&data->map);
	while (get_next_line(fd, &line))
	{
		ft_init_list(&data->list_line);
		if (ft_parse_line(line, count_line, &data->list_line))
		{
			ft_print_list(&data->list_line);
			//data->map = ft_create_map(data->list_line);
		}
		else
		{
			print_err("List fault");
			return (0);
		}
		ft_memdel((void **)&data->list_line);
		ft_strdel(&line);
		print_err("HEllO");
		count_line++;
	}
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
		if (!ft_mlx_init(&data))
			return (0);
	    mlx_loop(data.mlx_ptr);
	}
	else
		print_err("Env is empty");
    return (0);
}
