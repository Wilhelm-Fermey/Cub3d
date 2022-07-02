/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wilhelmfermey <marvin@42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 09:32:18 by wilhelmfermey     #+#    #+#             */
/*   Updated: 2022/07/02 12:26:55 by wilhelmfermey    ###   ########.fr       */
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

int	ft_put_info(t_file *file)
{
	int	i;
	int	j;
	int	x;

	file->info = malloc((ft_size_info(file) + 1) * sizeof(char *));
	if (file->info == NULL)
		return (printf("Error malloc\n"), 1);
	i = 0;
	j = 0;
	x = 0;
	while (file->cub[j])
	{
		i = 0;
		while (file->cub[j][i] == 32)
			i++;
		if (file->cub[j][i] == '0' || file->cub[j][i] == '1')
			break ;
		file->info[x] = ft_strdup2(file->cub[j]);
		x++;
		j++;
	}
	file->info[x] = NULL;
	return (0);
}

int	ft_check_WE(t_file *file)
{
	int	i;
	int	j;
	int	count;

	j = 0;
	count = 0;
	while (file->info[j])
	{
		i = 0;
		while (file->info[j][i] == ' ')
			i++;
		if ((file->info[j][i] == 'W') && (file->info[j][i +1] == 'E')
			&& (file->info[j][i +2] == ' '))
			count++;
		j++;
	}
	if (count == 1)
		return (0);
	return (1);
}

int	check_id_info(t_file *file)
{
	if (ft_check_F(file))
		return (printf("Error with id F\n"), 1);
	if (ft_check_C(file))
		return (printf("Error with id C\n"), 1);
	if (ft_check_NO(file))
		return (printf("Error with id NO\n"), 1);
	if (ft_check_SO(file))
		return (printf("Error with id SO\n"), 1);
	if (ft_check_EA(file))
		return (printf("Error with id EA\n"), 1);
	if (ft_check_WE(file))
		return (printf("Error with id WE\n"), 1);

	return (0);
}

int	ft_main_info(t_file *file)
{
	ft_put_info(file);
	if (check_id_info(file))
		return (1);

	return (0);
}
