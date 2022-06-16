/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfermey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 13:41:42 by wfermey           #+#    #+#             */
/*   Updated: 2022/06/16 15:31:01 by wfermey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* ******************  put file.cub in struct  ********************** */
void	ft_put_file(char *str, t_file *file)
{
	int	fd;
	char *res;
	char *tmp;

	res = NULL;
	fd = open(str, O_RDONLY);
	tmp = get_next_line(fd);
	while (tmp)
	{
		res = ft_strjoin(res, tmp);
		tmp = get_next_line(fd);
	}
	file->cub = ft_split(res, '\n');
}

/* ******************  main parsing function   ********************** */
int	ft_parsing(char *str, t_file *file)
{
	int		i;

	i = 0;
	ft_put_file(str, file);					// put .cub in struct
	if (ft_put_map(file))					// put map in struct
		return (1);

	while (file->map[i])
	{
		printf("%s\n", file->map[i]);
		i++;
	}

	if (ft_check_map(file))					// check map
		return (1);
	i = 0;
	while (file->cub[i])
	{
		if (file->cub[i][0] == 'F' || file->cub[i][0] == 'C')
			ft_add_color(file, file->cub[i]);
		i++;
	}
	return (0);
}
