/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   using_mlx2.0.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 17:03:13 by smodesto          #+#    #+#             */
/*   Updated: 2021/08/17 19:09:28 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/using_mlx.h"

int mouse_event(int button, int x, int y, void *param)
{
	t_program *prog = param;
	int xs;
	int ys;

	xs = 640 / 2;
	ys = 360 / 2;
	ft_putnbr_fd(button, 1);
	if (button == 1)
		mlx_pixel_put(prog->mlx_ptr, prog->win_ptr, xs, ys, 0xFFFFFF);
	if (button == 3)
		mlx_pixel_put(prog->mlx_ptr, prog->win_ptr, xs, ys, 0xFF3EFF);

	return (1);
}

int using_mlx2(void)
{
	t_program mxl;
	t_program prog;

	mxl.mlx_ptr = mlx_init();
	mxl.win_ptr = mlx_new_window(mxl.mlx_ptr, 500, 500, "Mouse hooks");

	prog.mlx_ptr = mxl.mlx_ptr;
	prog.win_ptr = mxl.win_ptr;
	mlx_mouse_hook(mxl.win_ptr, &mouse_event, &prog);
	mlx_loop(mxl.mlx_ptr);

	return (0);
}
