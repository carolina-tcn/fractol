/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctacconi <ctacconi@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:11:11 by ctacconi          #+#    #+#             */
/*   Updated: 2024/01/31 16:19:49 by ctacconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Establece len bytes de un bloque de memoria a un valor específico c (unsigned)
void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;
	size_t			i;

	i = 0;
	ptr = (unsigned char *)b;
	while (i < len)
		ptr[i++] = (unsigned char)c;
	return (b);
}

/*int	main(void)
{
	char	bufer[20];

	printf("Antes: %s\n", bufer);
	ft_memset(bufer, 'r', 5);
	printf("Despues: %s\n", bufer);
	return (0);
}*/
