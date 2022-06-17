/* ************************************************************************** */
/*                                                                            */
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

int	ft_middle2(char *str, int *i)
{
	if (str[*i -1] != '1')	// si str[i -1] n'est pas 1, error.
		return (1);
	while (str[*i] && str[*i] == ' ')	// on avance tant que str[i] est ' '
		*i = *i + 1;
	if (!str[*i])			// si str[i] == '\0' on sort
		return (0);
	if (str[*i] != '1')		// si str[i] != '1', error.
		return (1);
	while (str[*i] && str[*i] != ' ') // on avance jusqu'a ' ' ou '\0'
		*i = *i + 1;
	if (str[*i]  == ' ')
		return (2);
	else
	{
		if (str[*i -1] != '1')
			return (1);
	}
	return (0);
}

int	ft_loop2(t_file *file,int *i, int *j)
{
	int	x;

	x = ft_middle2(file->map[*i], i);
	while (x == 2)
		x = ft_middle2(file->map[*i], i);
	if (x == 1)
		return (1);
	return (0);
}

int	ft_check_wall2(t_file *file)
{
	int	i;
	int	j;

	i = -1;
	while (file->map[++i])
	{
		j = 0;
		while (file->map[i][j] == ' ')				// si ' ' on avance jusqu'a quelque chose
			i++;
		if (file->map[i][j] != '1')					// check si quelque chose == 1
			return (1);
		while (file->map[i] != NULL && file->map[i][j] != ' ')	// on avance jusqu'a ' ' ou 'NULL'
			i++;
		printf("%c\n", file->map[i][j]);
		if (file->map[i] == NULL)
		{											// sinon
			if (file->map[i -1][j] != '1')			// si str[i -1] pas egale a 1, alors error.
				return (1);
		}
		else if (file->map[i][j] == ' ')					// si ' '
		{
			if (ft_loop2(file, &i, &j) == 1)
				return (1);
		}
	}
	return (0);
}


