/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctacconi <ctacconi@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 22:28:46 by ctacconi          #+#    #+#             */
/*   Updated: 2024/02/10 18:22:56 by ctacconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//imprime un numero decimal
void	ft_putnbr(int number, int *len)
{
	char	*num;

	num = ft_itoa(number);
	if (!num)
	{
		*len = -1;
		return ;
	}
	ft_putstr(num, len);
	free(num);
}

/*int	main(void)
{
	//printf("%d", printf("%d", -1));	
	//print('\n');

	printf("%d\n", printf("%d", -10));
	print('\n');

	ft_printf("%d\n", printf("%d", -10));
	//print('\n');

	//printf("%d", printf("%d", -11));
	//print('\n');

	//printf("%d", printf("%d", -14));
	//print('\n');
}*/
