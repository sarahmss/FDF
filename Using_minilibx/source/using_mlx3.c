/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   using_mlx3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 17:03:13 by smodesto          #+#    #+#             */
/*   Updated: 2021/08/17 19:09:51 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/using_mlx.h"

int	using_mlx3(void)
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 640, 360, "Draw line");
	draw_line(mlx_ptr, win_ptr, 640, 360, 0, 0, 0xFF3EFF);
	mlx_loop(mlx_ptr);
	return (0);
}
