/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_basics.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wilhelmfermey <marvin@42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 15:47:23 by wilhelmfermey     #+#    #+#             */
/*   Updated: 2022/06/23 10:30:51 by wilhelmfermey    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_empty_line(char *str)
{
	int	i;
	int	j;
	int	count;

	count = 0;
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
