/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbicanic <rbicanic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 18:56:29 by rbicanic          #+#    #+#             */
/*   Updated: 2021/12/04 13:08:40 by rbicanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr_unsigned(unsigned int n)
{
	char	nbr[1];

	if (n > 9)
	{
		ft_putnbr_unsigned(n / 10);
		ft_putnbr_unsigned(n % 10);
	}
	else
	{
		nbr[0] = n + 48;
		write(1, nbr, 1);
	}
}

int	ft_putnbr_unsigned_len(unsigned int n)
{
	int	len;

	len = 0;
	ft_putnbr_unsigned(n);
	if (n == 0)
		return (1);
	while (n > 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}
