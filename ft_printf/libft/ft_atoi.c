/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctacconi <ctacconi@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:58:43 by ctacconi          #+#    #+#             */
/*   Updated: 2024/01/31 16:17:42 by ctacconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Convierte una cadena de caracteres num a un número en un entero
int	ft_atoi(const char *str)
{
	int	res;
	int	sign;
	int	i;

	res = 0;
	sign = 1;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * sign);
}

/*int	main(void)
{
	char	*s = " ---+--+1234ab567";
	printf("%d\n", ft_atoi(s));
	printf("%d\n\n", atoi(s));

	char	*s_1 = "0";
	printf("%d\n", ft_atoi(s_1));
	printf("%d\n\n", atoi(s_1));

	char	*s_2 = "\0";
	printf("%d\n", ft_atoi(s_2));
	printf("%d\n\n", atoi(s_2));

	char	*s_3= "1234ab567";
	printf("%d\n", ft_atoi(s_3));
	printf("%d\n\n", atoi(s_3));

	char	*s_4= "--1234ab567";
	printf("%d\n", ft_atoi(s_4));
	printf("%d\n", atoi(s_4));
}*/
