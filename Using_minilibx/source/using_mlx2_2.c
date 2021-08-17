/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   using_mlx2.2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 18:24:39 by smodesto          #+#    #+#             */
/*   Updated: 2021/08/17 19:09:38 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/using_mlx.h"

int	key_handling(int keycode, t_program *vars)
{
	printf("Keypressed: %d\n", keycode);
	if (keycode == KEY_ESC) //Quit the program when ESC key pressed
		exit(0);
	if (keycode == KEY_D)
			draw_line(vars->mlx_ptr, vars->win_ptr, 640, 360, 0, 0, 0xFF3EFF);
	return (0);
}

int mouse_handling(int button, int x, int y, void *param)
{
	t_program *vars = param;

	printf("Mouse button pressed: %d\n", button);
	if (button == 1)
		mlx_pixel_put(vars->mlx_ptr, vars->win_ptr, 640 / 2, 480 / 2, 0xFFFFFF);
	if (button == 3)
		mlx_pixel_put(vars->mlx_ptr, vars->win_ptr, 640 / 2, 480 / 2, 0xFF3EFF);

	return (1);
}

int	using_mlx2_2(void)
{
	t_program	vars;

	vars.mlx_ptr = mlx_init();
	vars.win_ptr = mlx_new_window(vars.mlx_ptr, 640, 480, "Keyboard + Mouse hooks");

	mlx_key_hook(vars.win_ptr, key_handling, &vars);
	mlx_mouse_hook(vars.win_ptr, &mouse_handling, &vars);

	mlx_loop(vars.mlx_ptr);
	return (0);
}
