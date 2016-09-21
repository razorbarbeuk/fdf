/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 19:38:34 by RAZOR             #+#    #+#             */
/*   Updated: 2016/09/21 16:49:51 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static int ft_convert_Hex(char *av)
{
	int i;
	int hex;
	int n;

	i = 0;
	n = 0;
	if (av[i] == '0')
	{
		++i;
		if (av[i] == 'x' || av[i] == 'X')
			++i;
		else
			return (-1);
		while (av[i])
		{
			if (av[i] >= '0' && av[i] <= '9')
				hex = av[i] - '0';
			if (av[i] >= 'a' && av[i] <= 'f')
				hex = av[i] - 'a' + 10;
			if (av[i] >= 'A' && av[i] <= 'F')
				hex = av[i] - 'A' + 10;
			n = 16 * n + hex;
			i++;
		}
		return (n);
	}
	return (-1);
}

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
		hex = ft_convert_Hex(av[i]);
		ft_putnbr(hex);
		ft_putchar(' ');
		color->r = hex;
		// ft_putnbr(color->r);
		// ft_putchar(' ');
		color->v = hex >> 8;
		// ft_putnbr(color->v);
		// ft_putchar(' ');
		color->b = hex >> 16;
		// ft_putnbr(color->b);
		// ft_putchar('\n');
		ft_lstadd_back(&tmp_color, ft_lstnew(color, sizeof(t_color)));
		ft_memdel((void **)&color);
		//ft_strdel(&av[i]);
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
	int	j;

	i = 0;
	while (av[i])
	{
		j = 0;
		while (av[i][j] && av[i][0] != '0' && av[i][1] != 'x')
		{
			if ((av[i][0] != '0' && av[i][1] != 'x') || (av[i][0] != '0' && av[i][1] != 'X'))
				return (0);
			j++;
		}
		i++;
	}
	ft_stock_color(&av[0], &data);
	return (1);
}
