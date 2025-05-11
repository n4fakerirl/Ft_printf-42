/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 17:52:38 by ocviller          #+#    #+#             */
/*   Updated: 2025/05/11 18:20:26 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_printchar(char c);
int	ft_printnb(int nb);
int	ft_printstr(char *str);
int	ft_printuns(unsigned int nb);
int	ft_printhex(unsigned int nb);
int	ft_printhex_up(unsigned int nb);
int	ft_putnbr_base(unsigned int nb, char *base);

#endif