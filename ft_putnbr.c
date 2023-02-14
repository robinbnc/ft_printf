/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbicanic <rbicanic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 18:32:52 by rbicanic          #+#    #+#             */
/*   Updated: 2021/12/04 13:06:11 by rbicanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr(int n)
{
	char	nbr;

	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		n = -n;
		write(1, "-", 1);
	}
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
	{
		nbr = n + 48;
		write(1, &nbr, 1);
	}
}

int	ft_putnbr_len(int n)
{
	int	len;

	len = 0;
	ft_putnbr(n);
	if (n == -2147483648)
		return (11);
	if (n == 0)
		return (1);
	else if (n < 0)
	{
		n = -n;
		len += 1;
	}
	while (n > 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}
