/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/17 14:10:35 by gbourson          #+#    #+#             */
/*   Updated: 2016/08/18 12:19:09 by RAZOR            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	print_err(char *str)
{
	ft_putstr_fd(RED, 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\e[0m", 2);
}

t_list *ft_init_list(t_list **lst)
{
	t_list *tmp;

	tmp = NULL;
	tmp = *lst;
	if ((tmp = (t_list *)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	return (tmp);
}

t_list *ft_parse_line(char *line, int count_line)
{
	t_list	*list_line;
	t_point	*point;
	int i;

	list_line = NULL;
	list_line = ft_init_list(&list_line);
	point = NULL;
	i = 0;
	while (line[i])
	{
		point = (t_point *)malloc(sizeof(t_point));
		point->x = i;
		point->y = count_line;
		point->z = ft_atoi(&line[i]);
		ft_lstadd_back(&list_line, ft_lstnew(point, sizeof(t_point)));
		i++;
	}
	return (list_line);
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
	while (get_next_line(fd, &line))
	{
		ft_parse_line(line, count_line);
		ft_strdel(&line);
		count_line++;
	}
	return (0);
}

int ft_mlx_init(t_env *data)
{
	if ((data->mlx_ptr = mlx_init()) == NULL)
        return (0);
    if ((data->mlx_win = mlx_new_window(data->mlx_ptr, 640, 480, "Hello world")) == NULL)
        return (0);
	return (1);
}

int main(int ac, char **av, char **env)
{
    t_env        data;

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
