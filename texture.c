/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wilhelmfermey <marvin@42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 17:00:16 by wilhelmfermey     #+#    #+#             */
/*   Updated: 2022/06/29 10:08:36 by wilhelmfermey    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char *ft_malloc()
{
	char *str;

	str = malloc(500 * sizeof(char));
	if (!str)
		return (NULL);
	return (str);
}

int	ft_malloc_texture(t_file *file)
{
	file->path_NO = ft_malloc();
	if (!file->path_NO)
		return (1);
	file->path_SO = ft_malloc();
	if (!file->path_SO)
		return (1);
	file->path_EA = ft_malloc();
	if (!file->path_EA)
		return (1);
	file->path_WE = ft_malloc();
	if (!file->path_WE)
		return (1);
	return (0);
}

int ft_which_path(char c, char *str, t_file *file)
{
	if (c == 'N')
	{
		if (ft_check2_NO(str, file))
			return (1);
	}
	if (c == 'S')
	{
		if (ft_check2_SO(str, file))
			return (1);
	}
	if (c == 'E')
	{
		if (ft_check2_EA(str, file))
			return (1);
	}
	if (c == 'W')
	{
		if (ft_check2_WE(str, file))
			return (1);
	}
	return (0);
}

char **ft_malloc_str(t_file *file)
{
	char **str;
	int	i;
	int	len;

	len = 0;
	while (file->info[len])
		len++;
	str = malloc (len + 1 * sizeof(int));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = malloc(500 * sizeof(int));
		if (!str[i])
			return (NULL);
		i++;
	}
	str[i] = NULL;
	i = -1;
	while (str[++i])
		str[i] = file->info[i];
	return (str);
}

int	ft_main_texture(t_file *file)
{
	int	i;
	int	j;
	char **str;

	j = 0;
	str = ft_malloc_str(file);
	if (ft_malloc_texture(file))
		return (1);
	j = 0;
	while (str[j])
	{
		i = 0;
		while (str[j][i] == ' ')
			i++;
		if (str[j][i] == 'N' || str[j][i] == 'S'
			|| str[j][i] == 'E' || str[j][i] == 'W')
		{
			if (ft_which_path(str[j][i], str[j], file))
				return (printf("Error\n"), 1);
		}
		j++;
	}
	return (0);
}
