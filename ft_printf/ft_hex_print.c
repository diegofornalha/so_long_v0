/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dida-sil <dida-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 09:20:05 by dida-sil          #+#    #+#             */
/*   Updated: 2022/09/19 16:38:41 by dida-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex_print(size_t n, char c)
{
	int	count;

	count = ft_num_length(n, 16);
	if (c == 'p')
	{
		ft_putstr_fd("0x", 1);
		count += 2;
		c = 'x';
	}
	if (n >= 16)
	{
		ft_hex_print(n / 16, c);
		ft_hex_print(n % 16, c);
	}
	else
	{
		if (n < 10)
			ft_putchar_fd(n + 48, 1);
		else if (c == 'x')
			ft_putchar_fd(n + 87, 1);
		else
			ft_putchar_fd(n + 55, 1);
	}
	return (count);
}
