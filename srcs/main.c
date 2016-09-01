/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/17 14:10:35 by gbourson          #+#    #+#             */
/*   Updated: 2016/08/31 19:42:16 by RAZOR            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void ft_draw_line(t_env *data, int *screen_xy, int *screen_xy_next, double *tab)
{
	float	dl;
	float	dh;
	float	c;
	float	m;

	dl = fabs((float)screen_xy[0] - (float)screen_xy_next[0]);
	dh = fabs((float)screen_xy[1] - (float)screen_xy_next[1]);
	c = -1.0;
	m = dh > dl ? dh : dl;
	while (++c <= m) {
		tab[0] = screen_xy[0] + data->left + (c * dl) / m;
		tab[1] = screen_xy[1] + data->top + (c * dh) / m;
		mlx_pixel_put(data->mlx_ptr, data->mlx_win, tab[0], tab[1], 0x00E80C7A);
	}
}

void ft_cal_iso(t_list *tmp_list, int *screen_xy)
{
	ft_elem_num(tmp_list, &screen_xy[0], 1);
	ft_elem_num(tmp_list, &screen_xy[1], 2);
}

void ft_tab_coord(double *tab, int cal_x, int cal_y)
{
	tab[0] = cal_x;
	tab[1] = cal_y;
}

void ft_cal_dist_case(t_env *data)
{
	t_list	*tmp_list;
	t_list	*tmp_list_next;
	int		screen_xy[2];
	int		screen_xy_next[2];

	ft_init_tab_int(screen_xy, 2);
	ft_init_tab_int(screen_xy_next, 2);
	tmp_list = NULL;
	tmp_list_next = NULL;
	if (data->map)
	{
		tmp_list = data->map->content;
		tmp_list_next = tmp_list->next;
		ft_cal_iso(tmp_list, screen_xy);
		ft_cal_iso(tmp_list_next, screen_xy_next);
		data->case_width = ((screen_xy_next[0]) - (screen_xy[0]));
		data->case_height = ((screen_xy_next[1]) - (screen_xy[1]));
	}
}

void ft_draw_pixel(t_env *data)
{
	t_list	*tmp_list;
	t_list	*tmp_list_next;
	t_point *point;
	int		screen_xy[2];
	int		screen_xy_next[2];
	float	dl;
	float	dh;
	//float	am;
	double	tab[2];

	tmp_list = NULL;
	point = NULL;
	ft_init_tab_int(screen_xy, 2);
	ft_init_tab_int(screen_xy_next, 2);
	ft_init_tab_int((int *)tab, 2);
	ft_center_map(data->map, &data->top, &data->left);
	ft_cal_dist_case(data);
	while (data->map)
	{
		tmp_list = data->map->content;
		while (tmp_list)
		{
			point = (t_point *)tmp_list->content;
			if (tmp_list->next)
				tmp_list_next = tmp_list->next;
			ft_cal_iso(tmp_list, screen_xy);
			ft_cal_iso(tmp_list_next, screen_xy_next);
			ft_putchar(' ');
			tab[0] = ((point->x - point->y) * SIZE_CASE) + point->z;
			tab[1] = (((point->x + point->y) * SIZE_CASE)/2) + point->z;
			dl = fabs((float)screen_xy[0] - (float)screen_xy_next[0]);
			dh = fabs((float)screen_xy[1] - (float)screen_xy_next[1]);
			mlx_pixel_put(data->mlx_ptr, data->mlx_win, tab[0] + data->left, tab[1] + data->top, 0x00FFCB0D);
			ft_draw_line(data, screen_xy, screen_xy_next, tab);
			tmp_list = tmp_list->next;
		}
		tmp_list = NULL;
		data->map = data->map->next;
	}
}

int ft_mlx_init(t_env *data)
{
	if ((data->mlx_ptr = mlx_init()) == NULL)
        return (0);
    if ((data->mlx_win = mlx_new_window(data->mlx_ptr, WIN_W, WIN_H, "Hello world")) == NULL)
        return (0);
	return (1);
}

int ft_init_data(t_env *data)
{
	data->mlx_ptr = NULL;
	data->mlx_win = NULL;
	data->top = 0;
	data->left = 0;
	data->case_width = 0;
	data->case_height = 0;
	data->list_line = NULL;
	data->map = NULL;
	return (1);
}

int main(int ac, char **av, char **env)
{
    t_env        data;

	ft_init_data(&data);
	if ((env) && (ac < 3))
	{
		ft_open_file(av[1], &data);
		//ft_print_list(&data.map);
		if (!ft_mlx_init(&data))
			return (0);
		ft_draw_pixel(&data);
	    mlx_loop(data.mlx_ptr);
	}
	else
		print_err("Env is empty");
    return (0);
}
