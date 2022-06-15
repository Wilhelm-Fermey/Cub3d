/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfermey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 13:41:42 by wfermey           #+#    #+#             */
/*   Updated: 2022/06/15 14:02:04 by wfermey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* ******************  main parsing function   ********************** */
int	ft_parsing(char *str, t_file *file)
{
	int		fd;
	char	*tmp;

	fd = open(str, O_RDONLY);
	tmp = get_next_line(fd);
	ft_map(str, file);
	while (tmp)
	{
		if (tmp[0] == 'F' || tmp[0] == 'C')
			ft_add_color(file, tmp);

		tmp = get_next_line(fd);
	}
	return (0);
}
