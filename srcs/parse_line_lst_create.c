/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line_lst_create.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: RAZOR <RAZOR@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/27 14:08:54 by RAZOR             #+#    #+#             */
/*   Updated: 2016/10/04 18:18:36 by RAZOR            ###   ########.fr       */
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

static int ft_parse_line(char *line, int count_line, t_list **list_line)
{
	t_point	*point;
	t_list	*tmp;
	t_env	*data;
	char	**tmp_read;
	int		i;


	tmp = NULL;
	tmp = *list_line;
	point = NULL;
	i = 0;
	data = NULL;
	data = ft_static_select(data, 1);
	tmp_read = ft_strsplit(line, ' ');
	while (tmp_read[i])
	{
		point = (t_point *)malloc(sizeof(t_point));
		ft_init_point(&point);
		point->x = i;
		point->y = count_line;
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

void ft_count_case(t_env *data, char *line)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (line[i])
	{
		if ((line[i] != ' ') && (line[i] != '\t'))
			count++;
		i++;
	}
	if (count > data->nb_case)
		data->nb_case = count;
}

int ft_open_file(char *av, t_env *data)
{
	int fd;
	char *line;

	fd = 0;
	line = NULL;
	if ((fd = open(av, O_RDONLY)) == -1)
		return (0);
	while (get_next_line(fd, &line))
	{
		ft_count_case(data, line);
		if ((*line) && ft_parse_line(line, data->count_line, &data->list_line))
		{
			ft_create_map(&data->map, data->list_line);
			data->count_line++;
		}
		data = ft_static_select(data, 0);
		ft_memdel((void **)&data->list_line);
		ft_strdel(&line);
	}
	ft_strdel(&line);
	close(fd);
	return (1);
}
