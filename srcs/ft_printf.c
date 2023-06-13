/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbureera <pbureera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 15:14:52 by pbureera          #+#    #+#             */
/*   Updated: 2023/06/13 11:59:20 by pbureera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_check(int c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
		|| c == 'u' || c == 'x' || c == 'X' || c == '%');
}

int	ft_convert(int c, va_list args)
{
	int	i;

	i = 0;
	if (c == 'c')
		i = ft_conv_char(va_arg(args, int));
	else if (c == 's')
		i = ft_conv_string(va_arg(args, char *));
	else if (c == 'p')
		i = ft_conv_pointer(va_arg(args, void *));
	else if (c == 'd' || c == 'i')
		i = ft_conv_decimal(va_arg(args, int));
	else if (c == 'u')
		i = ft_conv_unsigned(va_arg(args, unsigned long));
	else if (c == 'x')
		i = ft_conv_hexa_lower(va_arg(args, unsigned long));
	else if (c == 'X')
		i = ft_conv_hexa_upper(va_arg(args, unsigned long));
	else if (c == '%')
		i = ft_conv_percent(c);
	return (i);
}

static int	ft_print_value(const char *str, va_list args)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != '%')
			j += ft_putchar_fd(str[i], 1);
		else if ((str[i] == '%') && str[i + 1])
		{
			i++;
			if (ft_check(str[i]))
				j += ft_convert(str[i], args);
			else if (str[i])
				j += ft_putchar_fd(str[i], 1);
		}
		i++;
	}
	return (j);
}

int	ft_printf(const char *input, ...)
{
	int			i;
	const char	*str;
	va_list		args;

	i = 0;
	str = ft_strdup(input);
	if (!str)
		return (0);
	va_start(args, input);
	i += ft_print_value(str, args);
	va_end(args);
	free((void *)str);
	return (i);
}

int	main(void)
{
	int i;
	
	i = printf("\tprintf:\n");
	printf("%d\n", i);
	i = printf("char: %c\nstring: %s\npointer: %p\npointer null: %p\n", 'c', "Hello", "42", (void *)0);
	printf("%d\n", i);
	i = printf("decimal: %d\ninteger: %i\nunsigned: %u\n", -42, -42, 42);
	printf("%d\n", i);
	i = printf("hexa low: %x\nhexa up: %X\npercent: %%\n", 42, 42);
	printf("%d\n", i);
	i = ft_printf("\tft_printf:\n");
	ft_printf("%d\n", i);
	i = ft_printf("char: %c\nstring: %s\npointer: %p\npointer null: %p\n", 'c', "Hello", "42", (void *)0);
	ft_printf("%d\n", i);
	i = ft_printf("decimal: %d\ninteger: %i\nunsigned: %u\n", -42, -42, 42);
	ft_printf("%d\n", i);
	i = ft_printf("hexa low: %x\nhexa up: %X\npercent: %%\n", 42, 42);
	ft_printf("%d\n", i);
	return (0);
}
