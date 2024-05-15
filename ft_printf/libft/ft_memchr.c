/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctacconi <ctacconi@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 22:31:44 by ctacconi          #+#    #+#             */
/*   Updated: 2024/01/31 16:19:16 by ctacconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Busca la primera aparición de un byte esp en un bloque de memoria
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n--)
	{
		if (*ptr == (unsigned char)c)
			return ((void *)ptr);
		ptr++;
	}
	return (NULL);
}

/*int	main(void)
{
	char	string[15] = "abcfvcxghhbghhj";

	printf("%s\n", ft_memchr(string, 'x', 8));
	printf("%s\n", memchr(string, 'x', 8));
	return (0);
}*/
