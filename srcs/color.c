/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 19:38:34 by RAZOR             #+#    #+#             */
/*   Updated: 2016/09/20 16:11:06 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static void ft_init_color(t_color **color)
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

static int ft_stock_color(char **av, t_env **data)
{
	t_color	*color;
	t_list	*tmp_color;
	int		i;

	i = 0;
	color = NULL;
	tmp_color = NULL;
	while (av[i])
	{
		if (!(color = (t_color *)malloc(sizeof(t_color))))
			return (0);
		ft_init_color(&color);
		ft_putstr(av[i]);
		color->r = av[i];
		color->v = av[i] >> 8;
		color->b = av[i] >> 16;
		ft_putnbr(color->r);
		ft_putnbr(color->v);
		ft_putnbr(color->b);
		ft_lstadd_back(&tmp_color, ft_lstnew(color, sizeof(t_color)));
		// ft_memdel((void **)&color);
		// ft_strdel(&av[i]);
		i++;
	}
	((*data)->color) = tmp_color;
	color = NULL;
	//tmp_color = NULL;
	return (1);
}

int ft_parse_color(char **av, t_env *data)
{
	int	i;
	int	j;

	i = 0;
	while (av[i])
	{
		j = 0;
		while (av[i][j] && av[i][0] != '0' && av[i][1] != 'x')
		{
			if (av[i][0] != '0' && av[i][1] != 'x')
				return (0);
			j++;
		}
		i++;
	}
	ft_stock_color(&av[0], &data);
	return (1);
}
