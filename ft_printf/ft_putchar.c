/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctacconi <ctacconi@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 22:05:50 by ctacconi          #+#    #+#             */
/*   Updated: 2024/02/10 18:22:26 by ctacconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//imprimir un solo caracter
void	ft_putchar(char c, int *len)
{
	if (write(1, &c, 1) == -1)
		*len = -1;
	else
		*len += 1;
}
