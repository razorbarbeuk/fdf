/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/18 11:46:07 by RAZOR             #+#    #+#             */
/*   Updated: 2016/08/22 11:31:39 by gbourson         ###   ########.fr       */
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

void ft_print_list(t_list **map)
{
	t_point	*point;
	t_list	*tmp;
	t_list	*tmp_list;

	point = NULL;
	tmp = NULL;
	tmp_list = NULL;
	tmp = *map;
	while (tmp)
	{

		tmp_list = (t_list *)tmp->content;
		while (tmp_list)
		{
			point = (t_point *)tmp_list->content;
			//ft_putnbr(point->x);
			// ft_putnbr(point->y);
			if (ft_count_number(point->z) < 2)
			{
				ft_putchar(' ');
				ft_putchar(' ');
			}
			else
				ft_putchar(' ');
			ft_putnbr(point->z);
			point = NULL;
			tmp_list = tmp_list->next;

		}
		tmp_list = NULL;
		point = NULL;
		tmp = tmp->next;
		ft_putchar('\n');
	}
	tmp = NULL;
	ft_putendl("END");
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
