
/*                                                        :::      ::::::::   */
/*   map_check2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfermey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 14:22:21 by wfermey           #+#    #+#             */
/*   Updated: 2022/06/17 16:05:12 by wfermey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* ************************* check wall by column ************************** */
int	ft_middle2(t_file *file, int *i, int *j)
{
	if (file->map[*i -1][*j] != '1')
		return (1);
	while (file->map[*i][*j] == ' ')	// on avance tant que str[i][j] est ' '
		*i = *i + 1;
	if (!file->map[*i][*j])			// si str[i] == '\0' on sort
		return (0);
	if (file->map[*i][*j] != '1')		// si str[i] != '1', error.
		return (1);
	while (file->map[*i][*j] && file->map[*i][*j] != ' ')	// on avance jusqu'a ' ' ou '\0'
		*i = *i + 1;
	if (file->map[*i][*j]  == ' ')
		return (2);
	else
	{
		if (file->map[*i -1][*j] != '1')
			return (1);
	}
	return (0);
}

int	ft_loop2(t_file *file, int *i, int *j)
{
	int	x;

	x = ft_middle2(file, i, j);
	while (x == 2)
		x = ft_middle2(file, i, j);
	if (x == 1)
		return (1);
	return (0);
}

/* ************************* check wall by column ************************** */
int	ft_check_wall2(t_file *file, int len)
{
	int	i;
	int	j;

	j = -1;
	while (++j < len)
	{
		i = 0;
		while (file->map[i][j] == ' ')		// si ' ' on avance jusqu'a quelque chose
			i++;
		if (file->map[i][j] != '1')					// check si quelque chose == 1
			return (1);
		while (file->map[i][j] && file->map[i][j] != ' ' )	// on avance jusqu'a ' ' ou 'NULL'
			i++;
		if (file->map[i][j] == ' ')					// si ' '
		{
			if (ft_loop2(file, &i, &j) == 1)
				return (1);
		}
		else
		{											// sinon
			if (file->map[i -1][j] != '1')			// si str[i -1] pas egale a 1, alors error.
				return (1);
		}
	}
	return (0);
}
	
/* ************************* check mur par colone ************************** */
int	ft_check_map2(t_file *file, int len)
{
	int	i;
	int	x;
	int	y;

	x = 0;
	y = -1;
	while (file->map[x])
		x++;
	file->map[x] = malloc(1000 * sizeof(char));
	while (++y < 1000)
		file->map[x][y] = '\0';
	file->map[++x] = NULL;
	i = ft_check_wall2(file, len);
	file->map[--x] = NULL;
	return (i);
}
