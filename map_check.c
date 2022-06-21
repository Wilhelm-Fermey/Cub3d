/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfermey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 12:22:30 by wfermey           #+#    #+#             */
/*   Updated: 2022/06/20 17:39:23 by wilhelmfermey    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* **************** check max len line  ******************** */
int	ft_max_len(t_file *file)
{
	int	i;
	int	j;
	int res;

	i = 0;
	j = 0;
	while (file->map[j])
	{
		while (file->map[j][i])
			i++;
		if (i > res)
			res = i;
		j++;
	}
	return (res);
}

/* ****************  check wall by line  ******************** */
int	ft_middle(char *str, int *i)
{
	if (str[*i -1] != '1')	// si str[i -1] n'est pas 1, error.
		return (1);
	while (str[*i] && str[*i] == ' ')	// on avance tant que str[i] est ' '
		*i = *i + 1;
	if (!str[*i])			// si str[i] == '\0' on sort
		return (0);
	if (str[*i] != '1')		// si str[i] != '1', error.
		return (1);
	while (str[*i] && str[*i] != ' ') // on avance jusqu'a ' ' ou '\0'
		*i = *i + 1;
	if (str[*i]  == ' ')
		return (2);
	else
	{
		if (str[*i -1] != '1')
			return (1);
	}
	return (0);
}

int	ft_loop(t_file *file,int *j, int *i)
{
	int	x;

	x = ft_middle(file->map[*j], i);
	while (x == 2)
		x = ft_middle(file->map[*j], i);
	if (x == 1)
		return (1);
	return (0);
}

/* ******************  check wall by line  ********************** */
int	ft_check_wall(t_file *file)
{
	int	i;
	int	j;

	j = -1;
	while (file->map[++j])	
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
			if (ft_loop(file, &j, &i) == 1)
				return (1);
		}
		else
		{											// sinon
			if (file->map[j][i -1] != '1')			// si str[i -1] pas egale a 1, alors error.
				return (1);
		}
	}
	return (0);
}

/* ******************  main map check function ********************** */
int	ft_check_map(t_file *file)
{
	int 	i;

	if (ft_check_wall(file))
		return (printf("Error parsing\n"), 1);
	i = ft_max_len(file);
	if (ft_check_map2(file, i))
		return (printf("Error parsing\n"), 1);
	if (ft_check_player(file))
		return (printf("Error parsing\n"), 1);
	if (ft_check_number(file))	
		return (printf("Error parsing\n"), 1);

	i = 0;
	while (file->map[i])
	{
		printf("%s\n",file->map[i]);
		i++;
	}
		
	return (0);	
}
