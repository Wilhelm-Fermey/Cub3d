/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfermey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 09:34:26 by wfermey           #+#    #+#             */
/*   Updated: 2022/06/11 15:28:17 by wfermey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	print_window()
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");						//  creation fenetre.
	img.img = mlx_new_image(mlx, 1920, 1080);										//  creation image (pour print avant fenetre).
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);										//  adresse de image pour pouvoir ecrire dessus.
	my_mlx_pixel_put(&img, 5, 5, 0x00FFFFFF);										//  mettre pixel sur image.
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);							//  afficher image sur la fenetre.
	mlx_loop(mlx);
}

int	main(int argc, char **argv)
{
	t_file	file;	

	ft_parsing(argv[1], &file);
//	print_window();
}
