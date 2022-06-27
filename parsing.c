/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfermey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 13:41:42 by wfermey           #+#    #+#             */
/*   Updated: 2022/06/27 09:20:36 by wilhelmfermey    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* ******************  put file.cub in struct  ********************** */
int	ft_put_file(char *str, t_file *file)
{
	int	fd;
	char *res;
	char *tmp;

	res = NULL;
	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (printf("Error with file.cub\n"), 1); 
	tmp = get_next_line(fd);
	while (tmp)
	{
		res = ft_strjoin(res, tmp);
		tmp = get_next_line(fd);
	}
	file->cub = ft_split(res, '\n');
	if (ft_empty_line(res))
		return (printf("Error \n"), 1);
	return (0);
}

/* ******************  main parsing function   ********************** */
int	ft_parsing(int argc, char **argv, t_file *file)
{
	int		i;

	if (ft_check_basic(argc, argv))
		return (1);
	if (ft_put_file(argv[1], file))		// put .cub in struct
		return (1);
	if (ft_map_position(file))
		return (1);
	if (ft_put_map(file))					// put map in struct
		return (1);
	if (ft_check_map(file))					// check map
		return (1);
	if (ft_main_info(file))
		return (1);
	if (ft_main_color(file))
		return (1);
/*
	while (file->cub[i])
	{
		if (file->cub[i][0] == 'F' || file->cub[i][0] == 'C')
			ft_add_color(file, file->cub[i]);
		i++;
	}
*/
	return (0);
}
