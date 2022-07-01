/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check2_bis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wilhelmfermey <marvin@42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 10:53:45 by wilhelmfermey     #+#    #+#             */
/*   Updated: 2022/07/01 13:05:55 by wilhelmfermey    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_empty_space_end(t_file *file, int len)
{
	int	i;
	int	j;
	int	 count;
	int		res;

	j = -1;
	count = 0;
	res = 0;
	while (j++ < len)
	{
		i = 0;
		while (file->map[i][j] == ' ')
			i++;
		if (file->map[i][j] != ' ' && file->map[i][j] != '\0')
			count++;
		else if (file->map[i][j] == '\0' && count)
			return (j);
	}
	return (res);
}
