/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wilhelmfermey <marvin@42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:37:32 by wilhelmfermey     #+#    #+#             */
/*   Updated: 2022/06/20 17:39:14 by wilhelmfermey    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_player(t_file *file)
{
	int	i;
	int	j;
	int	count;

	j = -1;
	count = 0;
	while (file->map[++j])
	{
		i = 0;
		while (file->map[j][i])
		{
			if (file->map[j][i] == 'N' || file->map[j][i] == 'S'
				|| file->map[j][i] == 'E' || file->map[j][i] == 'W')
			{
				file->map[j][i] = '0';
				file->player_x = i;
				file->player_y = j;
				count++;
			}
			i++;
		}
	}
	if (count == 1)
		return (0);
	return (1);
}

int	ft_check_number(t_file *file)
{
	int	i;
	int	j;
	int	count;

	j = 0;
	count = 0;
	while (file->map[j -1])
	{
		i = 0;
		while (file->map[j][i])
		{
			if (file->map[j][i] != '0' && file->map[j][i] != '1')
			{
				printf("%c\n", file->map[j][i]);
				count++;
			}
			i++;
		}
		j++;
	}
	if (count)
		return (1);
	return (0);
}
