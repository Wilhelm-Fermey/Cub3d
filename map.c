/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfermey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 13:58:54 by wfermey           #+#    #+#             */
/*   Updated: 2022/06/15 16:58:41 by wfermey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* ******************  creat empty map   ********************** */
char **	ft_size_map(char *str)
{
	int		fd;
	int		i;
	int		j;
	char 	*tmp;
	char	**map;

	j = 0;
	i = 0;
	fd = open(str, O_RDONLY);
	tmp = get_next_line(fd);
	printf("tmp[i] ==  %c\n", tmp[i]);
	while (tmp)
	{
		i = 0;
		while (tmp[i] == 32)
			i++;
		if (tmp[i] == '1')
			j++;
		tmp = get_next_line(fd);
	}
	printf("%d\n", j);
	map = malloc(j + 1 * sizeof(char *));
	return (map);
}

/* ******************  put map in char**   ********************** */
char	**ft_put_map(char *str, t_file *file)
{
	int		fd;
	int		i;
	int		j;
	char 	*tmp;
	char	**map;

	j = 0;
	map = ft_size_map(str);
	/*
	fd = open(str, O_RDONLY);
	tmp = get_next_line(fd);
	while (tmp)
	{
		i = 0;
		while (tmp[i] == ' ')
			i++;
		i++;
		if (tmp[i] == '1')
		{
			map[j] = ft_strdup(tmp);
			j++;
		}
		tmp = get_next_line(fd);
	}
	*/
	map[j] = NULL;
	return (map);
}



/* ******************  main map function   ********************** */
int	ft_map(char *str, t_file *file)
{
	char	**map;

	map = ft_put_map(str, file);
	return (0);
}
