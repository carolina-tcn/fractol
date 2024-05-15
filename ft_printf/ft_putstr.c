/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctacconi <ctacconi@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:41:17 by ctacconi          #+#    #+#             */
/*   Updated: 2024/02/10 18:23:35 by ctacconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//imprime una string
void	ft_putstr(char *s, int *len)
{
	int	i;

	i = 0;
	if (!s)
	{
		if (write(1, "(null)", 6) == -1)
			*len = -1;
		else
			*len += 6;
	}
	else
	{
		while (s[i] != '\0')
		{
			ft_putchar(s[i], len);
			if (*len == -1)
				return ;
			i++;
		}
	}
}

/*int	main(void)
{
	printf("%d", ft_putstr((char *)NULL));
	printf("%s", (char *)NULL);
}*/
