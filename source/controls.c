/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 17:54:42 by smodesto          #+#    #+#             */
/*   Updated: 2021/09/13 11:08:46 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
**Handle zoom
*/
void	zoom(int key, t_fdf *mlx)
{
	if (key == NUM_KEY_PLUS)
		mlx->img->camera->zoom++;
	else if (key == NUM_KEY_MINUS)
		mlx->img->camera->zoom--;
	if (mlx->img->camera->zoom < 1)
		mlx->img->camera->zoom = 1;
	ft_create_image(mlx, mlx->img);
}

void	move(int key, t_fdf *mlx)
{
	if (key == MAIN_KEY_A)
		mlx->img->camera->x_offset -= 10;
	else if (key == MAIN_KEY_D)
		mlx->img->camera->x_offset += 10;
	else if (key == MAIN_KEY_W)
		mlx->img->camera->y_offset -= 10;
	else if (key == MAIN_KEY_S)
		mlx->img->camera->y_offset += 10;
	else if (key == MAIN_KEY_Q)
		mlx->img->camera->z_divisor -= 0.1;
	else if (key == MAIN_KEY_E)
		mlx->img->camera->z_divisor += 0.1;
	if (mlx->img->camera->z_divisor < 0.1)
		mlx->img->camera->z_divisor = 0.1;
	if (mlx->img->camera->z_divisor > 10)
		mlx->img->camera->z_divisor = 10;
	ft_create_image(mlx, mlx->img);
}

void	rotate(int key, t_fdf *mlx)
{
	if (key == ARROW_UP)
		mlx->img->camera->alpha += 0.5;
	else if (key == ARROW_DOWN)
		mlx->img->camera->alpha -= 0.5;
	else if (key == ARROW_RIGHT)
		mlx->img->camera->beta += 0.5;
	else if (key == ARROW_LEFT)
		mlx->img->camera->beta -= 0.5;
	else if (key == NUM_KEY_1 || key == MAIN_KEY_1)
		mlx->img->camera->gamma += 0.5;
	else if (key == NUM_KEY_3 || key == MAIN_KEY_3)
		mlx->img->camera->gamma -= 0.5;
	ft_create_image(mlx, mlx->img);
}

void	change_color(int key, t_fdf *mlx)
{
	mlx->colors->c4 = 0;
	mlx->colors->c5 = 0;
	mlx->colors->c6 = 0;
	mlx->colors->c7 = 0;
	if (key == NUM_KEY_4 || key == MAIN_KEY_4)
		mlx->colors->c4 = 1;
	else if (key == NUM_KEY_5 || key == MAIN_KEY_5)
		mlx->colors->c5 = 1;
	else if (key == NUM_KEY_6 || key == MAIN_KEY_6)
		mlx->colors->c6 = 1;
	else if (key == NUM_KEY_7 || key == MAIN_KEY_7)
		mlx->colors->c7 = 1;
	ft_create_image(mlx, mlx->img);
}
