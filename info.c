/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wilhelmfermey <marvin@42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 09:32:18 by wilhelmfermey     #+#    #+#             */
/*   Updated: 2022/06/24 16:20:35 by wilhelmfermey    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_size_info(t_file *file)
{
	int	i;
	int	j;
	int	count;

	j = 0;
	count = 0;
	while (file->cub[j])
	{
		i = 0;
		while (file->cub[j][i] == 32)
			i++;
		if (file->cub[j][i] == '0' || file->cub[j][i] == '1')
			return (count);
		count++;
		j++;
	}
	return (count);
}

int	ft_main_info(t_file *file)
{
	int	i;
	int	j;

	ft_size_info(file);
//	file->map = malloc((ft_size_info(file) + 2) * sizeof(char *));

	return (0);
}
