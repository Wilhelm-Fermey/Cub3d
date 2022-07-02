/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wilhelmfermey <marvin@42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 10:15:07 by wilhelmfermey     #+#    #+#             */
/*   Updated: 2022/07/02 12:08:30 by wilhelmfermey    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int ft_check2_NO(char *str, t_file *file)
{
	int	i;
	int	j;

	i = 2;
	j = 0;
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		while (str[i] && str[i] != ' ')
		{
			file->path_NO[j] = str[i];
			i++;
			j++;
		}
		while (str[i] == ' ')
			i++;
		if (str[i])
			return (1);
	}
	file->path_NO[j] = '\0';
	return (0);
}

int ft_check2_SO(char *str, t_file *file)
{
	int	i;
	int	j;

	i = 2;
	j = 0;
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		while (str[i] && str[i] != ' ')
		{
			file->path_SO[j] = str[i];
			i++;
			j++;
		}
		while (str[i] == ' ')
			i++;
		if (str[i])
			return (1);
	}
	file->path_SO[j] = '\0';
	return (0);
}

int ft_check2_EA(char *str, t_file *file)
{
	int	i;
	int	j;

	i = 2;
	j = 0;
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		while (str[i] && str[i] != ' ')
		{
			file->path_EA[j] = str[i];
			i++;
			j++;
		}
		while (str[i] == ' ')
			i++;
		if (str[i])
			return (1);
	}
	file->path_EA[j] = '\0';
	return (0);
}

int ft_check2_WE(char *str, t_file *file)
{
	int	i;
	int	j;

	i = 2;
	j = 0;
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		while (str[i] && str[i] != ' ')
		{
			file->path_WE[j] = str[i];
			i++;
			j++;
		}
		while (str[i] == ' ')
			i++;
		if (str[i])
			return (1);
	}
	file->path_WE[j] = '\0';
	return (0);
}
