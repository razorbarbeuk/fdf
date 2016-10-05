/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_pixel.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: RAZOR <RAZOR@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 10:22:34 by RAZOR             #+#    #+#             */
/*   Updated: 2016/10/04 17:44:18 by RAZOR            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static void ft_draw_pixel(t_env *data, int x, int y, int *tab)
{
	t_color *col_test;
	int pos;

	col_test = ((t_color *)data->color->content);
	if ((x <= (WIN_W) && y <= (WIN_H)) && (x >= 0 && y >= 0))
	{
		pos = (x * data->img.bpp / 8) + (y * data->img.size_line);
		data->img.img[pos] = col_test->b + (tab[2] * tab[4]);
		data->img.img[pos + 1] = col_test->v + (tab[1] * tab[4]);
		data->img.img[pos + 2] = col_test->r + (tab[0] * tab[4]);
	}
}

static int	ft_color_counter(int *color, int color_count, int dist)
{
	if (color_count > 0)
		return((*color) = 1);
	if (color_count == 0)
		return((*color) = dist);
	else
		return (++(*color));
}

void ft_draw_line(t_env *data, float *screen_xy, float *screen_xy_next, int color_count)
{
	double i;
	double distl;
	double disth;
	int color[5];

	ft_init_tab_int(color, 5);
	distl = (screen_xy_next[0] - screen_xy[0]);
	disth = (screen_xy_next[1] - screen_xy[1]);
	init_color_value(data, fabs((float)disth), color);
	i = screen_xy[1] - 1;
	while (++i < screen_xy_next[1] && ft_color_counter(&color[4], color_count, fabs((float)disth)))
		ft_draw_pixel(data, (screen_xy[0] + (distl * (i - screen_xy[1])) / disth) + data->left, i + data->top, color);
	i = screen_xy_next[1];
	while (++i < screen_xy[1] && ft_color_counter(&color[4], color_count, fabs((float)disth)))
		ft_draw_pixel(data, (screen_xy_next[0] + (distl * (i - screen_xy_next[1])) / disth) + data->left, i + data->top, color);
}
