/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: RAZOR <RAZOR@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/18 11:46:07 by RAZOR             #+#    #+#             */
/*   Updated: 2016/10/04 15:07:30 by RAZOR            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *tmp;

	tmp = *alst;
	if (tmp == NULL)
		*alst = new;
	else if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void	ft_elem_num(t_list *elem, float *num, int opt)
{
	t_point	*point;
	t_env	*data;
	int iso_x;
	int iso_y;

	point = NULL;
	data = NULL;
	point = (t_point *)elem->content;
	iso_x = 0;
	iso_y = 0;
	data = ft_static_select(data, 1);
	iso_x = (point->x * data->scale) - ((point->z));
	iso_y = (point->y * data->scale) - ((point->z));
	if (!elem->next && !opt)
		(*num) = ((iso_x - iso_y));
	if (opt == 1)
		(*num) = ((iso_x - iso_y));
	if (opt == 2)
		(*num) = ((iso_x + iso_y)/2);
	return ;
}

void	ft_lstiter_coord(t_list *lst, float *num, int opt, void (*f)(t_list *elem, float *num, int opt))
{
	t_list *tmp;

	tmp = NULL;
	tmp = (t_list *)lst->content;
	while (tmp)
	{
		f(tmp, num, opt);
		tmp = tmp->next;
	}
}
