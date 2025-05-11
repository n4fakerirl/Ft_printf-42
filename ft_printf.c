/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 18:03:14 by ocviller          #+#    #+#             */
/*   Updated: 2025/05/11 20:21:42 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdio.h>
#include <limits.h>

int ft_printf(const char *format, ...)
{
    size_t i;
    va_list args;
    int count;

    i = 0;
    count = 0;
    va_start(args, format);
    while (format[i] != '\0')
    {
        if (format[i] == '%')
        {
            i++;
            if (format[i] == '%')
                count += ft_printchar(format[i]);
            else if (format[i] == 'd' || format[i] == 'i')
                count += ft_printnb(va_arg(args, int));
            else if (format[i] == 'u')
                count += ft_printuns(va_arg(args, unsigned int));
            else if (format[i] == 'x')
                count += ft_printhex(va_arg(args, unsigned int));
            else if (format[i] == 'X')
                count += ft_printhex_up(va_arg(args, unsigned int));
            else if (format[i] == 's')
                count += ft_printstr(va_arg(args, char *));
            else if (format[i] == 'c')
                count += ft_printchar(va_arg(args, int));
			else if (format[i] == 'p')
				count += ft_printmem(va_arg(args, char *));
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
	char	str[] = "test";
	int		count;
	int		count2;

	a = 21;
	count = ft_printf("%p\n", &a);
	count2 = printf("%p\n", &a);
	ft_printf("%d\n", count);
	printf("%d\n", count2);
}*/
