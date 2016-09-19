/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_pixel.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: RAZOR <RAZOR@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 10:22:34 by RAZOR             #+#    #+#             */
/*   Updated: 2016/09/14 18:59:33 by RAZOR            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void ft_draw_pixel(t_env *data, int x, int y)
{
	int pos;
	int color;

	color = 0x0D6386;
	// ft_putnbr(x);
	// ft_putchar(' ');
	// ft_putnbr(data->img.bpp);
	// ft_putchar(' ');
	pos = (x * data->img.bpp / 8) + (y * data->img.size_line);
	// ft_putnbr(pos);
	// ft_putchar(' ');
	data->img.img[pos] = color;
	ft_putnbr(color);
	ft_putchar('\n');
	data->img.img[pos + 1] = color >> 8;
	ft_putnbr(color >> 8);
	ft_putchar('\n');
	data->img.img[pos + 2] = color >> 16;
	ft_putnbr(color >> 16);
	ft_putchar('\n');
}

void ft_draw_line(t_env *data, int *screen_xy, int *screen_xy_next)
{
	int i;
	int distl;
	int disth;

	distl = ((float)screen_xy_next[0] - (float)screen_xy[0]);
	disth = ((float)screen_xy_next[1] - (float)screen_xy[1]);
	if (distl > disth)
	{
		i = screen_xy[0] - 1;
		while (++i <= screen_xy_next[0])
			ft_draw_pixel(data, i + data->left, (screen_xy[1] + (disth * (i - screen_xy[0])) / distl) + data->top);
			//mlx_pixel_put(data->mlx_ptr, data->mlx_win, i + data->left, (screen_xy[1] + (disth * (i - screen_xy[0])) / distl) + data->top, 0x00E80C7A);


	}
	else
	{
		i = screen_xy[1] - 1;
		while (++i <= screen_xy_next[1])
			ft_draw_pixel(data, (screen_xy[0] + (distl * (i - screen_xy[1])) / disth) + data->left, i + data->top);
			//mlx_pixel_put(data->mlx_ptr, data->mlx_win, (screen_xy[0] + (distl * (i - screen_xy[1])) / disth) + data->left, i + data->top, 0x00E80C7A);


	}

}
