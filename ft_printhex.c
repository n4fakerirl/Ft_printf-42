/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 22:04:02 by ocviller          #+#    #+#             */
/*   Updated: 2025/05/11 17:46:54 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	ft_putnbr_base(unsigned int nb, char *base)
{
	unsigned long long	nbr;
	char				result;
	int					count;

	nbr = nb;
	count = 0;
	if (nbr >= ft_strlen(base))
	{
		count += ft_putnbr_base(nbr / ft_strlen(base), base);
		count += ft_putnbr_base(nbr % ft_strlen(base), base);
	}
	if (nbr >= 0 && nbr < ft_strlen(base))
	{
		count++;
		result = base[nbr];
		ft_putchar_fd(result, 1);
	}
	return (count);
}

int	ft_printhex(unsigned int nb)
{
	int	count;

	count = ft_putnbr_base(nb, "0123456789abcdef");
	return (count);
}

int	ft_printhex_up(unsigned int nb)
{
	int				count;

	count = ft_putnbr_base(nb, "0123456789ABCDEF");
	return (count);
}
