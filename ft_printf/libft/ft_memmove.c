/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctacconi <ctacconi@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:49:26 by ctacconi          #+#    #+#             */
/*   Updated: 2024/01/31 16:19:42 by ctacconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Copia un bloque de memoria de una ubi a otra, non destructive way
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*ptrdest;
	const unsigned char	*ptrsrc;
	size_t				i;

	if (!src && !dst)
		return (0);
	ptrdest = (unsigned char *)dst;
	ptrsrc = (const unsigned char *)src;
	if (ptrdest > ptrsrc)
	{
		while (len-- > 0)
		{
			ptrdest[len] = ptrsrc[len];
		}
	}
	else
	{
		i = 0;
		while (i < len)
		{
			ptrdest[i] = ptrsrc[i];
			i++;
		}
	}
	return (dst);
}

/*int	main(void)
{
	char	src[] = "hola caracola";
	char	dst[] = "                      ";

	printf ("%s\n", dst);
	ft_memmove(dst, src, 4);
	printf ("%s\n", dst);
	return (0);
}*/
