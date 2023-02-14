/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbicanic <rbicanic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 19:02:09 by rbicanic          #+#    #+#             */
/*   Updated: 2021/12/04 13:08:14 by rbicanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_hex(unsigned int long_nbr, char *base)
{
	if (long_nbr > 15)
		ft_putnbr_hex(long_nbr / 16, base);
	write(1, &base[long_nbr % 16], 1);
}

int	ft_puthex_size(unsigned int long_nbr, char *base)
{
	int	i;

	i = 0;
	ft_putnbr_hex(long_nbr, base);
	if (long_nbr == 0)
		return (1);
	while (long_nbr > 0)
	{
		long_nbr /= 16;
		i++;
	}
	return (i);
}
