/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wilhelmfermey <marvin@42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 11:47:26 by wilhelmfermey     #+#    #+#             */
/*   Updated: 2022/07/05 11:20:47 by wilhelmfermey    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	if (tab[i])
	{
		while (tab[i])
		{
			free (tab[i]);
			i++;
		}
		free (tab);
	}
	return (0);
}

void ft_free(t_file *file, int i)
{
	if (i >= 1)
		ft_free_tab(file->cub);
	if (i >= 2)
		ft_free_tab(file->map);
	if (i >= 3)
		free(file->info);
	if (i >= 4)
	{
		free (file->path_NO);
		free (file->path_SO);
		free (file->path_EA);
		free (file->path_WE);
	}
}
