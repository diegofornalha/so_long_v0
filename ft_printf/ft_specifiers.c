/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifiers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dida-sil <dida-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 09:20:05 by dida-sil          #+#    #+#             */
/*   Updated: 2022/09/19 16:39:02 by dida-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_specifiers(const char c, va_list v, int *i)
{
	if (c == 'c')
		return (ft_char_print(va_arg(v, int)));
	if (c == 's')
		return (ft_str_print(v));
	if (c == 'i' || c == 'd')
		return (ft_num_print(va_arg(v, int)));
	if (c == 'u')
		return (ft_num_print(va_arg(v, unsigned int)));
	if (c == 'x' || c == 'X')
		return (ft_hex_print(va_arg(v, unsigned int), c));
	if (c == 'p')
		return (ft_hex_print(va_arg(v, unsigned long), c));
	if (c == '%')
		return (ft_char_print(c));
	if (!c)
		return (0);
	else
		*i = *i - 1;
	return (0);
}
