/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dida-sil <dida-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 09:20:05 by dida-sil          #+#    #+#             */
/*   Updated: 2022/09/19 16:39:19 by dida-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H	
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

int	ft_char_print(char c);
int	ft_hex_print(size_t n, char c);
int	ft_num_length(size_t n, int base);
int	ft_num_print(long long int n);
int	ft_printf(const char *str, ...);
int	ft_specifiers(const char c, va_list v, int *i);
int	ft_str_print(va_list v);

#endif
