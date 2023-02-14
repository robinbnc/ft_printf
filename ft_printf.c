/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbicanic <rbicanic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 17:20:53 by rbicanic          #+#    #+#             */
/*   Updated: 2021/12/09 17:52:06 by rbicanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_flags(va_list	param, const char *c)
{
	char	*hex_min;
	char	*hex_maj;

	hex_min = "0123456789abcdef";
	hex_maj = "0123456789ABCDEF";
	if (c[1] == 'c')
		return (ft_putchar(va_arg(param, int)));
	else if (c[1] == 's')
		return (ft_putstr(va_arg(param, char *)));
	else if (c[1] == 'p')
		return (ft_print_memory(va_arg(param, void *)));
	else if (c[1] == 'd')
		return (ft_putnbr_len(va_arg(param, int)));
	else if (c[1] == 'i')
		return (ft_putnbr_len(va_arg(param, int)));
	else if (c[1] == 'u')
		return (ft_putnbr_unsigned_len(va_arg(param, unsigned int)));
	else if (c[1] == 'x')
		return (ft_puthex_size(va_arg(param, unsigned int), hex_min));
	else if (c[1] == 'X')
		return (ft_puthex_size(va_arg(param, unsigned int), hex_maj));
	else if (c[1] == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	va_list	param;

	va_start(param, str);
	i = 0;
	len = 0;
	while (*str)
	{
		while (str[i] && str[i] != '%')
			i++;
		write(1, str, i);
		str += i;
		len += i;
		i = 0;
		if (str[i] == '%')
		{
			len += print_flags(param, str);
			str += 2;
		}
	}
	va_end(param);
	return (len);
}
