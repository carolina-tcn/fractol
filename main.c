/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctacconi <ctacconi@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 19:06:01 by ctacconi          #+#    #+#             */
/*   Updated: 2024/05/25 13:12:04 by ctacconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_error_exit(void)
{
	ft_printf("%s%s%s%s", ERROR_1, ERROR_2, ERROR_3, ERROR_4);
	exit (EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_fractal	fract;

	if (argc < 2)
		print_error_exit();
	check_args(argc, argv, &fract);
	init(&fract);
	render_fractal(&fract);
	mlx_hook(fract.win_ptr, 4, 0, mouse_hook, &fract);
	mlx_key_hook(fract.win_ptr, manage_key, &fract.mlx_ptr);
	mlx_hook(fract.win_ptr, ON_DESTROY, 0, close_red_cross, fract.mlx_ptr);
	mlx_loop(fract.mlx_ptr);
	return (0);
}
