/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 10:13:14 by hgeffroy          #+#    #+#             */
/*   Updated: 2022/11/19 10:30:43 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	lenunbr(unsigned long long nb, int basesize)
{
	int			res;

	res = 1;
	while (nb / basesize > 0)
	{
		res++;
		nb /= basesize;
	}
	return (res);
}

void	ft_putunbr(unsigned int n)
{
	if (n > 9)
	{
		printf_putunbr(n / 10);
		printf_putunbr(n % 10);
	}
	else
		ft_putchar_fd(n + '0', 1);
}

int	printf_putunbr(unsigned long long n)
{
	ft_putunbr(n);
	return (lenunbr(n, 10));
}
