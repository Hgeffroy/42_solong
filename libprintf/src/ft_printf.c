/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 13:27:27 by hgeffroy          #+#    #+#             */
/*   Updated: 2022/11/22 14:22:09 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_args(char c, va_list args)
{
	int	res;

	res = 0;
	if (c == 'c')
		res = printf_putchar(va_arg(args, int), 1);
	else if (c == 'd' || c == 'i')
		res = printf_putnbr(va_arg(args, int), 1);
	else if (c == 's')
		res = printf_putstr((const char *)va_arg(args, char *), 1);
	else if (c == 'u')
		res = printf_putunbr(va_arg(args, unsigned int));
	else if (c == 'p')
		res = printf_address(va_arg(args, unsigned long long));
	else if (c == 'x')
		res = printf_puthexanbr(va_arg(args, unsigned int), 0);
	else if (c == 'X')
		res = printf_puthexanbr(va_arg(args, unsigned int), 1);
	else if (c == '%')
	{
		ft_putchar_fd('%', 1);
		res = 1;
	}
	return (res);
}

int	ft_printf_main(const char *str, va_list args, const char *modes, int mode)
{
	int	res;
	int	i;

	i = 0;
	res = 0;
	while (str[i])
	{
		if (str[i] == '%' && (mode % 2) == 0)
			mode++;
		else if ((mode % 2) == 1 && ft_strchr(modes, str[i]))
		{
			res += print_args(str[i], args);
			mode++;
		}
		else if (mode % 2 == 0)
			res += printf_putchar(str[i], 1);
		else
		{
			va_end(args);
			return (-1);
		}
		i++;
	}
	return (res);
}

int	ft_printf(const char *str, ...)
{
	int			res;
	int			mode;
	va_list		args;
	const char	*modes;

	if (write(1, 0, 0) != 0)
		return (-1);
	mode = 0;
	modes = "cdisupxX%";
	if (!str)
		return (-1);
	va_start(args, str);
	res = ft_printf_main(str, args, modes, mode);
	va_end(args);
	return (res);
}
