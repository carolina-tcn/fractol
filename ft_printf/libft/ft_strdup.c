/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctacconi <ctacconi@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:30:29 by ctacconi          #+#    #+#             */
/*   Updated: 2024/01/31 16:20:55 by ctacconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//allocate memory for a copy of string
char	*ft_strdup(const char *s1)
{
	char	*ptr_dst;
	size_t	i;

	ptr_dst = (char *)malloc(ft_strlen(s1) + 1);
	if (!ptr_dst)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		ptr_dst[i] = s1[i];
		i++;
	}
	ptr_dst[i] = '\0';
	return (ptr_dst);
}

/*int	main(void)
{
	const char	*string_src;
	char		*string_dst;

	string_src = "Hola, mundo!";
	string_dst = ft_strdup(string_src);

	if (!string_dst)
		printf("Error: no se pudo duplicar la cadena.\n");
	printf("Original: %s\n", string_src);
	printf("Copiada: %s\n", string_dst);
	free(string_dst);
	return (0);
}*/
