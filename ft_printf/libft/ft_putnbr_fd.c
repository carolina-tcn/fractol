/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctacconi <ctacconi@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 22:00:30 by ctacconi          #+#    #+#             */
/*   Updated: 2024/01/31 16:20:18 by ctacconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//escribir un int en un fd
void	print(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		print('-', fd);
		print('2', fd);
		ft_putnbr_fd(147483648, fd);
	}
	else if (n < 0)
	{
		print('-', fd);
		n = n * (-1);
		ft_putnbr_fd(n, fd);
	}
	else if (n > 9)
	{
		ft_putnbr_fd((n / 10), fd);
		ft_putnbr_fd((n % 10), fd);
	}
	else
		print((n + '0'), fd);
}

/*int	main(void)
{
	ft_putnbr_fd(147483648, 1);
	print('\n', 1);
}*/
