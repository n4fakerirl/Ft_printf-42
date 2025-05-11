/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 18:03:14 by ocviller          #+#    #+#             */
/*   Updated: 2025/05/11 18:25:30 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <limits.h>
#include <stdio.h>

int	ft_format(const char c, va_list args)
{
	int	count;

	count = 0;
	if (c == '%')
		count += ft_printchar(c);
	else if (c == 'd' || c == 'i')
		count += ft_printnb(va_arg(args, int));
	else if (c == 'u')
		count += ft_printuns(va_arg(args, unsigned int));
	else if (c == 'x')
		count += ft_printhex(va_arg(args, unsigned int));
	else if (c == 'X')
		count += ft_printhex_up(va_arg(args, unsigned int));
	else if (c == 's')
		count += ft_printstr(va_arg(args, char *));
	else if (c == 'c')
		count += ft_printchar(va_arg(args, int));
	return (count);
}

int	ft_printf(const char *format, ...)
{
	size_t	i;
	va_list	args;
	int count;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			count += ft_format(format[i + 1], args);
			i++;
		}
		else
			count += ft_printchar(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}

int	main(void)
{
	int		a;
	char	str[] = "oce";
	int		count;
	int		count2;

	a = 21;
	count = ft_printf("slt c %s, g %d ans, j'adore lettre %c et le truc %%, 42 en hex : %x\n", str, a, 'n', 420);
	count2 = printf("slt c %s, g %d ans, j'adore lettre %c et le truc %%, 42 en hex : %x\n", str, a, 'n', 420);
	ft_printf("%d\n", count);
	printf("%d\n", count2);
}
