/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_pixel.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: RAZOR <RAZOR@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 10:22:34 by RAZOR             #+#    #+#             */
/*   Updated: 2016/09/22 18:57:06 by RAZOR            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void ft_draw_pixel(t_env *data, int x, int y, int *tab)
{
	t_color *col_test;
	int pos;

	col_test = ((t_color *)data->color->content);
	pos = (x * data->img.bpp / 8) + (y * data->img.size_line);
	data->img.img[pos] = col_test->b + (tab[2] * tab[4]);
	data->img.img[pos + 1] = col_test->v + (tab[1] * tab[4]);
	data->img.img[pos + 2] = col_test->r + (tab[0] * tab[4]);
}

void ft_draw_line(t_env *data, int *screen_xy, int *screen_xy_next)
{
	int i;
	int distl;
	int disth;
	int color[5];

	ft_init_tab_int(color, 5);
	distl = ((float)screen_xy_next[0] - (float)screen_xy[0]);
	disth = ((float)screen_xy_next[1] - (float)screen_xy[1]);
	if (distl > disth)
	{
		init_color_value(data, distl, color);
		i = screen_xy[0] - 1;
		while (++i <= screen_xy_next[0] && ++color[4])
			ft_draw_pixel(data, i + data->left, (screen_xy[1] + (disth * (i - screen_xy[0])) / distl) + data->top, color);
	}
	else
	{
		init_color_value(data, disth, color);
		i = screen_xy[1] - 1;
		while (++i <= screen_xy_next[1] && ++color[4])
			ft_draw_pixel(data, (screen_xy[0] + (distl * (i - screen_xy[1])) / disth) + data->left, i + data->top, color);
	}
}
