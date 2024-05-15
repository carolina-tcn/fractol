/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctacconi <ctacconi@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:57:51 by ctacconi          #+#    #+#             */
/*   Updated: 2024/01/31 16:20:46 by ctacconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Encuentra la primera aparición de un carácter en una cadena
char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != (char)c)
		i++;
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (0);
}

/*int	main(void)
{
	char	a = 'l';

	const char *s = "hola";
	const char	*s_2 = "hola";
	printf("%s\n", ft_strchr(s, a));
	printf("%s\n", strchr(s_2, a));
	return (0);
}*/
