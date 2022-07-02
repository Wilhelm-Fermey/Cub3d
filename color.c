/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfermey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 14:27:09 by wfermey           #+#    #+#             */
/*   Updated: 2022/07/02 11:44:41 by wilhelmfermey    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* *****************  convert rgb to decimal   ********************* */
int	ft_convert(int R, int G, int B)
{	int res;

	res = R * 65536 + G * 256 + B;
	return (res);
}

 /* *****************  convert from char** to int**   ********************* */
void	ft_char_to_int(char **color_rgb, t_file *file, char which)
{
	int     *c_rgb2;

	c_rgb2 = malloc(3 * sizeof(int));
	c_rgb2[0] = ft_atoi(color_rgb[0]);
	c_rgb2[1] = ft_atoi(color_rgb[1]);
	c_rgb2[2] = ft_atoi(color_rgb[2]);
	if (which == 'C')
		file->C_color = ft_convert(c_rgb2[0], c_rgb2[1], c_rgb2[2]);
	if (which == 'F')
		file->F_color = ft_convert(c_rgb2[0], c_rgb2[1], c_rgb2[2]);
	free (c_rgb2);
}


/* *******************  main color function  *********************** */
int	ft_main_color(t_file *file)
{
	int		j;
	int 	i;
	char	which;

	j = 0;
	while (file->info[j])
	{
		i = 0;
		while (file->info[j][i] == ' ')
			i++;
		if (file->info[j][i] == 'C' || file->info[j][i] == 'F')
		{
			if (file->info[j][i] == 'C')
				which = 'C';
			if (file->info[j][i] == 'F')
				which = 'F';
			if (ft_main_check_color(&file->info[j][i +1], file, which))
				return (1);
		}
		j++;
	}
	return (0);
}

