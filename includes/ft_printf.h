/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbureera <pbureera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 16:54:40 by pbureera          #+#    #+#             */
/*   Updated: 2023/06/13 12:00:17 by pbureera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>
# include <stdio.h>
# include "../Libft/libft.h"

# define DECIMAL "0123456789"
# define HEXADECIMAL_LOWERCASE "0123456789abcdef"
# define HEXADECIMAL_UPPERCASE "0123456789ABCDEF"

int				ft_printf(const char *input, ...);
int				ft_conv_char(char c);
int				ft_conv_string(char *s);
int				ft_conv_pointer(void *str);
int				ft_conv_decimal(int d);
int				ft_conv_unsigned(unsigned int u);
int				ft_conv_hexa_lower(unsigned int hexa_l);
int				ft_conv_hexa_upper(unsigned int hexa_u);
int				ft_conv_percent(char c);

#endif