/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palette.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: RAZOR <RAZOR@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 15:57:06 by RAZOR             #+#    #+#             */
/*   Updated: 2016/10/04 18:14:44 by RAZOR            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int ft_open_dir_palette(t_env *data)
{
	DIR 			*dir;
	struct dirent	*dir_struct;
	int				fd;
	char			*line;

	(void)data;
	fd = 0;
	line = NULL;
	if ((dir = opendir("./pal")) == NULL)
		return (0);
	while ((dir_struct = readdir(dir)))
	{
		if (dir_struct->d_name[0] != '.')
		{
			if ((fd = open(dir_struct->d_name, O_RDONLY)) == -1)
				return (0);
			while (get_next_line(fd, &line))
			{
				ft_putendl(line);
				ft_strdel(&line);
			}
		}

	}
	ft_strdel(&line);
	close(fd);
	return (1);
}
