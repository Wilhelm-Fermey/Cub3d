/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfermey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 13:58:54 by wfermey           #+#    #+#             */
/*   Updated: 2022/06/16 11:37:00 by wfermey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


/* ******************  malloc map in struct  ********************** */
void	ft_size_map(char **file_cub, t_file *file)
{
	int		i;
	int		j;
	int		count;

	j = 0;
	i = 0;
	count = 0;
	while (file_cub[j])
	{
		i = 0;
		while (file_cub[j][i] == 32 || file_cub[j][i] == '	')
			i++;
		if (file_cub[j][i] == '1')
		{
			count++;
//			printf("%s\n", file_cub[j]);
		}
		j++;
	}
	printf("%d\n",  count);
	file->map = malloc(count + 1 * sizeof(char *));
}

/* ******************  put map in struct   ********************** */
void	ft_put_map(char **file_cub, t_file *file)
{
	int		i;
	int		j;
	int		x;

	ft_size_map(file_cub, file);
	i = 0;
	j = 0;
	x = 0;
	while (file_cub[j])
	{
		i = 0;
		while (file_cub[j][i] == 32 /*|| file_cub[j][i] == '	'*/)
			i++;
		if (file_cub[j][i] == '1')
		{
			file->map[x] = ft_strdup2(file_cub[j]);
	//		printf("%s\n", file_cub[j]);
			x++;
		}
		j++;
	}
	file->map[x] = NULL;
}


/* ******************  main map function   ********************** */
int	ft_map(char **file_cub, t_file *file)
{
	ft_put_map(file_cub, file);

	int	i = 0;
	while (file->map[i])
	{
		printf("%s\n", file->map[i]);
		i++;
	}
	return (0);
}
