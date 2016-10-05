/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: RAZOR <RAZOR@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 15:03:23 by RAZOR             #+#    #+#             */
/*   Updated: 2016/10/04 17:33:10 by RAZOR            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static void ft_cal_iso(t_list *tmp_list, float *screen_xy)
{
	ft_elem_num(tmp_list, &screen_xy[0], 1);
	ft_elem_num(tmp_list, &screen_xy[1], 2);
}

static int ft_amplitude(int amplitude_cur, int amplitude_next)
{
	if (amplitude_cur != amplitude_next)
		return (amplitude_next - amplitude_cur);
	else
		return (amplitude_cur);
}

static void ft_draw_next(t_env *data, float *screen_xy, float *screen_xy_next, t_list **tmp, int *count)
{
	t_point	*point;
	t_point	*point_next;
	float	color;

	point = NULL;
	point_next = NULL;
	color = 0.0;
	ft_cal_iso(tmp[0], screen_xy);
	if (tmp[0]->next)
	{
		tmp[1] = tmp[0]->next;
		point = (t_point *)tmp[0]->content;
		point_next = (t_point *)tmp[1]->content;
		ft_cal_iso(tmp[1], screen_xy_next);
		ft_draw_line(data, screen_xy, screen_xy_next, ft_amplitude(point->z, point_next->z));
	}
	if (data->map->next && tmp[0])
	{
		point = NULL;
		point_next = NULL;
		count[1] = 0;
		ft_init_tab_int((int *)screen_xy_next, 2);
		point = (t_point *)tmp[0]->content;
		tmp[1] = data->map->next->content;
		while (count[1]++ != count[0] && tmp[1])
			tmp[1] = tmp[1]->next;
		point_next = (t_point *)tmp[1]->content;
		ft_cal_iso(tmp[1], screen_xy_next);
		ft_draw_line(data, screen_xy, screen_xy_next, ft_amplitude(point->z, point_next->z));
	}
}

static void ft_draw_scale(t_env *data)
{
	float	hyp;

	hyp = 0.0;
	hyp = sqrt(pow(data->count_line, 2.0) + pow(data->nb_case, 2.0)) + 1.0;
	if (hyp != 0)
		data->scale = (WIN_W - 100)/(hyp * 1.2);
	ft_static_select(data, 0);
}

static void ft_draw_line_init(t_env *data, float *screen_xy, float *screen_xy_next, t_list **tmp)
{
	tmp[0] = NULL;
	tmp[1] = NULL;
	tmp[2] = NULL;
	ft_init_tab_int((int *)screen_xy, 2);
	ft_init_tab_int((int *)screen_xy_next, 2);
	ft_center_map(data->map, &data->top, &data->left);
}

void ft_draw(t_env *data)
{
	t_list	*tmp[3];
	float	screen_xy[2];
	float	screen_xy_next[2];
	int		count[2];

	ft_cal_case(data);
	ft_draw_scale(data);
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
		ft_putchar('\n');
		data->map = data->map->next;
	}
	ft_lstdel(&tmp[2], &del_elem_map);
	//ft_draw_face(data, screen_xy, screen_xy_next);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img.adress, 0, 0);
}
