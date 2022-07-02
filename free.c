/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wilhelmfermey <marvin@42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 11:47:26 by wilhelmfermey     #+#    #+#             */
/*   Updated: 2022/07/02 12:21:47 by wilhelmfermey    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free (tab[i]);
		i++;
	}
	free (tab);
	return (0);
}

void ft_free_struct(t_file *file)
{
	free (file->path_NO);
	free (file->path_SO);
	free (file->path_EA);
	free (file->path_WE);
	ft_free_tab(file->cub);
	ft_free_tab(file->map);
	free(file->info);
}
