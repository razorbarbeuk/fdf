/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 17:59:26 by gbourson          #+#    #+#             */
/*   Updated: 2016/10/04 17:59:38 by RAZOR            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"
# include <../minilibx_macos/mlx.h>
# include <sys/types.h>
# include <dirent.h>
# include <stdlib.h>
# include <signal.h>
# include <math.h>


# define OPT "i"
# define HEXA "0123456789abcdef"
# define ERROR_OPT() ft_putendl("Erreur option");
# define RED "\e[31m"
# define ORANGE "\033[38;2;255;189;0m"
# define WIN_W 800
# define WIN_H 600

typedef enum	e_enum
{
	DEFAULT_COLOR_1 = 0xFF0000,
	DEFAULT_COLOR_2 = 0xFFFFFF,
	LEFT_KEY = 4479771,
	RIGHT_KEY = 4414235,
	UP_KEY = 4283163,
	DOWN_KEY = 4348699,
	ESC_KEY = 27,
	SPACE_KEY = 32,
	DEL_KEY = 127,
}				t_enum;

typedef struct		s_img
{
	void			*adress;
	char			*img;
	int				bpp;
	int				size_line;
	int				endian;
}					t_img;

typedef struct		s_point
{
	int				x;
	int				y;
	int				z;
}					t_point;

typedef struct		s_color
{
	unsigned char	r;
	unsigned char	v;
	unsigned char	b;
}					t_color;

typedef struct		s_env
{
	void			*mlx_ptr;
	void			*mlx_win;
	int				size_x;
	int				size_y;
	float			x1;
	float			x2;
	float			y1;
	float			y2;
	float			scale;
	int				top;
	int				left;
	int				nb_case;
	int				count_line;
	float			case_width;
	float			case_height;
	t_list			*color;
	t_img			img;
	t_list			*list_line;
	t_list			*map;
}					t_env;

/*Init*/
void	ft_init_data(t_env *data);
t_env	*ft_static_select(t_env *data, int i);
int 	ft_open_dir_palette(t_env *data);
int		ft_mlx_init(t_env *data);
int		ft_img_init(t_env *data);
void	ft_init_color(t_color **color);

/*Parsing line*/
int		ft_open_file(char *av, t_env *data);
void	ft_cal_case(t_env *data);
int		ft_parse_color(char **av, t_env *data);

/*Color*/
void	init_color_value(t_env *data, int step, int *tab);

int		get_color_value(t_env *data, int tab, int steps, char c);

/*List_utils*/
void	ft_lstadd_back(t_list **alst, t_list *new);
void	ft_lstiter_coord(t_list *lst, float *num, int opt, void (*f)(t_list *elem, float *num, int opt));
void	ft_elem_num(t_list *elem, float *num, int opt);

/*err*/
void	ft_print_err(char *str);

/*draw*/
void	ft_draw(t_env *data);
void	ft_draw_line(t_env *data, float *screen_xy, float *screen_xy_next, int color_count);
void	ft_draw_face(t_env *data, int *screen_xy, int *screen_xy_next);

/*free*/
void	del_elem_map(void *content, size_t size);
void	del_elem(void *content, size_t size);

/*utils*/
int		ft_convert_Hex(char *s);
void	ft_init_tab_int(int *tab, size_t c);

/*Print utils*/
void ft_print_list(t_list **map);

/*get_center_map*/
int ft_center_map(t_list *map, int *top, int *left);

#endif
