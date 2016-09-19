/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: RAZOR <RAZOR@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 15:03:23 by RAZOR             #+#    #+#             */
/*   Updated: 2016/09/09 12:49:36 by RAZOR            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static void ft_cal_iso(t_list *tmp_list, int *screen_xy)
{
	ft_elem_num(tmp_list, &screen_xy[0], 1);
	ft_elem_num(tmp_list, &screen_xy[1], 2);
}

static void ft_draw_next(t_env *data, int *screen_xy, int *screen_xy_next, t_list **tmp, int *count)
{
	ft_cal_iso(tmp[0], screen_xy);
	if (tmp[0]->next)
	{
		tmp[1] = tmp[0]->next;
		ft_cal_iso(tmp[1], screen_xy_next);
		ft_draw_line(data, screen_xy, screen_xy_next);
	}
	if (data->map->next && tmp[0])
	{
		count[1] = -1;
		ft_init_tab_int(screen_xy_next, 2);
		tmp[1] = data->map->next->content;
		while (++count[1] != count[0] && tmp[1])
			tmp[1] = tmp[1]->next;
		ft_cal_iso(tmp[1], screen_xy_next);
		ft_draw_line(data, screen_xy, screen_xy_next);
	}
}

static void ft_draw_line_init(t_env *data, int *screen_xy, int *screen_xy_next, t_list **tmp)
{
	tmp[0] = NULL;
	tmp[1] = NULL;
	tmp[2] = NULL;
	ft_init_tab_int(screen_xy, 2);
	ft_init_tab_int(screen_xy_next, 2);
	ft_center_map(data->map, &data->top, &data->left);
}

void ft_draw(t_env *data)
{
	t_list	*tmp[3];
	int		screen_xy[2];
	int		screen_xy_next[2];
	int		count[2];

	ft_draw_line_init(data, screen_xy, screen_xy_next, tmp);
	tmp[2] = data->map;
	while (data->map)
	{
		count[0] = 0;
		tmp[0] = data->map->content;
		while (tmp[0])
		{
			ft_draw_next(data, screen_xy, screen_xy_next, tmp, count);
			count[0]++;
			tmp[1] = NULL;
			tmp[0] = tmp[0]->next;
		}
		ft_lstdel((t_list **)&data->map->content, &del_elem);
		tmp[0] = NULL;
		data->map = data->map->next;
	}
	ft_lstdel(&tmp[2], &del_elem_map);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img.adress, 0, 0);
}
