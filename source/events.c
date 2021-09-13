/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 10:49:09 by smodesto          #+#    #+#             */
/*   Updated: 2021/09/13 13:04:58 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
** Write error messages and exit program
*/
void	check_error(int err, char *msg)
{
	if (err < 1)
	{
		ft_printf("-ERROR: %s\n", msg);
		exit (1);
	}
}

/*
** Close window when X bar's buttom is pressed
*/
static int	close_window(t_fdf *mlx)
{
	free_array((void **)mlx->hex_color);
	free_array((void **)mlx->z_matrix);
	exit(0);
}

/*
** Redraw image when - bar's buttom is pressed
*/
static int	redraw(t_fdf *mlx)
{
	ft_create_image(mlx, mlx->img);
	return (0);
}

/*
** Controls keyboard events
*/
static int	keyboard_input(int key, t_fdf *mlx)
{
	if (key == MAIN_KEY_ESC)
		close_window(mlx);
	if (key == NUM_KEY_PLUS || key == NUM_KEY_MINUS)
		zoom(key, mlx);
	else if (key == MAIN_KEY_W || key == MAIN_KEY_A || key == MAIN_KEY_S
		|| key == MAIN_KEY_D || key == MAIN_KEY_Q || key == MAIN_KEY_E)
		move(key, mlx);
	else if (key == ARROW_DOWN || key == ARROW_UP
		|| key == ARROW_RIGHT || key == ARROW_LEFT
		|| key == NUM_KEY_1 || key == MAIN_KEY_1
		|| key == NUM_KEY_3 || key == MAIN_KEY_3)
		rotate(key, mlx);
	else if (key == NUM_KEY_4 || key == MAIN_KEY_4
		|| key == NUM_KEY_5 || key == MAIN_KEY_5
		|| key == NUM_KEY_6 || key == MAIN_KEY_6
		|| key == NUM_KEY_7 || key == MAIN_KEY_7)
		change_color(key, mlx);
	return (0);
}

void	control_events(t_fdf *mlx)
{
	mlx_key_hook(mlx->win, keyboard_input, mlx);
	mlx_hook(mlx->win, X_EVENT_KEY_EXIT, 0, &close_window, mlx);
	mlx_expose_hook(mlx->win, &redraw, mlx);
}
