/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 19:58:01 by smodesto          #+#    #+#             */
/*   Updated: 2021/09/13 13:05:15 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
**Apply Isometric formulas to x and y coordenates giving 3D impression
*/
static void	isometric(float *x, float *y, int z)
{
	int	previous_x;
	int	previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = -z + (previous_x + previous_y) * sin(0.523599);
}

/*
** Configure color for each line drawed by brasenham
*/
static void	configure_color(t_fdf *mlx)
{
	int	cz0;
	int	cz1;

	cz0 = mlx->hex_color[(int)mlx->temp_vector->y0][(int)mlx->temp_vector->x0];
	cz1 = mlx->hex_color[(int)mlx->temp_vector->y1][(int)mlx->temp_vector->x1];
	if (cz0 != 0 && cz0 == cz1 && mlx->colors->c4)
		mlx->temp_vector->color = cz0;
	else if (mlx->temp_vector->z0 || mlx->temp_vector->z1)
	{
		if (mlx->colors->c5)
			mlx->temp_vector->color = RED;
		else if (mlx->colors->c6)
			mlx->temp_vector->color = PURPLE;
		else if (mlx->colors->c7)
			mlx->temp_vector->color = BLUE;
	}
	else
		mlx->temp_vector->color = WHITE;
}

/*
** Configure point's
**		size: zoom
**		position: zoom + (width/height)
**		rotation: matrix transformation formulas for each aixis and angles
*/
static void	point_configure(t_image *img, float *x, float *y, int *z)
{
	int	previous_y;
	int	previous_x;

	*x *= img->camera->zoom;
	*y *= img->camera->zoom;
	*z *= img->camera->zoom / img->camera->z_divisor;
	*x -= (img->width * img->camera->zoom) / 2;
	*y -= (img->height * img->camera->zoom) / 2;
	previous_y = *y;
	*y = (previous_y * cos(img->camera->alpha) + *z * sin(img->camera->alpha));
	*z = (-previous_y * sin(img->camera->alpha) + *z * cos(img->camera->alpha));
	previous_x = *x;
	*x = (previous_x * cos(img->camera->beta) + *z * sin(img->camera->beta));
	*z = (-previous_x * sin(img->camera->beta) + *z * cos(img->camera->beta));
	previous_y = *y;
	previous_x = *x;
	*x = (previous_x * cos(img->camera->gamma) - previous_y
			* sin(img->camera->gamma));
	*y = (previous_x * sin(img->camera->gamma) + previous_y
			* cos(img->camera->gamma));
	isometric(x, y, *z);
	*x += ((WIN_WIDTH - MENU_WIDTH) / 2 + (img->camera->x_offset + MENU_WIDTH));
	*y += ((WIN_HEIGHT + img->height * img->camera->zoom) / 2)
		+ img->camera->y_offset;
}

/*
** Brasenham's algorithme draws lines between two points
*/
static void	brasenham(t_fdf *mlx, t_vector vector, t_image *img)
{
	t_vector	*temp;

	temp = &vector;
	mlx->temp_vector = &vector;
	temp->z0 = mlx->z_matrix[(int)temp->y0][(int)temp->x0];
	temp->z1 = mlx->z_matrix[(int)temp->y1][(int)temp->x1];
	configure_color(mlx);
	point_configure(img, &temp->x0, &temp->y0, &temp->z0);
	point_configure(img, &temp->x1, &temp->y1, &temp->z1);
	temp->delta_x = (temp->x1 - temp->x0);
	temp->delta_y = (temp->y1 - temp->y0);
	temp->max = max(mod(temp->delta_x), mod(temp->delta_y));
	temp->delta_x /= temp->max;
	temp->delta_y /= temp->max;
	while ((int)(temp->x0 - temp->x1) || (int)(temp->y0 - temp->y1))
	{
		my_mlx_pixel_put(mlx, temp->x0, temp->y0, img);
		temp->x0 += temp->delta_x;
		temp->y0 += temp->delta_y;
	}
}

/*
** draw function defines the coordenates of (x0, y0) and (x1, y1)
** based on width and height
*/
void	draw(t_fdf *mlx, t_image *img)
{
	t_vector	vector;

	vector.y0 = 0;
	while (vector.y0 < mlx->height)
	{
		vector.x0 = 0;
		while (vector.x0 < mlx->width)
		{
			if (vector.x0 < mlx->width - 1)
			{
				vector.x1 = vector.x0 + 1;
				vector.y1 = vector.y0;
				brasenham(mlx, vector, img);
			}
			if (vector.y0 < mlx->height - 1)
			{
				vector.x1 = vector.x0;
				vector.y1 = vector.y0 + 1;
				brasenham(mlx, vector, img);
			}
			vector.x0++;
		}
		vector.y0++;
	}
}
