/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfermey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 16:41:18 by wfermey           #+#    #+#             */
/*   Updated: 2022/06/24 16:13:47 by wilhelmfermey    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_len_map(t_file *file)
{
	int	i;
	int	j;
	int res;
	int	count;

	j = 0;
	res = 0;
	count = 0;
	while (file->cub[j])
	{
		i = 0;
		while (file->cub[j][i] == 32)
			i++;
		if (file->cub[j][i] == '1' || file->cub[j][i] == '0')
			count++;
		i = 0;
		while (file->cub[j][i])
		{
			if (i > res && count)
				res = i;
			i++;
		}
		j++;
	}
	return (res);
}
/*
int	ft_len_map(t_file *file)
{
	int	i;
	int	j;
	int res;

	j = 0;
	res = 0;
	while (file->cub[j])
	{

		i = 0;
		while (file->cub[j][i])
		{
			if (i > res)
				res = i;
			i++;
		}
		j++;
	}
	return (res +1);
}
*/

char	*ft_strdup(char *src, t_file *file)
{
	int		i;
	int		len;
	char	*str;
	int		end;

	len = 0;
	end = ft_len_map(file);
	while (src[len])
		len++;
	str = (char*)malloc(sizeof(*str) * (end + 1));
	i = 0;
	while (i < len)
	{
		str[i] = src[i];
		i++;
	}
	while (i <= end)
	{
		str[i] = ' ';
		i++;
	}
	str[i] = '\0';
	return (str);
}
