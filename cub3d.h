/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfermey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 09:50:48 by wfermey           #+#    #+#             */
/*   Updated: 2022/06/15 13:43:36 by wfermey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_file {
	int		F_color;
	int		C_color;
	char	**map;
}				t_file;


/* ********************************** MAIN ********************************** */

/* ******************************** COLOR ********************************* */
void	ft_add_color(t_file *file, char *tmp);

/* ******************************** PARSING ********************************* */
int	ft_parsing(char *str, t_file *file);

/* ******************************** Get_N_L ********************************* */
char    *get_next_line(int fd);
char    *ft_read(int fd, char *buff, char *str, int res);

/* ******************************** UTILS1 ********************************** */
int		ft_strlen(char *str);
int		ft_strchr(char *str, char c);
char    *ft_strjoin(char *str, char *buff);
int     ft_atoi(char *str);

/* ********************************* SPLIT ********************************** */
char    **ft_split(char *s, char c);


#endif
