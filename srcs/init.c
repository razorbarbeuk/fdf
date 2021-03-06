/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: RAZOR <RAZOR@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 12:00:23 by RAZOR             #+#    #+#             */
/*   Updated: 2016/10/02 19:27:11 by RAZOR            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

t_env *ft_static_select(t_env *data, int i)
{
	static t_env tmp;

	if (i == 0)
		tmp = *data;
	return (&tmp);
}

int ft_img_init(t_env *data)
{
	if ((data->img.adress = mlx_new_image(data->mlx_ptr, WIN_W, WIN_H)) == NULL)
		return (0);
	if ((data->img.img = mlx_get_data_addr(data->img.adress, &data->img.bpp, &data->img.size_line, &data->img.endian)) == NULL)
		return (0);
	return (1);
}

int ft_mlx_init(t_env *data)
{
	if ((data->mlx_ptr = mlx_init()) == NULL)
		return (0);
	if ((data->mlx_win = mlx_new_window(data->mlx_ptr, WIN_W, WIN_H, "fdf")) == NULL)
		return (0);
	return (1);
}

void ft_init_color(t_color **color)
{
	t_color *tmp;

	tmp = NULL;
	tmp = *color;
	tmp->r = 0;
	tmp->v = 0;
	tmp->b = 0;
	*color = tmp;
	tmp = NULL;
}

void ft_init_data(t_env *data)
{
	data->mlx_ptr = NULL;
	data->mlx_win = NULL;
	data->top = 0;
	data->left = 0;
	data->nb_case = 0;
	data->count_line = 0;
	data->scale = 1.1;
	data->case_width = 0;
	data->case_height = 0;
	data->list_line = NULL;
	data->map = NULL;
}
