/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfermey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 14:57:29 by wfermey           #+#    #+#             */
/*   Updated: 2022/06/29 11:20:36 by wilhelmfermey    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


/* ************************************************************************** */
int	ft_size_map(t_file *file)
{
	int		i;
	int		j;
	int		count;

	j = 0;
	i = 0;
	count = 0;
	while (file->cub[j])
	{
		i = 0;
		while (file->cub[j][i] == 32 || file->cub[j][i] == '	')
			i++;
		if (file->cub[j][i] == '1' || file->cub[j][i] == '0')
			count++;
		j++;
	}
	return (count);
}

/* *********************** put just map in struct ************************** */
int	ft_put_map(t_file *file)
{
	int		i;
	int		j;
	int		x;

	file->map = malloc((ft_size_map(file) + 2) * sizeof(char *));
	if (file->map == NULL)
		return (printf("Error malloc\n"), 1);
	i = 0;
	j = 0;
	x = 0;
	while (file->cub[j])
	{
		i = 0;
		while (file->cub[j][i] == 32)
			i++;
		if (file->cub[j][i] == '1' || file->cub[j][i] == '0')
		{
			file->map[x] = ft_strdup(file->cub[j], file);
			x++;
		}
		j++;
	}
	file->map[x] = NULL;
	return (0);
}
