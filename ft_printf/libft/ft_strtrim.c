/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctacconi <ctacconi@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:26:50 by ctacconi          #+#    #+#             */
/*   Updated: 2024/01/31 16:22:22 by ctacconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//eleimina los caracteres set de la s1(ppo y final)
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	int		start;
	int		end;

	start = 0;
	end = ft_strlen(s1);
	if (!s1 || !set)
		return (NULL);
	while (ft_strchr(set, s1[start]) && start < end && s1[start])
	{
		start++;
	}
	while (ft_strchr(set, s1[end]) && end > start)
	{
		end--;
	}
	ptr = ft_substr(s1, start, end - start + 1);
	return (ptr);
}

/*int main ()
{
	printf("%s\n", ft_strtrim("papapacarolpapap","pa"));
	printf("%s\n", ft_strtrim("", ""));
}*/
