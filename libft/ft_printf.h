/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yususato <yususato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 18:54:48 by yususato          #+#    #+#             */
/*   Updated: 2024/08/24 17:34:11 by yususato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <inttypes.h>
# include <string.h>
# include <limits.h>
# include <stdarg.h>
# include <stdint.h>

int		ft_putnbr_i(int nb);
int		ft_putnbr_u(unsigned int nb);
int		ft_putstr(char *s);
int		ft_printf(const char *fmt, ...);
int		count(const char *save, va_list ap);
int		ft_range(int c, va_list ap);
int		ft_process_u(unsigned int u);
int		ft_process_c(char c);
int		ft_process_i(int c);
int		ft_process_s(char *c);
int		ft_process_x(unsigned int p, int c);
int		ft_small(unsigned int p);
int		ft_large(unsigned int p);
int		ft_process_p(uintptr_t p);
int		ft_putchar(int n);

#endif