/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   using_mlx1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 17:03:13 by smodesto          #+#    #+#             */
/*   Updated: 2021/08/17 19:21:33 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/using_mlx.h"

int	using_mlx1(void)
{
	t_program	mxl;

	mxl.mlx_ptr = mlx_init();
	mxl.win_ptr = mlx_new_window(mxl.mlx_ptr, 500, 500, "Simple window");

	mlx_loop(mxl.mlx_ptr);

	return (0);
}
