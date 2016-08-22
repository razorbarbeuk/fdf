/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 17:59:26 by gbourson          #+#    #+#             */
/*   Updated: 2016/08/22 13:44:11 by gbourson         ###   ########.fr       */
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
# define SIZE_CASE 20

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
	int				origin;
	t_list			*list_line;
	t_list			*map;
}					t_env;

/*List_utils*/
void	ft_lstadd_back(t_list **alst, t_list *new);

/*err*/
void	print_err(char *str);

/*Print utils*/
void ft_print_list(t_list **map);


#endif
