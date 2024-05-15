/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctacconi <ctacconi@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:13:41 by ctacconi          #+#    #+#             */
/*   Updated: 2024/01/31 16:21:21 by ctacconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Concatena dos cadenas de manera segura, evita desbordamientos de búfer
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	i;

	if (dstsize <= ft_strlen(dst))
		return (dstsize + ft_strlen(src));
	dst_len = ft_strlen(dst);
	i = 0;
	while (src[i] != '\0' && ((dstsize - 1) > dst_len))
	{
		dst[dst_len] = src[i];
		i++;
		dst_len++;
	}
	dst[dst_len] = '\0';
	return (ft_strlen(&src[i]) + ft_strlen(dst));
}

/*int	main(void)
{
	char	s_src[20] = "hola";
	char	s_dst[30] = "carolina";
	printf("%zu\n", ft_strlcat(s_dst, s_src, 15));
	printf("%s\n", s_dst);
	printf("%zu\n", strlcat(s_dst, s_src, 15));
	printf("%s\n\n", s_dst);
	
	char	s_src1[20] = "hola";
	char	s_dst1[30] = "carolina";
	printf("%zu\n", ft_strlcat(s_dst1, s_src1, 5));
	printf("%s\n", s_dst1);
	printf("%zu\n", strlcat(s_dst1, s_src1, 5));
	printf("%s\n\n", s_dst1);
	
	char	s_src2[20] = "hola";
	char	s_dst2[30] = "carolina";
	printf("%zu\n", ft_strlcat(s_dst2, s_src2, 6));
	printf("%s\n", s_dst2);
	printf("%zu\n", strlcat(s_dst2, s_src2, 6));
	printf("%s\n\n", s_dst2);

	char	s_src3[30] = "hola";
	char	s_dst3[30] = "carolina";
	printf("%zu\n", ft_strlcat(s_dst3, s_src3, 4));
	printf("%s\n", s_dst3);
	printf("%zu\n", strlcat(s_dst3, s_src3, 4));
	printf("%s\n\n", s_src3);
	return (0);
}*/
