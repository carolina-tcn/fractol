/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctacconi <ctacconi@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 19:06:21 by ctacconi          #+#    #+#             */
/*   Updated: 2024/05/20 19:06:23 by ctacconi         ###   ########.fr       */
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

