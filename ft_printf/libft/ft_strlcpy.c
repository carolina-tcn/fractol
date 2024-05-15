/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctacconi <ctacconi@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:09:47 by ctacconi          #+#    #+#             */
/*   Updated: 2024/01/31 16:21:30 by ctacconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Copia una cadena a otra, cadena dest no excede size
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	cont;

	i = 0;
	cont = 0;
	while (src[cont])
		cont++;
	if (dstsize < 1)
		return (cont);
	while (src[i] && (i < (dstsize - 1)))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (cont);
}

/*int	main(void)
{
	char	src[] = "hola carolina";
	char	dst[] = "adios                      ";

	printf("%zu\n", ft_strlcpy(dst, src, 25));
	printf("%s\n", dst);
}*/
