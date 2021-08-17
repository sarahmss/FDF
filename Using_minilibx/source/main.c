/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 17:03:13 by smodesto          #+#    #+#             */
/*   Updated: 2021/08/17 19:24:07 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/using_mlx.h"

int draw_line(void *mlx, void *win, int beginX, int beginY, int endX, int endY, int color)
{
	t_data	line;

	line.pixelX = beginX;
	line.pixelY = beginY;
	line.deltaX = endX - beginX;
	line.deltaY = endY - beginY;
	line.pixels = sqrt((line.deltaX * line.deltaX) + (line.deltaY * line.deltaY));
	line.deltaX /= line.pixels;
	line.deltaY /= line.pixels;
	while (line.pixels)
	{
		mlx_pixel_put(mlx, win, line.pixelX, line.pixelY, color);
		line.pixelX += line.deltaX;
		line.pixelY += line.deltaY;
		--line.pixels;
	}
	return (0);
}

int	main(void)
{
	using_mlx1();
	return (0);
}
