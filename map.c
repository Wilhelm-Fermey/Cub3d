/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfermey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 13:58:54 by wfermey           #+#    #+#             */
/*   Updated: 2022/06/15 14:33:04 by wfermey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* ******************  malloc size of char**   ********************** */
char **	ft_size_map(char *str)
{
	int		fd;
	int		i;
	int		j;
	char 	*tmp;

	fd = open(str, O_RDONLY);
	tmp = get_next_line(fd);
	while (tmp)
	{
		i = 0;
		while (tmp[i] == ' ')
			i++;
		if (str[i] == '1')
			j++;
	}
	printf("%d\n", j);
	map = malloc(j + 1 * sizeof(char *));
	return (mqp);
}

/* ******************  put map in char**   ********************** */
int	ft_put_map(char *str, t_file file)
{
	int		fd;
	int		i;
	char 	*tmp;
	char	**map;

	map = ft_size_map(str);
	fd = open(str, O_RDONLY);
	tmp = get_next_line(fd);
	map = malloc(50 * sizeof(char *));
	while (tmp)
	{
		i = 0;
		while (tmp[i] == ' ')
			i++;
		if (str[i] == '1')
		{
			map[j] = ft_strdup(tmp);
			j++;
		}
	}
	map[j] = NULL;
}



/* ******************  main map function   ********************** */
int	ft_map(char *str, t_file *file)
{
	char	**map;

	map = ft_put_map(str, file);
}
