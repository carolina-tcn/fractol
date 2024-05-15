/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctacconi <ctacconi@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 19:27:25 by ctacconi          #+#    #+#             */
/*   Updated: 2024/02/10 18:23:14 by ctacconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//imprime el argumento en formato hexadecimal
static void	ft_printptr(unsigned long ptr, int *len)
{
	if (*len == -1)
		return ;
	if (ptr >= 16 && *len != -1)
	{
		ft_printptr(ptr / 16, len);
		if (*len == -1)
			return ;
		ft_printptr(ptr % 16, len);
	}
	else
	{
		if (ptr <= 9 && *len != -1)
			ft_putchar(ptr + '0', len);
		else
		{
			if (*len != -1)
				ft_putchar(ptr - 10 + 'a', len);
		}
	}
}

void	ft_putptr(unsigned long ptr, int *len)
{
	if (ptr == 0)
	{
		if (write(1, "0x0", 3) == -1)
		{
			*len = -1;
			return ;
		}
		*len += 3;
	}
	else
	{
		if (write(1, "0x", 2) == -1)
		{
			*len = -1;
			return ;
		}
		*len += 2;
		ft_printptr(ptr, len);
	}
}

/*int	main(void)
{
	int variable = 42;
	
	void *p;
	p = &variable;
	printf("%p", p); 
	return (0);
}*/
