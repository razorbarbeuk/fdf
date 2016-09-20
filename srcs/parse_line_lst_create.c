/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line_lst_create.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: RAZOR <RAZOR@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/27 14:08:54 by RAZOR             #+#    #+#             */
/*   Updated: 2016/09/19 19:55:40 by RAZOR            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static int	ft_create_map(t_list **map, t_list *list_line)
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

static void ft_init_point(t_point **pts)
{
	t_point *tmp;

	tmp = NULL;
	tmp = *pts;

	tmp->x = 0;
	tmp->y = 0;
	tmp->z = 0;
	*pts = tmp;
}

static int ft_parse_line(char *line, int *count_line, t_list **list_line)
{
	t_point	*point;
	t_list	*tmp;
	char	**tmp_read;
	int		i;


	tmp = NULL;
	tmp = *list_line;
	point = NULL;
	i = 0;
	tmp_read = ft_strsplit(line, ' ');
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
		ft_memdel((void **)&data->list_line);
		ft_strdel(&line);
	}
	ft_strdel(&line);
	close(fd);
	return (1);
}
