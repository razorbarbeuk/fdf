/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: RAZOR <RAZOR@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 19:46:01 by RAZOR             #+#    #+#             */
/*   Updated: 2016/09/08 10:15:24 by RAZOR            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void del_elem(void *content, size_t size)
{
	t_point	*point;

	point = (t_point *)content;
	point->x = 0;
	point->y = 0;
	point->z = 0;
	free(point);
	point = NULL;
	size = 0;
}

void del_elem_map(void *content, size_t size)
{
	ft_memdel((void **)&content);
	size = 0;
}
