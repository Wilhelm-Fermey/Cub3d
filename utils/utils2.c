/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfermey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 16:41:18 by wfermey           #+#    #+#             */
/*   Updated: 2022/06/29 11:25:51 by wilhelmfermey    ###   ########.fr       */
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
			i++;
			if (i > res && count)
				res = i;
		}
		j++;
	}
	return (res);
}

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
	str = malloc(sizeof(char) * (end + 1));
	i = 0;
	while (i < len)
	{
		str[i] = src[i];
		i++;
	}
	while (i < end)
	{
		str[i] = ' ';
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strdup2(char *src)
{
	char	*new;
	int		i;
	int		size;

	size = 0;
	while (src[size])
		++size;
	if (!(new = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	i = 0;
	while (src[i])
	{
		new[i] = src[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}


