/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfermey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 14:27:09 by wfermey           #+#    #+#             */
/*   Updated: 2022/06/16 10:18:50 by wfermey          ###   ########.fr       */
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
}

/* *****************  add color rgb to char**  ********************* */
char	**ft_add_color_char(char * tmp)
{
	int		i;
	int		j;
	int		k;
	char    **color_rgb;

	i = -1;	
	color_rgb = malloc(3 * sizeof (char *));
	while (++i < 3)
		color_rgb[i] = malloc(50 * sizeof (char));
	i = ft_strlen(tmp);
	tmp[i-1] = '\0';
	i = 2;
	k = -1;
	while (++k < 3)
	{	
		j = -1;
		while (tmp[i] >= '0' && tmp[i] <= '9')
		{
			color_rgb[k][++j] = tmp[i];
			i++;
		}
		i++;
	}
	return (color_rgb);
}

/* *******************  main color function  *********************** */
void	ft_add_color(t_file *file, char *tmp)
{
	char	**color_rgb;
	int		*color_rgb2;
	char 	which;

	if (tmp[0] == 'F')
		which = 'F';
	if (tmp[0] == 'C')
		which = 'C';
	color_rgb = ft_add_color_char(tmp);
	ft_char_to_int(color_rgb, file, which);

}
