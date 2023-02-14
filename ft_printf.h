/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbicanic <rbicanic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 18:18:34 by rbicanic          #+#    #+#             */
/*   Updated: 2021/12/09 17:46:54 by rbicanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putnbr_len(int n);
int	ft_putnbr_unsigned_len(unsigned int n);
int	ft_puthex_size(unsigned int long_nbr, char *base);
int	ft_print_memory(void *ptr);
int	ft_printf(const char *str, ...);

#endif