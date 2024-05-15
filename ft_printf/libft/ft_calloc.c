/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctacconi <ctacconi@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:11:05 by ctacconi          #+#    #+#             */
/*   Updated: 2024/01/31 16:18:08 by ctacconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//allocate space for count objects with size bytes each
void	*ft_calloc(size_t count, size_t size)
{
	void			*ptr;

	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, size * count);
	return (ptr);
}

/*int	main(void)
{	
	size_t			obj;
	size_t			size_obj;
	unsigned char	*str;

	obj = 5;
	size_obj = sizeof(char);
	str = ft_calloc(obj, size_obj);
	
	if (str[0] == '\0')
		write (1, "x\n", 1);
	if (str[1] == '\0')
		write (1, "x\n", 1);
	return (0);
}*/
