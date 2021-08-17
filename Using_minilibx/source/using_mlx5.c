/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   using_mlx5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 17:03:13 by smodesto          #+#    #+#             */
/*   Updated: 2021/08/17 19:10:23 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/using_mlx.h"

int	using_mlx5(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;
	int	img_width;
	int	img_height;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "Putting existent image to window");
	img = mlx_xpm_file_to_image(mlx_ptr, "../textures/wall_n.xpm", &img_width, &img_height);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img, 50, 50);
	mlx_loop(mlx_ptr);
	return (0);
}
