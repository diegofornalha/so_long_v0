/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dida-sil <dida-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 09:20:05 by dida-sil          #+#    #+#             */
/*   Updated: 2022/09/19 16:38:55 by dida-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnum(size_t n)
{
	if (n > 9)
	{
		ft_putnum(n / 10);
		ft_putnum(n % 10);
	}
	if (n < 10)
	{
		ft_putchar_fd(n + 48, 1);
	}
}

int	ft_num_print(long long int n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		ft_putchar_fd('-', 1);
		n = -n;
		count++;
	}
	ft_putnum(n);
	count += ft_num_length(n, 10);
	return (count);
}
