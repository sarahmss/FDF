/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 17:58:28 by smodesto          #+#    #+#             */
/*   Updated: 2021/09/12 22:36:51 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int argc, char **argv)
{
	t_fdf	*mlx;

	mlx = init_fdf();
	if (argc != 2)
	{
		ft_printf("Insert only one file: ./fdf <MAP_FILE> \n");
		exit (0);
	}
	read_file(argv[1], mlx);
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, WIN_WIDTH, WIN_HEIGHT, "FDF-smodesto");
	mlx->img = init_img(mlx);
	ft_create_image(mlx, mlx->img);
	control_events(mlx);
	mlx_loop(mlx->mlx);
	return (0);
}
