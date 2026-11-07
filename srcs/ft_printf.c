/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabaadi <yabaadi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 16:02:37 by yabaadi           #+#    #+#             */
/*   Updated: 2026/11/07 11:00:28 by yabaadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

static ssize_t	put_lastcase(char c)
{
	if (write(1, "%", 1) < 0)
		return (-1);
	if (write(1, &c, 1) < 0)
		return (-1);
	else
		return (2);
}

static ssize_t	ft_print_format(char type, va_list args, t_flags *flags)
{
	if (type == 'd' || type == 'i')
		return (ft_printnumber(va_arg(args, int), flags));
	else if (type == 'u')
		return (ft_printunsigned(va_arg(args, unsigned int)));
	else if (type == 'c')
		return (ft_printchar(va_arg(args, int)));
	else if (type == 'p')
		return (ft_printaddress(va_arg(args, void *), flags));
	else if (type == 'x')
		return (ft_printhexa_lower(va_arg(args, unsigned int), flags));
	else if (type == 'X')
		return (ft_printhexa_upper(va_arg(args, unsigned int), flags));
	else if (type == 's')
		return (ft_printstring(va_arg(args, char *)));
	else if (type == SPECIFIER)
		return (write(1, "%", 1));
	else
		return (put_lastcase(type));
}

static void	skip_flags(const char **s, t_flags *flags)
{
	while (**s == '#' || **s == '+' || **s == ' ')
	{
		if (**s == '#')
			flags->hash = 1;
		else if (**s == '+')
			flags->plus = 1;
		else if (**s == ' ')
			flags->space = 1;
		(*s)++;
	}
}

static ssize_t	print_one(const char **s, va_list args)
{
	ssize_t	count;
	t_flags	flags;

	if (**s != SPECIFIER)
	{
		if (write(1, *s, 1) < 0)
			return (-1);
		(*s)++;
		return (1);
	}
	(*s)++;
	if (**s == '\0')
		return (-1);
	flags.hash = 0;
	flags.plus = 0;
	flags.space = 0;
	skip_flags(s, &flags);
	if (**s == '\0')
		return (-1);
	count = ft_print_format(**s, args, &flags);
	if (count < 0)
		return (-1);
	(*s)++;
	return (count);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	ssize_t	count;
	ssize_t	bytes;

	if (!s || write(1, 0, 0) < 0)
		return (-1);
	va_start(args, s);
	bytes = 0;
	while (*s)
	{
		count = print_one(&s, args);
		if (count < 0)
		{
			va_end(args);
			return (-1);
		}
		bytes += count;
	}
	va_end(args);
	return (bytes);
}
