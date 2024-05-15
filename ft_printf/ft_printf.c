/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctacconi <ctacconi@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 18:15:52 by ctacconi          #+#    #+#             */
/*   Updated: 2024/02/10 18:37:53 by ctacconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_format(char const *formato, va_list parametros, int *len)
{
	if (*(formato + 1) == 'c')
		ft_putchar(va_arg(parametros, int), len);
	else if (*(formato + 1) == 's')
		ft_putstr(va_arg(parametros, char *), len);
	else if (*(formato + 1) == 'p')
		ft_putptr(va_arg(parametros, unsigned long), len);
	else if ((*(formato + 1)) == 'd' || (*(formato + 1) == 'i'))
		ft_putnbr(va_arg(parametros, int), len);
	else if (*(formato + 1) == 'u')
		ft_put_unbr(va_arg(parametros, unsigned int), len);
	else if ((*(formato + 1) == 'x') || (*(formato + 1) == 'X'))
		ft_puthex(va_arg(parametros, unsigned int), *(formato + 1), len);
	else if (*(formato + 1) == '%')
		ft_putchar('%', len);
}

int	ft_printf(char const *formato, ...)
{
	va_list	parametros;
	int		len;

	len = 0;
	va_start(parametros, formato);
	while (*formato != '\0')
	{
		if (*formato != '%')
			ft_putchar(*formato++, &len);
		else
		{
			check_format(formato, parametros, &len);
			if (*formato)
				formato += 2;
		}
		if (len == -1)
			return (-1);
	}
	va_end(parametros);
	return (len);
}

/*int	main(void)
{
	int	variable = 42;
	int *ptr = &variable;
	printf(" LEN:%d\n", ft_printf("%s!, %d, %c", "Carolina", 42, 'h'));
	printf(" LEN:%d\n", printf("%s!, %d, %c", "Carolina", 42, 'h'));
	
	printf(" LEN:%d\n", ft_printf("%%, %u, %p", -21474648, ptr));
	printf(" LEN:%d\n", printf("%%, %u, %p", -21474648, ptr));

	printf(" len:%d\n", printf("%p", ""));
	printf(" len:%d\n", ft_printf("%p", ""));
	return (0);
}*/
