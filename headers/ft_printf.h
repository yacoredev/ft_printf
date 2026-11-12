/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabaadi <yabaadi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 16:00:37 by yabaadi           #+#    #+#             */
/*   Updated: 2026/11/10 17:43:00 by yabaadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# define SPECIFIER '%'
# define BASE16_UPPER "0123456789ABCDEF"
# define BASE16_LOWER "0123456789abcdef"

int		ft_printf(const char *s, ...);

ssize_t	ft_printchar(char c);
ssize_t	ft_printstring(char *s);
ssize_t	ft_printunsigned(unsigned int n);

ssize_t	ft_printnumber(int n);
ssize_t	ft_printaddress(void *address);
ssize_t	ft_printhexa_upper(unsigned int decimal);
ssize_t	ft_printhexa_lower(unsigned int decimal);

#endif