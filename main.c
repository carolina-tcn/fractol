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
	ft_printf("%s%s%s%s%s%s%s", ERROR_1, ERROR_2, ERROR_3,
		ERROR_4, ERROR_5, ERROR_6, ERROR_7);
	exit (EXIT_FAILURE);
}

void	ft_error(void)
{
	printf("Memory allocation failure\n");
}

//to rescale from 0...800 to -2...+2
double	map(double unscaled_num, double new_min, double new_max, double old_max)
{
	double	old_min;

	old_min = 0;
	return ((new_max - new_min) * (unscaled_num - old_min)
		/ (old_max - old_min) + new_min);
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
