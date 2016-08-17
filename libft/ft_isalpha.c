/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:56:50 by gbourson          #+#    #+#             */
/*   Updated: 2016/06/30 12:12:40 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isalpha(int c)
{
	if (((c >= 'a') && (c <= 'z')) || ((c >= 'A') && (c <= 'Z')))
		return (1);
	else
		return (0);
}

int		ft_isalpha_string(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (((str[i] >= 'a') && (str[i] <= 'z')) || ((str[i] >= 'A') \
			&& (str[i] <= 'Z')) || (str[i] == '_') || (str[i] == '-'))
			i++;
		else
			return (0);
	}
	return (1);
}
