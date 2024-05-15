/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carolinatacconis <marvin@42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 17:34:53 by carolinat         #+#    #+#             */
/*   Updated: 2024/05/15 17:34:56 by carolinat        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int check_double_format(char *xy)
{
	int i;

	i = 0;
	if (xy[i] == '\0')
		return (0);
	if (xy[0] == '-' && !ft_isdigit(xy[1]))
		return (0);
	if (xy[0] == '-')
	{		
		if (xy[2] && xy[2] != '.')
			return (0);
		i++;
	}
	if (xy[i + 1] && xy[i + 1] == '.')
	{
		i += 2;	
		while (xy[i])
		{
			if (!ft_isdigit(xy[i]))
				return (0);
			i++;
		}
	}
	return (1);
}

int check_max_min_double(char *xy)
{
	char *xy_check;

	xy_check = xy;
	if (xy_check[0] == '-')
		xy_check++;
	if (*xy_check > '2')
		return (0);
	if (*(xy_check + 1) && *(xy_check + 1) != '.')
		return (0);
	if (*xy_check == '2' && *(xy_check + 1) == '.')
	{
		xy_check += 2;
		if (ft_strlen(xy_check) > 6)
			return (0);
		while (*xy_check++)
		{
			if (*xy_check != '0')
				return (0);
			xy_check++;
		}
		return (1);
	}
	xy_check += 2;
	if (ft_strlen(xy_check) > 6)
		return (0);
	return (1);
}

int check_julia_args(char *str)
{
	if (!check_double_format(str))
		return (0);
	if (!check_max_min_double(str))
		return (0);
	return (1);
}

void print_error_exit(void)
{
	ft_printf("%s%s%s", ERROR_2, ERROR_3, ERROR_4);
	exit (1);
}

void check_args(int argc, char **argv, t_fractal *fractal)
{
 	int i;

	i = -1;
	while (argv[1][i++])
		argv[1][i] = ft_tolower(argv[1][i]);
	if ((argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10)) || (argc == 4 && !ft_strncmp(argv[1], "julia", 5)))
	{
		fractal->name = argv[1];
		if (argc == 4)
		{
			if (!check_julia_args(argv[2]) || !check_julia_args(argv[3]))
				print_error_exit();
			//fractal.c.x = ft_atod(argv[2]);
			//fractal.c.y = ft_atod(argv[3]);
			return ;
		}

	}
	else
		print_error_exit();	
}