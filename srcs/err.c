/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/18 15:04:50 by gbourson          #+#    #+#             */
/*   Updated: 2016/08/24 16:20:49 by RAZOR            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	print_err(char *str)
{
	ft_putstr_fd(RED, 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\e[0m", 2);
}

void ft_init_tab_int(int *tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		tab[i] = 0;
		i++;
	}
}
