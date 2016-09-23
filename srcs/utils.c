/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: RAZOR <RAZOR@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/27 12:58:29 by RAZOR             #+#    #+#             */
/*   Updated: 2016/09/22 18:35:09 by RAZOR            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int ft_convert_Hex(char *av)
{
	int i;
	int hex;
	int n;

	i = 0;
	n = 0;
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

void ft_init_tab_int(int *tab, size_t c)
{
	int i;

	i = 0;
	while ((size_t)i != c)
	{
		tab[i] = 0;
		i++;
	}
}
