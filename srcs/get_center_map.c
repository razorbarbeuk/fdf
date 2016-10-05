/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_center_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: RAZOR <RAZOR@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/26 15:16:51 by RAZOR             #+#    #+#             */
/*   Updated: 2016/10/03 12:46:50 by RAZOR            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	ft_cal_case(t_env *data)
{
	float	size_case_x;
	float	size_case_y;
	t_list	*tmp;
	int		count;

	tmp = NULL;
	tmp = data->map;
	count = 0;
	while (tmp)
	{
		count++;
		tmp = tmp->next;
	}
	data->count_line = count;
	size_case_x = (WIN_W - 100)/data->nb_case;
	size_case_y = (WIN_H - 100)/data->count_line;
	data->case_width = size_case_x;
	data->case_height = size_case_y;
	ft_static_select(data, 0);
}

int ft_center_map(t_list *map, int *top, int *left)
{
	float x1;
	float x2;
	float y1;
	t_env	*data;
	t_list	*tmp;

	y1 = 0;
	x1 = 0;
	x2 = 0;
	data = NULL;
	tmp = NULL;
	data = ft_static_select(data, 1);
	ft_lstiter_coord(map, &x2, 0, &ft_elem_num);
	while (map->next)
		map = map->next;
	tmp = (t_list *)map->content;
	ft_elem_num(tmp, &x1, 1);
	ft_lstiter_coord(map, &y1, 2, &ft_elem_num);
	data->size_x = (x2 - x1);
	(*left) = (WIN_W - (x1 + x2))/2;
	(*top) = (WIN_H - y1)/2;
	data->size_y = (y1 - (*top));
	return (0);
}
