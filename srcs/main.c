/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/17 14:10:35 by gbourson          #+#    #+#             */
/*   Updated: 2016/10/05 12:48:01 by RAZOR            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int main(int ac, char **av, char **env)
{
    t_env        data;

	ft_init_data(&data);
	ft_static_select(&data, 0);
	if ((env) && (ac < 6))
	{
		if(!ft_open_file(av[1], &data))
		{
			ft_print_err("Error open file");
			return (0);
		}
		// if (!ft_open_dir_palette(&data))
		// {
		// 	ft_print_err("Error open folder");
		// 	return (0);
		// }
		ft_parse_color(&av[2], &data);
		if (!ft_mlx_init(&data))
			return (0);
		if (!ft_img_init(&data))
		{
			ft_print_err("Error img");
			return (0);
		}
		ft_draw(&data);
		mlx_loop(data.mlx_ptr);
	}
	else
		ft_print_err("Env is empty");
    return (0);
}
