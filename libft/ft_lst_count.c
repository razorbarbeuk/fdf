/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_count.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/13 14:45:25 by gbourson          #+#    #+#             */
/*   Updated: 2016/07/13 14:45:39 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		lst_count(t_list *env_lst)
{
	int count;

	count = 0;
	while (env_lst)
	{
		env_lst = env_lst->next;
		count++;
	}
	return (count);
}
