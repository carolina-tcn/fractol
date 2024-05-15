/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctacconi <ctacconi@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 12:04:03 by ctacconi          #+#    #+#             */
/*   Updated: 2024/01/31 16:19:34 by ctacconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Copia un bloque de memoria de una ubi a otra, si overlap mejor memmove
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (!src && !dst)
		return (0);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}

/*int	main(void)
{
	char	sorc[] = "hola caracola";
	char	dest[15];

	printf("%s\n", dest);
	ft_memcpy(dest, sorc, 7);
	printf("%s\n", dest);
	return (0);
}*/
