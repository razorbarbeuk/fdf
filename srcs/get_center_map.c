/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_center_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: RAZOR <RAZOR@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/26 15:16:51 by RAZOR             #+#    #+#             */
/*   Updated: 2016/08/26 15:17:12 by RAZOR            ###   ########.fr       */
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
