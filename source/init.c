/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 19:27:02 by smodesto          #+#    #+#             */
/*   Updated: 2021/09/13 11:16:02 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
** allocate and init FDF struct
*/
t_fdf	*init_fdf(void)
{
	t_fdf	*mlx;

	mlx = (t_fdf *)malloc(sizeof(t_fdf));
	if (!mlx)
		check_error(1, "ERR_FDF_INIT");
	mlx->mlx = NULL;
	mlx->win = NULL;
	mlx->z_matrix = NULL;
	mlx->width = 0;
	mlx->height = 0;
	mlx->temp_vector = NULL;
	mlx->img = NULL;
	mlx->hex_color = 0;
	mlx->colors = (t_cc *)malloc(sizeof(t_cc));
	if (!mlx->colors)
		check_error(1, "ERR_FDF_INIT");
	mlx->colors->c4 = 1;
	mlx->colors->c5 = 1;
	mlx->colors->c6 = 0;
	mlx->colors->c7 = 0;
	return (mlx);
}

/*
** allocate and init IMG struct
*/
t_image	*init_img(t_fdf *mlx)
{
	t_image	*img;

	img = (t_image *)malloc(sizeof(t_image));
	if (!img)
		check_error(1, "ERR_IMG_INIT");
	img->img = NULL;
	img->data_address = NULL;
	img->bpp = 0;
	img->line_size = 0;
	img->endian = 0;
	img->camera = init_camera(mlx);
	img->width = mlx->width;
	img->height = mlx->height;
	return (img);
}

/*
** allocate and init Camera struct
*/
t_camera	*init_camera(t_fdf *mlx)
{
	t_camera	*camera;

	camera = (t_camera *)malloc(sizeof(t_camera));
	if (!camera)
		check_error(1, "ERR_CAM_INIT");
	camera->alpha = 0;
	camera->beta = 0;
	camera->gamma = 0;
	camera->z_divisor = 1;
	camera->x_offset = 0;
	camera->y_offset = 0;
	camera->zoom = min((WIN_WIDTH - MENU_WIDTH) / mlx->width / 2,
			WIN_HEIGHT / mlx->height / 2);
	return (camera);
}
