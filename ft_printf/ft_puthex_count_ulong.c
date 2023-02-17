/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abertoli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 17:33:54 by abertoli          #+#    #+#             */
/*   Updated: 2022/10/21 18:29:38 by abertoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_puthex_strncmp(unsigned long n, char *letter_size)
{
	int	count;

	count = 0;
	if (n <= 9)
		count = count + ft_putnbr_count(n);
	else if (!ft_strncmp(letter_size, "lowercase", ft_strlen(letter_size)))
		count = count + ft_putchar_count(n + 87);
	else if (!ft_strncmp(letter_size, "uppercase", ft_strlen(letter_size)))
		count = count + ft_putchar_count(n + 55);
	return (count);
}

int	ft_puthex_count_ulong(unsigned long n, char *letter_size, int binary_size)
{
	int	count;

	if (n < 16)
		count = ft_puthex_strncmp(n, letter_size);
	else
	{
		count = ft_puthex_count_ulong(n / 16, letter_size, binary_size);
		count = count + ft_puthex_strncmp(n % 16, letter_size);
	}
	return (count);
}
