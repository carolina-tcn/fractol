/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctacconi <ctacconi@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:43:16 by ctacconi          #+#    #+#             */
/*   Updated: 2024/02/10 18:22:17 by ctacconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//imprimir un numero decimal sin signo
static void	print(char c, int *len)
{
	if (write(1, &c, 1) == -1)
		*len = -1;
	else
		*len += 1;
}

void	ft_put_unbr(unsigned int n, int *len)
{
	if (n > 9 && *len != -1)
	{
		ft_put_unbr(n / 10, len);
		ft_put_unbr(n % 10, len);
	}
	else if (*len != -1)
		print(n + '0', len);
}

/*int	main(void)
{
	int len = 0;
    int *ptr = &len;
	ft_put_unbr(-2147483648, ptr);
	return (0);
}*/
