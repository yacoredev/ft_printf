/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabaadi <yabaadi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 11:23:57 by yabaadi           #+#    #+#             */
/*   Updated: 2026/11/10 17:43:04 by yabaadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

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
}		t_flags;

int		ft_printf(const char *s, ...);

ssize_t	ft_printchar(char c);
ssize_t	ft_printstring(char *s);
ssize_t	ft_printunsigned(unsigned int n);

ssize_t	ft_printnumber_bonus(int n, t_flags *flags);
ssize_t	ft_printaddress_bonus(void *address, t_flags *flags);
ssize_t	ft_printhexa_upper_bonus(unsigned int decimal, t_flags *flags);
ssize_t	ft_printhexa_lower_bonus(unsigned int decimal, t_flags *flags);

#endif