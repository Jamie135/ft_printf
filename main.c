/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbureera <pbureera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:06:51 by pbureera          #+#    #+#             */
/*   Updated: 2023/06/13 12:17:44 by pbureera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"
#include "./Libft/libft.h"
#include <stdio.h>

int	main(void)
{
	printf("\tprintf:\n");
	printf("char: %c\nstring: %s\npointer: %p\npointer null: %p\n", 'c', "Hello", "42", (void *)0);
	printf("decimal: %d\ninteger: %i\nunsigned: %u\n", -42, -42, 42);
	printf("hexa low: %x\nhexa up: %X\npercent: %%\n", 42, 42);
	ft_printf("\tft_printf:\n");
	ft_printf("char: %c\nstring: %s\npointer: %p\npointer null: %p\n", 'c', "Hello", "42", (void *)0);
	ft_printf("decimal: %d\ninteger: %i\nunsigned: %u\n", -42, -42, 42);
	ft_printf("hexa low: %x\nhexa up: %X\npercent: %%\n", 42, 42);
	return (0);
}
