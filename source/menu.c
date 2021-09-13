/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 19:10:56 by smodesto          #+#    #+#             */
/*   Updated: 2021/09/13 11:10:24 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	print_menu(t_fdf *fdf)
{
	int		y;
	void	*mlx;
	void	*win;

	y = 20;
	mlx = fdf->mlx;
	win = fdf->win;
	mlx_string_put(mlx, win, WIN_CENTER_X + (WIN_WIDTH * 0.0625),
		20, TEXT_COLOR, "Welcome to Fil De Fer");
	mlx_string_put(mlx, win, 65, y, TEXT_COLOR, "How to use:");
	mlx_string_put(mlx, win, 15, y += 35, TEXT_COLOR, "Zoom: +/-");
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "Move: w/a/s/d");
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "Height: q/e ");
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "Rotate:");
	mlx_string_put(mlx, win, 57, y += 25, TEXT_COLOR, "X-Axis: up/down");
	mlx_string_put(mlx, win, 57, y += 25, TEXT_COLOR, "Y-Axis: right/left");
	mlx_string_put(mlx, win, 57, y += 25, TEXT_COLOR, "Z-Axis: 1/3");
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "Color: ");
	mlx_string_put(mlx, win, 57, y += 25, TEXT_COLOR, "map color: 4");
	mlx_string_put(mlx, win, 57, y += 25, TEXT_COLOR, "white & Red: 5");
	mlx_string_put(mlx, win, 57, y += 25, TEXT_COLOR, "White & Purple: 6");
	mlx_string_put(mlx, win, 57, y += 25, TEXT_COLOR, "White & Blue: 7");
	mlx_string_put(mlx, win, WIN_CENTER_X + (WIN_WIDTH * 0.0625),
		WIN_HEIGHT - 20, TEXT_COLOR, "To exit Press Esc");
}
