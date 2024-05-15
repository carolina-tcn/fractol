/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctacconi <ctacconi@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 21:00:38 by ctacconi          #+#    #+#             */
/*   Updated: 2024/01/31 16:22:14 by ctacconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Encuentra la última aparición de un carácter en una cadena
char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i--;
	}
	return (0);
}

/*int	main(void)
{
	char	a = 'l';

	const char *s = "carolina";
	const char *s_2 = "carolina";
	printf("%s\n", ft_strrchr(s, a));
	printf("%s\n", ft_strrchr(s_2, a));
	return (0);
}*/
