void ft_draw(t_env *data, int screen_x, int screen_y, int *tab)
{
	screen_x = screen_x * SIZE_CASE;
	screen_y = screen_y * SIZE_CASE;
	while (tab[1] < screen_y)
	{
		while (tab[0] < screen_x)
		{
			mlx_pixel_put(data->mlx_ptr, data->mlx_win, tab[0], tab[1], 0x00FFFFFF);
			tab[0]++;
		}
		mlx_pixel_put(data->mlx_ptr, data->mlx_win, tab[0], tab[1], 0x00FFFFFF);
		tab[1]++;
	}
}

int ft_center_map(t_list *map, int *top, int *left)
{
	int x1;
	int x2;
	int y1;
	t_list	*tmp;
	t_list	*start_tmp;
	t_point	*point;


	y1 = 0;
	x2 = 0;
	tmp = NULL;
	start_tmp = NULL;
	start_tmp = tmp;
	tmp = (t_list *)map->content;
	while (tmp->next)
		tmp = tmp->next;
	point = (t_point *)tmp->content;
	x2 = (((point->x - point->y) * SIZE_CASE));
	tmp = start_tmp;
	while (map->next)
		map = map->next;
	tmp = (t_list *)map->content;
	point = (t_point *)tmp->content;
	x1 = (((point->x - point->y) * SIZE_CASE));
	while (tmp->next)
		tmp = tmp->next;
	point = (t_point *)tmp->content;
	y1 = (((point->x + point->y) * SIZE_CASE)/2);
	x1 = x1 + x2;
	ft_putnbr(x1);
	(*left) = (WIN_W - x1)/2;
	(*top) = (WIN_H - y1)/2;
	ft_putnbr(x1);
	ft_putchar(':');
	ft_putnbr(y1);
	ft_putchar('\n');
	ft_putnbr(*left);
	ft_putchar(':');
	ft_putnbr(*top);
	// ft_putnbr((point->y));
	return (0);
}

void ft_print_list_kk(t_list **lst)
{
	t_point	*point;
	t_list	*tmp;

	point = NULL;
	tmp = NULL;
	tmp = *lst;
	while (tmp)
	{
		point = (t_point *)tmp->content;
			//ft_putnbr(point->x);
			// ft_putnbr(point->y);
		ft_putnbr(point->z);
		ft_putchar(' ');
		tmp = tmp->next;
	}
	ft_putendl("END LST");
}

void ft_print_list(t_list **map)
{
	t_point	*point;
	t_list	*tmp;
	t_list	*tmp_list;

	point = NULL;
	tmp = NULL;
	tmp_list = NULL;
	tmp = *map;
	while (tmp)
	{

		tmp_list = (t_list *)tmp->content;
		while (tmp_list)
		{
			point = (t_point *)tmp_list->content;
			//ft_putnbr(point->x);
			// ft_putnbr(point->y);
			if (ft_count_number(point->z) < 2)
			{
				ft_putchar(' ');
				ft_putchar(' ');
			}
			else
				ft_putchar(' ');
			ft_putnbr(point->z);
			point = NULL;
			tmp_list = tmp_list->next;

		}
		tmp_list = NULL;
		point = NULL;
		tmp = tmp->next;
		ft_putchar('\n');
	}
	tmp = NULL;
	ft_putendl("END");
}

// while (tab[0] < (screen_x + data->left))
// {
// 	mlx_pixel_put(data->mlx_ptr, data->mlx_win, tab[0], tab[1], 0x00FFCB0D);
// 	tab[0]++;
// 	tab[1] += 0.5;
// }
// while (tab[1] < (screen_x + data->left))
// {
// 	mlx_pixel_put(data->mlx_ptr, data->mlx_win, tab[0], tab[1], 0x00FFCB0D);
// 	tab[0] -= 2;
// 	tab[1]++;
// }

// ft_elem_num(tmp_list, &screen_x, 1);
// ft_elem_num(tmp_list, &screen_y, 2);
// ft_elem_num(tmp_list_next, &screen_x_next, 1);
// ft_elem_num(tmp_list_next, &screen_y_next, 2);
//screen_y = point->y * SIZE_CASE;
//disth = ((point_next->y + data->top) - (point->y + data->top)) * SIZE_CASE;

// screen_x = (point->x * SIZE_CASE) + data->left;
// screen_x_next = (point_next->x * SIZE_CASE) + data->left;

// screen_y = (point->y * SIZE_CASE) + data->top;
// screen_y_next = (point_next->y * SIZE_CASE) + data->top;

// ft_putnbr(point->y + data->top);
// ft_putchar(':');
// ft_putnbr(point_next->y + data->top);
// ft_putchar(' ');
//distl = ((screen_x_next + data->left) - (screen_x + data->left));

//disth = ((point->x * SIZE_CASE) - (point_next->x * SIZE_CASE));


// ft_putnbr(distl);
// ft_putchar(':');
// ft_putnbr(disth);
// ft_putchar(' ');
//point_next = (t_point *)tmp_list->next->content;
// tab[0] = point->x + data->left;
// tab[1] = point->y + data->top;
// screen_x = point->x * SIZE_CASE;
// screen_y = point->y * SIZE_CASE;
// tab[0] = point->x + data->left;
// tab[1] = point->y + data->top;
// screen_x = point->x * SIZE_CASE;
// screen_y = point->y * SIZE_CASE;

