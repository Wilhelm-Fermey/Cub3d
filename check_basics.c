/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_basics.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wilhelmfermey <marvin@42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 15:47:23 by wilhelmfermey     #+#    #+#             */
/*   Updated: 2022/06/22 16:57:57 by wilhelmfermey    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_empty_line(t_file *file)
{
	
}

int	ft_check_basic(int argc, char **argv)
{
	if (argc != 2)
		return (printf("Error: Incorrect number of arguments\n"), 1);
	if (opendir(argv[1]))
		return (printf("Error: Put file, not directory\n"), 1);
	return (0);
}
