/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/17 14:10:35 by gbourson          #+#    #+#             */
/*   Updated: 2016/09/09 12:50:53 by RAZOR            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

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
		if (!ft_img_init(&data))
		{
			print_err("Error img");
			return (0);
		}
		ft_draw(&data);
		mlx_loop(data.mlx_ptr);
	}
	else
		print_err("Env is empty");
    return (0);
}
