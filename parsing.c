/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfermey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 14:27:09 by wfermey           #+#    #+#             */
/*   Updated: 2022/06/11 16:15:31 by wfermey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_convert(t_file *file, char *tmp)
{
	int		i;
	char	**color_rgb;

	i = ft_strlen(tmp);
	tmp[i-1] = '\0';
	i = 2;
	color_rgb = ft_split(&tmp[i], ',');
}

void	ft_parsing(char *str, t_file *file)
{
	int		fd;
	char	*tmp;

	fd = open(str, O_RDONLY);
	tmp = get_next_line(fd);
	while (tmp)
	{
		if (tmp[0] == 'F')
			ft_convert(file, tmp);
		if (tmp[0] == 'C')
			ft_convert(file, tmp);
		tmp = get_next_line(fd);
	}
	

}
