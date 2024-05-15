/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctacconi <ctacconi@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 20:30:17 by ctacconi          #+#    #+#             */
/*   Updated: 2024/01/31 16:22:30 by ctacconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//crea una substr desde la s
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ptr;
	unsigned int	i;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		len = 0;
	else if (ft_strlen(&s[start]) < len)
		len = ft_strlen(&s[start]);
	ptr = malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < len && s[start] != '\0')
	{
		ptr[i] = s[start];
		i++;
		start++;
	}
	ptr[i] = '\0';
	return (ptr);
}
/*int	main(void)
{
	char const	*string;
	char		*sub_string;

	string = "Carolina";
	sub_string = ft_substr(string, 2, 4);

	if (!sub_string)
		printf("Error: no se pudo duplicar la cadena.\n");
	printf("Original: %s\n", string);
	printf("Substring: %s\n", sub_string);
	free(sub_string);
	return (0);
}
*/
