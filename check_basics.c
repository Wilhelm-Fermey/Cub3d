/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_basics.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wilhelmfermey <marvin@42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 15:47:23 by wilhelmfermey     #+#    #+#             */
/*   Updated: 2022/07/02 11:18:02 by wilhelmfermey    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_no_map(t_file *file)
{
	int i;
	int	j;
	int	count;

	j = 0;
	count = 0;
	while (file->cub[j])
	{
		i = 0;
		while (file->cub[j][i])
		{
			while (file->cub[j][i] == ' ')
				i++;
			if (file->cub[j][i] == '1' || file->cub[j][i] == '0')
				count++;
			i++;
		}
		j++;
	}
	if (!count)
		return (1);
	return (0);
}

int	ft_map_position(t_file *file)
{
	if (ft_no_map(file))
		return (printf("Error : Any map found in the file\n"), 1);
	return (0);
}

int	ft_empty_line(char *str)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n' && count)
			return (1);
		while (str[i] == 32)
			i++;
		if (str[i] == '1' || str[i] == '0')
			count++;
		while (str[i] != '\n')
			i++;
		i++;
	}

	return (0);
}

int	ft_check_basic(int argc, char **argv)
{
	if (argc != 2)
		return (printf("Error: Incorrect number of arguments\n"), 1);
	if (opendir(argv[1]))
		return (printf("Error: Put file, not directory\n"), 1);
	
	return (0);
}
