/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctacconi <ctacconi@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 00:26:32 by ctacconi          #+#    #+#             */
/*   Updated: 2024/01/31 16:21:04 by ctacconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//a cada caracter de s aplica f(x) sin malloc
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int		cont;

	cont = 0;
	while (s[cont] != '\0')
	{
		f(cont, &s[cont]);
		cont++;
	}
	s[cont] = '\0';
}

/*int main()
{
	printf("\n%s\n", ft_strmapi("hola que tal", &f));
}*/
