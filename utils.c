/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carolinatacconis <marvin@42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 21:03:10 by carolinat         #+#    #+#             */
/*   Updated: 2024/05/15 21:45:28 by carolinat        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_atod(const char *str, double res, double decimal, int i)
{
	int	sign;
	int	j;

	sign = 1;
	j = -1;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	if (str[i] >= '0' && str[i] <= '9')
	{
		res += (str[i] - '0');
		i++;
	}
	if (str[i++] == '.')
	{
		while (str[i] && str[i] >= '0' && str[i] <= '9')
		{
			decimal += (pow(10, j) * (str[i] - '0'));
			j--;
			i++;
		}
	}
	//printf("%lf\n", (res + decimal) * sign);
	return ((res + decimal) * sign);
}

