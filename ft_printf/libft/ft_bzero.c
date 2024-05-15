/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctacconi <ctacconi@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:01:23 by ctacconi          #+#    #+#             */
/*   Updated: 2024/01/31 16:17:56 by ctacconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Establece todos los bytes de un bloque de memoria a cero
void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	i = 0;
	ptr = (unsigned char *)s;
	while (i < n)
		ptr[i++] = '\0';
}

/*int	main(void)
{
	char	bufer[10] = "hola";

	printf("Antes: %s\n", bufer);
	ft_bzero(bufer, 5);
	printf("Despues: %s\n", bufer);
	return (0);
}*/
