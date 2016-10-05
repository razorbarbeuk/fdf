/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: RAZOR <RAZOR@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 19:38:34 by RAZOR             #+#    #+#             */
/*   Updated: 2016/10/03 16:59:34 by RAZOR            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int get_color_value(t_env *data, int tab, int steps, char c)
{
	t_color *col;
	t_list	*tmp;
	int		i;

	i = 0;
	col = NULL;
	tmp = NULL;
	tmp = data->color;
	while (i < steps)
	{
		col = ((t_color *)tmp->content);
		if (c == 'R')
			return ((col->r + (tab * i)));
		if (c == 'V')
			return ((col->v + (tab * i)));
		if (c == 'B')
			return ((col->b + (tab * i)));
		i++;
	}
	return (0);
}

void init_color_value(t_env *data, int step, int *tab)
{
	t_color *col;
	t_color *col_next;
	t_list	*tmp;

	col = NULL;
	tmp = NULL;
	tmp = data->color;
	col_next = NULL;
	while (tmp && step)
	{
		col = ((t_color *)tmp->content);
		if (tmp->next)
		{
			col_next = ((t_color *)tmp->next->content);
			tab[0] = (col_next->r - col->r) / (step);
			tab[1] = (col_next->v - col->v) / (step);
			tab[2] = (col_next->b - col->b) / (step);
		}
		tmp = tmp->next;
	}
	return ;
}

static int ft_stock_color(char **av, t_env **data)
{
	t_color	*color;
	t_list	*tmp_color;
	int		i;
	int		hex;

	i = 0;
	hex = 0;
	color = NULL;
	tmp_color = NULL;
	while (av[i])
	{
		if (!(color = (t_color *)malloc(sizeof(t_color))))
			return (0);
		ft_init_color(&color);
		hex = ft_convert_Hex(&av[i][2]);
		color->r = hex >> 16;
		color->v = hex >> 8;
		color->b = hex;
		ft_lstadd_back(&tmp_color, ft_lstnew(color, sizeof(t_color)));
		ft_memdel((void **)&color);
		i++;
	}
	((*data)->color) = tmp_color;
	color = NULL;
	tmp_color = NULL;
	return (1);
}

int ft_parse_color(char **av, t_env *data)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if ((av[i][0] != '0' && av[i][1] != 'x') || (av[i][0] != '0' && av[i][1] != 'X'))
			ft_print_err("Error code Hexa");
		else
		{
			if (!ft_stock_color(&av[0], &data))
				return (0);
		}
		i++;
	}
	return (1);
}
