/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 17:59:26 by gbourson          #+#    #+#             */
/*   Updated: 2016/08/17 14:22:56 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"
# include "../minilibx_macos/mlx.h"
# include <unistd.h>
# include <pwd.h>
# include <signal.h>

# define OPT "i"
# define ERROR_OPT() ft_putendl("Erreur option");
# define BUILD_FIND 0
# define BUILD_EXE 1
# define RED "\e[31m"
# define ORANGE "\033[38;2;255;189;0m"




#endif
