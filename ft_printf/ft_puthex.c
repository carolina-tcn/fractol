/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctacconi <ctacconi@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:04:53 by ctacconi          #+#    #+#             */
/*   Updated: 2024/02/10 18:22:41 by ctacconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//Funcion que printa un numero en hexadecimal en may o min
void	ft_puthex(unsigned int num, char c, int *len)
{
	if (num < 0 && *len != -1)
	{
		ft_putchar('-', len);
		num *= (-1);
		ft_puthex(num, c, len);
	}
	if (num >= 16 && *len != -1)
	{
		ft_puthex(num / 16, c, len);
		ft_puthex(num % 16, c, len);
	}
	else
	{
		if (num <= 9 && *len != -1)
			ft_putchar(num + '0', len);
		else
		{
			if (c == 'x' && *len != -1)
				ft_putchar(num - 10 + 'a', len);
			if (c == 'X' && *len != -1)
				ft_putchar(num - 10 + 'A', len);
		}
	}
}

/*int	main(void)
{
	printf("%x\n", -1);

	printf("%x\n", -9);
	
	printf("%x\n", -10);	
	
	printf("%x\n", -11);
	
	printf("%x\n", -99);
	
	return (0);
}*/
