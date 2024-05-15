/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctacconi <ctacconi@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 19:26:56 by ctacconi          #+#    #+#             */
/*   Updated: 2024/01/31 16:22:06 by ctacconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Busca la primera aparición de una subcadena en otra, dentro de un len 
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!*needle)
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		j = 0;
		while ((haystack[i + j] == needle[j]) && ((i + j) < len))
		{
			if (needle[j + 1] == '\0')
				return ((char *)(haystack + i));
			j++;
		}
		i++;
	}
	return (NULL);
}

/*int	main(void)
{
	const char *cadena = "carolina";
	const char *subcadena = "oli";
	printf("%s\n", ft_strnstr(cadena, subcadena, 9));
	printf("%s\n\n", strnstr(cadena, subcadena, 9));

	const char *cadena_1 = "carolina";
	const char *subcadena_1 = "\0";
	printf("%s\n", ft_strnstr(cadena_1, subcadena_1, 7));
	printf("%s\n", strnstr(cadena_1, subcadena_1, 7));
	return (0);
}*/
