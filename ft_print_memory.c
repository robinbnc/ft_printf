/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbicanic <rbicanic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 20:07:11 by rbicanic          #+#    #+#             */
/*   Updated: 2021/12/09 17:38:35 by rbicanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdint.h>

static void	ft_printhex(uintptr_t long_nbr, char *base)
{
	if (long_nbr > 15)
		ft_printhex(long_nbr / 16, base);
	write(1, &base[long_nbr % 16], 1);
}

static int	ft_printhex_size(uintptr_t long_nbr, char *base)
{
	int	i;

	i = 0;
	ft_printhex(long_nbr, base);
	while (long_nbr > 0)
	{
		long_nbr /= 16;
		i++;
	}
	return (i);
}

int	ft_print_memory(void *ptr)
{
	uintptr_t	lint_add;

	if (ptr == NULL)
	{
		write(1, "0x0", 3);
		return (3);
	}
	lint_add = (uintptr_t) ptr;
	write(1, "0x", 2);
	return (ft_printhex_size(lint_add, "0123456789abcdef") + 2);
}
