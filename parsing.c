/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfermey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 13:41:42 by wfermey           #+#    #+#             */
/*   Updated: 2022/06/16 10:39:52 by wfermey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* ******************  put file.cub in char**  ********************** */
char **	ft_put_file(char *str)
{
	int	fd;
	char *res;
	char *tmp;
	char **file;

	res = NULL;
	file = NULL;
	fd = open(str, O_RDONLY);
	tmp = get_next_line(fd);
	while (tmp)
	{
		res = ft_strjoin(res, tmp);
		tmp = get_next_line(fd);
	}
	file = ft_split(res, '\n');
	return (file);
}


/* ******************  main parsing function   ********************** */
int	ft_parsing(char *str, t_file *file)
{
	int		i;
	char	**file_cub;

	i = 0;
	file_cub = ft_put_file(str);
	ft_map(file_cub, file);
	while (file_cub[i])
	{
		if (file_cub[i][0] == 'F' || file_cub[i][0] == 'C')
			ft_add_color(file, file_cub[i]);
		i++;
	}
	return (0);
}
