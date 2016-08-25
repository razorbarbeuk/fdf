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
