/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfermey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 12:22:30 by wfermey           #+#    #+#             */
/*   Updated: 2022/06/16 16:04:03 by wfermey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* ****************  check for space in middle of map  ******************** */
int	ft_middle(char *str)
{
	int	i;

	i = 0;
	printf("str[i] = %c\n", str[i]);
	if (str[i -1] != '1')	// si str[i -1] n'est pas 1, error.
		return 1;
	while (str[i] == ' ')	// on avance tant que str[i] est ' '
		i++;
	if (!str[i])			// si str[i] == '\0' on sort
		return (0);
	if (str[i] != '1')		// si str[i] != '1', error.
		return (1);
	while (str[i] != ' ' && str[i]) // on avance jusqu'a ' ' ou '\0'
		i++;
	if (str[i]  == ' ')
		ft_middle(&str[i]);
	else
	{
		if (str[-1] != '1')
			return (1);
	}
	return (0);
}

/* ******************  check if wall == 1  ********************** */
int	ft_check_wall(t_file *file)
{
	int	i;
	int	j;

	j = 0;
	while (file->map[j])	
	{
		i = 0;
		while (file->map[j][i] == ' ')				// si ' ' on avance jusqu'a quelque chose
			i++;
		if (file->map[j][i] != '1')					// check si quelque chose == 1
			return (1);
		while (file->map[j][i] != ' ' && file->map[j][i])	// on avance jusqu'a ' ' ou '\0'
			i++;
		if (file->map[j][i] == ' ')					// si ' '
		{
			if (ft_middle(&file->map[j][i]) == 0)		// on envois l'adress de la string a la fonction middle.
				j++;
			else
				return (1);
		}
		else										
		{											// sinon
			if (file->map[j][i -1] != '1')			// si str[i -1] pas egale a 1, alors error.
				return (1);
			j++;
		}
	}
	return (0);
}

/* ******************  main check function   ********************** */
int	ft_check_map(t_file *file)
{
	if (ft_check_wall(file))
		return (printf("Error parsing\n"), 1);
	return (0);	
}
