/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carolinatacconis <marvin@42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 17:16:54 by carolinat         #+#    #+#             */
/*   Updated: 2024/05/15 17:17:07 by carolinat        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_error_exit(void)
{
	ft_printf("%s%s%s%s", ERROR_2, ERROR_3, ERROR_4, ERROR_5);
	exit (EXIT_FAILURE);
}

int main(int argc, char **argv)
{
	t_fractal	fract;

	if (argc < 2)
	{
		ft_printf("%s", ERROR_1);
		exit(1);
	}	
	check_args(argc, argv, &fract);
	init(&fract);
	render_fractal(&fract);
	mlx_loop(fract.mlx_ptr);
	return (0);
}
