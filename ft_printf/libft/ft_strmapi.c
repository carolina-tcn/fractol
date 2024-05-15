/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctacconi <ctacconi@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 23:29:58 by ctacconi          #+#    #+#             */
/*   Updated: 2024/01/31 16:21:48 by ctacconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//a cada caracter de s a aplica la f(x)
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ptr;
	int		cont;

	ptr = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!ptr)
		return (NULL);
	if (!s)
		return (NULL);
	cont = 0;
	while (s[cont] != '\0')
	{
		ptr[cont] = f(cont, s[cont]);
		cont++;
	}
	ptr[cont] = '\0';
	return (ptr);
}

/*int main()
{
	printf("%s\n", ft_strmapi("hola que tal", &f));
}
char	f(unsigned int i, char c)
{
	(void)i;

	if (c >= 97 && c <= 122)
		return ft_toupper(c);
	else
		return ft_tolower(c);
}*/
