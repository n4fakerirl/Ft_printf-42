/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 18:03:14 by ocviller          #+#    #+#             */
/*   Updated: 2025/05/12 16:16:42 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <limits.h>
#include <stdio.h>

int	ft_format(const char c, va_list args)
{
	if (c == 'd' || c == 'i')
		return (ft_printnb(va_arg(args, int)));
	else if (c == 'u')
		return (ft_printuns(va_arg(args, unsigned int)));
	else if (c == 'x')
		return (ft_printhex(va_arg(args, unsigned int)));
	else if (c == 'X')
		return (ft_printhex_up(va_arg(args, unsigned int)));
	else if (c == 's')
		return (ft_printstr(va_arg(args, char *)));
	else if (c == 'c')
		return (ft_printchar(va_arg(args, int)));
	else if (c == '%')
		return (ft_printchar('%'));
	else if (c == 'p')
		return (ft_printmem(va_arg(args, char *)));
	else
		return (-1);
}

int	ft_printf(const char *format, ...)
{
	size_t	i;
	va_list	args;
	int		count;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			count += ft_format(format[i], args);
		}
		else
			count += ft_printchar(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}

/*int	main(void)
{
	int		a;
	char	*str = NULL;
	int		count;
	int		count2;

	a = 21;
	count = ft_printf("ma fonction : %%% . euuuh");
	//printf("\n");
	count2 = printf(" vrai printf : %%% . euuuh");
	//ft_printf("%d\n", count);
	//printf("%d\n", count2);
}*/
