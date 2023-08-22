/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 13:31:46 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/05/24 09:06:56 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	lennbr(int nb, int basesize)
{
	int			res;
	long int	longnb;

	longnb = nb;
	res = 1;
	if (longnb < 0)
	{
		res++;
		longnb *= -1;
	}
	while (longnb / basesize > 0)
	{
		res++;
		longnb /= basesize;
	}
	return (res);
}

int	printf_putnbr(int nb, int fd)
{
	ft_putnbr_fd(nb, fd);
	return (lennbr(nb, 10));
}

void	ft_puthexanbr(unsigned long long n, int up)
{
	char	*base;

	base = "0123456789abcdef";
	if (up)
		base = "0123456789ABCDEF";
	else if (n > 15)
	{
		ft_puthexanbr(n / 16, up);
		ft_puthexanbr(n % 16, up);
	}
	else
		ft_putchar_fd(base[n], 1);
}

int	printf_puthexanbr(unsigned long long n, int up)
{
	ft_puthexanbr(n, up);
	return (lenunbr(n, 16));
}

int	printf_address(unsigned long long ptr)
{
	ft_putstr_fd("0x", 1);
	return (printf_puthexanbr(ptr, 0) + 2);
}
