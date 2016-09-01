/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: RAZOR <RAZOR@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/18 11:46:07 by RAZOR             #+#    #+#             */
/*   Updated: 2016/08/31 12:20:35 by RAZOR            ###   ########.fr       */
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

// void	ft_elem_num(t_list *elem, int *num, int opt)
// {
// 	t_point	*point;
//
// 	point = NULL;
// 	point = (t_point *)elem->content;
// 	if (!elem->next && !opt)
// 		(*num) = (((point->x - point->y) * SIZE_CASE));
// 	if (opt == 1)
// 		(*num) = (((point->x - point->y) * SIZE_CASE));
// 	if (opt == 2)
// 		(*num) = (((point->x + point->y) * SIZE_CASE)/2);
// 	return ;
// }

void	ft_elem_num(t_list *elem, int *num, int opt)
{
	t_point	*point;
	int iso_x;
	int iso_y;

	point = NULL;
	point = (t_point *)elem->content;
	iso_x = 0;
	iso_y = 0;
	iso_x = (point->x) * SIZE_CASE;
	iso_y = (point->y) * SIZE_CASE;
	if (!elem->next && !opt)
		(*num) = ((iso_x - iso_y));
	if (opt == 1)
		(*num) = ((iso_x - iso_y));
	if (opt == 2)
		(*num) = ((iso_x + iso_y)/2);
	return ;
}

void	ft_lstiter_coord(t_list *lst, int *num, int opt, void (*f)(t_list *elem, int *num, int opt))
{
	t_list *tmp;

	tmp = NULL;
	tmp = (t_list *)lst->content;;
	while (tmp)
	{
		f(tmp, num, opt);
		tmp = tmp->next;
	}
}
