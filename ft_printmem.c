/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printmem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 19:36:55 by ocviller          #+#    #+#             */
/*   Updated: 2025/06/04 10:23:29 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putptr(uintptr_t addr)
{
	char	*base;
	char	buffer[16];
	int		i;
	int		count;

	base = "0123456789abcdef";
	i = 0;
	count = 0;
	if (addr == 0)
		return (write(1, "0", 1));
	while (addr > 0)
	{
		buffer[i++] = base[addr % 16];
		addr /= 16;
	}
	while (i--)
		count += ft_printchar(buffer[i]);
	return (count);
}

int	ft_printmem(void *ptr)
{
	int			count;
	uintptr_t	addr;

	addr = (uintptr_t)ptr;
	if (ptr == 0)
	{
		count = write(1, "(nil)", 5);
		return (count);
	}
	count = write(1, "0x", 2);
	count += ft_putptr(addr);
	return (count);
}
