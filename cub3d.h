
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfermey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 09:50:48 by wfermey           #+#    #+#             */
/*   Updated: 2022/06/22 10:55:14 by wilhelmfermey    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "minilibx/mlx.h"
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <dirent.h>

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
	int		player_x;
	int		player_y;
	char	**cub;
	char	**map;
	char	**info;
}				t_file;

/* ******************************** COLOR ********************************* */
void	ft_add_color(t_file *file, char *tmp);

/* ******************************** PARSING ********************************* */
int		ft_parsing(int argc, char **argv, t_file *file);

/* ******************************** Get_N_L ********************************* */
char    *get_next_line(int fd);
char    *ft_read(int fd, char *buff, char *str, int res);

/* ******************************** UTILS1 ********************************** */
int		ft_strlen(char *str);
int		ft_strchr(char *str, char c);
char    *ft_strjoin(char *str, char *buff);
int     ft_atoi(char *str);

/* ******************************** UTILS2 ********************************** */
char    *ft_strdup(char *src, t_file *file);

/* ********************************* SPLIT ********************************** */
char    **ft_split(char *s, char c);

/* ********************************* MAP ********************************** */
int		ft_put_map(t_file *file);

/* ******************************* CHECK_MAP ******************************** */
int		ft_check_map(t_file *file);

/* ******************************* CHECK_MAP2 ******************************** */
int ft_check_map2(t_file *file, int len);
int ft_check_wall2(t_file *file, int len);

/* ***************************** CHECK_MAP3 ***************************** */
int ft_check_player(t_file *file);
int ft_check_number(t_file *file);
int ft_put_wall(t_file *file);

/* ***************************** CHECK_BASICS ***************************** */
int ft_map_position(t_file *file);
int ft_empty_line(char *res);
int ft_check_basic(int argc, char **argv);

/* ***************************** INFO ***************************** */
int ft_main_info(t_file *file);




#endif
