/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   using_mxl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 17:03:13 by smodesto          #+#    #+#             */
/*   Updated: 2021/08/11 21:49:26 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	using_mxl(void)
{
	void	*mlx_ptr;
	void	*win_ptr;

	ft_putstr_fd("ok\n", 1);
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "fdf 42");
	mlx_pixel_put(mlx_ptr, win_ptr, 300, 300, 0xFFFFFF);
	mlx_loop(mlx_ptr);

	return (0);
}
