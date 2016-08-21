/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: RAZOR <RAZOR@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/18 11:46:07 by RAZOR             #+#    #+#             */
/*   Updated: 2016/08/21 23:12:38 by RAZOR            ###   ########.fr       */
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

void ft_print_list_kk(t_list **lst)
{
	t_point	*point;
	t_list	*tmp;

	point = NULL;
	tmp = NULL;
	tmp = *lst;
	while (tmp)
	{
		point = (t_point *)tmp->content;
			//ft_putnbr(point->x);
			// ft_putnbr(point->y);
		ft_putnbr(point->z);
		ft_putchar(' ');
		tmp = tmp->next;
	}
	ft_putendl("END LST");
}
// void ft_free_list(t_list **lst)
// {
// 	t_point	*point;
// 	t_list	*tmp;
//
// 	point = NULL;
// 	tmp = NULL;
// 	tmp = *lst;
// 	while (tmp)
// 	{
// 		point = ((t_point *)tmp->content);
// 		ft_memdel((void **)&point);
// 		tmp = tmp->next;
// 	}
// 	//ft_memdel((void **)&tmp);
// }
