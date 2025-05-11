/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printmem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 19:36:55 by ocviller          #+#    #+#             */
/*   Updated: 2025/05/11 20:21:04 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdint.h>
#include <stdio.h>

#include <unistd.h>
#include <stdint.h>

static int	ft_putptr(uintptr_t addr)
{
	char	*base = "0123456789abcdef";
	char	buffer[16];
	int		i = 0;
	int		count = 0;

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
	count = write(1, "0x", 2);
	count += ft_putptr(addr);
	return (count);
}