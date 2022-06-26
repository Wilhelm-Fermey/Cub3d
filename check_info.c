/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wilhelmfermey <marvin@42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 11:37:21 by wilhelmfermey     #+#    #+#             */
/*   Updated: 2022/06/26 12:36:21 by wilhelmfermey    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_F(t_file *file)
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
		if ((file->info[j][i] == 'F') && (file->info[j][i+1] == ' '))
			count++;
		j++;
	}
	if (count == 1)
		return (0);
	return (1);
}

int	ft_check_C(t_file *file)
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
		if ((file->info[j][i] == 'C') && (file->info[j][i+1] == ' '))
			count++;
		j++;
	}
	if (count == 1)
		return (0);
	return (1);
}

int	ft_check_NO(t_file *file)
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
		if ((file->info[j][i] == 'N') && (file->info[j][i +1] == 'O')
			&& (file->info[j][i +2] == ' '))
			count++;
		j++;
	}
	if (count == 1)
		return (0);
	return (1);
}

int	ft_check_SO(t_file *file)
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
		if ((file->info[j][i] == 'S') && (file->info[j][i +1] == 'O')
			&& (file->info[j][i +2] == ' '))
			count++;
		j++;
	}
	if (count == 1)
		return (0);
	return (1);
}

int	ft_check_EA(t_file *file)
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
		if ((file->info[j][i] == 'E') && (file->info[j][i +1] == 'A')
			&& (file->info[j][i +2] == ' '))
			count++;
		j++;
	}
	if (count == 1)
		return (0);
	return (1);
}
