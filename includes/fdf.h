/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 17:59:26 by gbourson          #+#    #+#             */
/*   Updated: 2016/08/27 14:10:45 by RAZOR            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"
# include <../minilibx_macos/mlx.h>
# include <unistd.h>
# include <pwd.h>
# include <stdlib.h>
# include <string.h>
# include <signal.h>


# define OPT "i"
# define ERROR_OPT() ft_putendl("Erreur option");
# define BUILD_FIND 0
# define BUILD_EXE 1
# define RED "\e[31m"
# define ORANGE "\033[38;2;255;189;0m"
# define WIN_W 800
# define WIN_H 600
# define SIZE_CASE 24

typedef struct		s_point
{
	int				x;
	int				y;
	int				z;
}					t_point;

typedef struct		s_env
{
	void			*mlx_ptr;
	void			*mlx_win;
	int				top;
	int				left;
	int				case_width;
	int				case_height;
	t_list			*list_line;
	t_list			*map;
}					t_env;

/*Parsing line*/
int ft_open_file(char *av, t_env *data);

/*List_utils*/
void	ft_lstadd_back(t_list **alst, t_list *new);
void	ft_lstiter_coord(t_list *lst, int *num, int opt, void (*f)(t_list *elem, int *num, int opt));
void	ft_elem_num(t_list *elem, int *num, int opt);

/*err*/
void	print_err(char *str);

/*utils*/
void ft_init_tab_int(int *tab, size_t c);

/*Print utils*/
void ft_print_list(t_list **map);

/*get_center_map*/
int ft_center_map(t_list *map, int *top, int *left);

#endif