// ft_putnbr(point_next->x + data->left);
// ft_putchar(':');
// ft_putnbr(point_next->y + data->left);
// ft_putchar(' ');


// while (tab[0] < (screen_x + data->left))
// {
// 	mlx_pixel_put(data->mlx_ptr, data->mlx_win, tab[0], (screen_y + data->top), 0x00FFCB0D);
// 	tab[0]++;
// }
// while (tab[1] < (screen_y + data->top))
// {
// 	mlx_pixel_put(data->mlx_ptr, data->mlx_win, (screen_x + data->left), tab[1], 0x00FFCB0D);
// 	tab[1]++;
// }

//mlx_pixel_put(data->mlx_ptr, data->mlx_win, screen_x, screen_y, 0x00FFCB0D);


// ft_cal_iso(tmp_list, screen_xy);
// ft_cal_iso(tmp_list_next, screen_xy_next);
// ft_draw_line(data, screen_xy, screen_xy_next, tab);
//ft_tab_coord(tab, (screen_xy[0] + data->left), (screen_xy[1] + data->top));

//ft_draw_line(double *tab, )
// while ((++tab[0]) < (screen_xy[0] + data->left) && data->map->next)
// {
// 	mlx_pixel_put(data->mlx_ptr, data->mlx_win, tab[0], tab[1], 0x00FFCB0D);
// 	tab[1] -= 0.5;
// }
// ft_tab_coord(tab, (screen_xy[0] + data->left), (screen_xy[1] + data->top));
// while (tab[1] < (screen_xy_next[1] + data->top))
// {
// 	mlx_pixel_put(data->mlx_ptr, data->mlx_win, tab[0], tab[1], 0x00E80C7A);
// 	tab[0]++;
// 	tab[1] += 0.5;
// }

// if (!tmp_list->next)
// {
// 	// while (++tab[0] < (screen_xy[0] + data->left))
// 	// {
// 	// 	mlx_pixel_put(data->mlx_ptr, data->mlx_win, tab[0], tab[1], 0x00E80C7A);
// 	// 	//tab[0]--;
// 	// 	tab[1] -= 0.5;
// 	// }
// }
//mlx_pixel_put(data->mlx_ptr, data->mlx_win, screen_xy[0] + data->left, screen_xy[1] + data->top, 0x00FFCB0D);
//ft_draw_line(data, screen_x + data->left, screen_x_next + data->left);

// screen_xy_next[0] = screen_xy[0] - SIZE_CASE + point->z;
// screen_xy_next[1] = (screen_xy[1] + SIZE_CASE/2) + point->z;

// dl = screen_xy_next[0] - screen_xy[0];
// dh = screen_xy_next[1] - screen_xy[1];
// screen_xy_next[0] = (screen_xy[0] - dl);
// screen_xy_next[1] = (screen_xy[1] + dh);


	//screen_xy_next[0] = screen_xy[0] - dl;
	// screen_xy_next[1] = screen_xy[1] + dh;
	// dh = (float)screen_xy_next[1] - (float)screen_xy[1];
	// ft_putnbr(i);
	// ft_putchar(':');
	// ft_putnbr(screen_xy_next[1]);
	// ft_putchar(' ');
	// while (++i <= screen_xy_next[1])
	// 	mlx_pixel_put(data->mlx_ptr, data->mlx_win, (screen_xy[0] + (dl * (i - screen_xy[1])) / dh) + data->left, i + data->top, 0x00FFCB0D);

	// void	ft_elem_num(t_list *elem, int *num, int opt)
	// {
	// 	t_point	*point;
	//
	// 	point = NULL;
	// 	point = (t_point *)elem->content;
	// 	if (!elem->next && !opt)
	// 		(*num) = (((point->x - point->y) * SIZE_CASE));
	// 	if (opt == 1)
	// 		(*num) = (((point->x - point->y) * SIZE_CASE));
	// 	if (opt == 2)
	// 		(*num) = (((point->x + point->y) * SIZE_CASE)/2);
	// 	return ;
	// }

	// init_color_value(data, distl, color);
	// i = screen_xy[0] - 1;
	// // distl = fabs((float)distl);
	// while (++i <= screen_xy_next[0] && ft_color_counter(&color[4], color_count))
	// 	ft_draw_pixel(data, i + data->left, (screen_xy[1] + (disth * (i - screen_xy[0])) / distl) + data->top, color);
// if (distl < 0)
// {
// 	init_color_value(data, distl, color);
// 	i = screen_xy_next[0] - 1;
// 	distl = fabs((float)distl);
// 	while (++i <= screen_xy[0] && ft_color_counter(&color[4], color_count))
// 		ft_draw_pixel(data, i + data->left, (screen_xy_next[1] + (disth * (i - screen_xy_next[0])) / distl) + data->top, color);
// }
// init_color_value(data, disth, color);
// i = screen_xy_next[1] - 1;
// disth = fabs((float)disth);
// while (++i <= screen_xy[1] && ft_color_counter(&color[4], color_count))
// 	ft_draw_pixel(data, (screen_xy_next[0] + (distl * (i - screen_xy_next[1])) / disth) + data->left, i + data->top, color);
