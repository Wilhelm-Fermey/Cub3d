/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wilhelmfermey <marvin@42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 10:17:23 by wilhelmfermey     #+#    #+#             */
/*   Updated: 2022/07/02 12:23:42 by wilhelmfermey    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* ************ check nb of coma and if unapropriate caractere ************** */
int	ft_check_coma(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if ((str[i] >= 0 && str[i] < '0') || (str[i] > '9' && str[i] <= 127))
		{
			if (str[i] != ' ' && str[i] != ',')
				return (1);
		}
		if (str[i] == ',')
			count++;
		i++;
	}
	if (count == 2)
		return (0);
	return (1);
}

char **ft_malloc_color(char **color)
{
	int	i;

	i = 0;
	color = malloc(51 * sizeof(char *));
	if (color == NULL)
		return (printf("Error malloc \n"), NULL);
	while (i < 50)
	{
		color[i] = malloc(50 * sizeof(char));
		if (color[i] == NULL)
			return (printf("Error malloc \n"), NULL);
		i++;
	}
	color[i] = NULL;
	return (color);
}

char **ft_add_color_char(char *str, char **color)
{
	int	x;
	int	y;
	int	i;

	i = 0;
	x = 0;
	y = 0;
	while (str[i])
	{
		y = 0;
		while (str[i] == ' ')
			i++;
		while (str[i] >= '0' && str[i] <= '9')
		{
			color[x][y] = str[i];
			y++;
			i++;
		}
		while (str[i] == ' ')
			i++;
		while (str[i] == ',')
			i++;
		x++;
	}
	color[x] = NULL;
	return (color);
}

int	ft_check_nb_of_nb(char ** color)
{
	int	i;

	i = 0;
	while (color[i])
	{
		if (ft_atoi(color[i]) > 255)
			return (1);
		if (ft_atoi(color[i]) < 0)
			return (1);
		if ((color[i][0] >= 0 && color[i][0] < '0') 
			|| (color[i][0] > '9' && color[i][0] <= 127))
			return (1);
		i++;
	}
	if (i == 3)
		return (0);
	return (1);
}


int	ft_main_check_color(char *str, t_file *file, int which)
{
	char **color;

	color = NULL;
	if (ft_check_coma(str))
		return (printf("Error coma\n"), 1);
	color = ft_malloc_color(color);
	if (!color)
		return (1);
	color = ft_add_color_char(str, color);
	if (ft_check_nb_of_nb(color))
		return (printf("Error with color number\n"), 1);
	ft_char_to_int(color, file, which);
	return (ft_free_tab(color), 0);
}
