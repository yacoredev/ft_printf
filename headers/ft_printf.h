/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabaadi <yabaadi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 16:00:37 by yabaadi           #+#    #+#             */
/*   Updated: 2026/11/07 10:52:42 by yabaadi          ###   ########.fr       */
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

typedef struct s_flags
{
	int	space;
	int	hash;
	int	plus;
}	t_flags;

int		ft_printf(const char *s, ...);
ssize_t	ft_printchar(char c);
ssize_t	ft_printnumber(int n, t_flags *flags);
ssize_t	ft_printunsigned(unsigned int n);
ssize_t	ft_printaddress(void *address, t_flags *flags);
ssize_t	ft_printhexa_upper(unsigned int decimal, t_flags *flags);
ssize_t	ft_printhexa_lower(unsigned int decimal, t_flags *flags);
ssize_t	ft_printstring(char *s);

#endif