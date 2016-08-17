/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 15:31:48 by gbourson          #+#    #+#             */
/*   Updated: 2016/07/19 12:38:56 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striter(char *s, void (*f)(char *))
{
	if (s && f)
	{
		while (*s)
			f(s++);
	}
}

void	ft_striter_c(char *s, void (*f)(char))
{
	if (s && f)
	{
		while (*s)
		{
			f(*s);
			s++;
		}
	}
}
