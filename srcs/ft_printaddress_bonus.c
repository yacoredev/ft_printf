/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printaddress_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabaadi <yabaadi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 12:13:28 by yabaadi           #+#    #+#             */
/*   Updated: 2026/11/09 12:13:32 by yabaadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf_bonus.h"

static ssize_t	print_rec(unsigned long decimal)
{
	char	*hexa;
	char	c;
	ssize_t	count;

	hexa = BASE16_LOWER;
	if (decimal == 0)
		return (0);
	count = print_rec(decimal / 16);
	if (count < 0)
		return (-1);
	c = hexa[decimal % 16];
	if (write(1, &c, 1) < 0)
		return (-1);
	return (count + 1);
}

ssize_t	ft_printaddress_bonus(void *address, t_flags *flags)
{
	ssize_t	count;
	ssize_t	re;

	count = 0;
	if (!address)
		return (write(1, "(nil)", 5));
	if (flags->plus)
	{
		count = write(1, "+", 1);
		if (count < 0)
			return (-1);
	}
	else if (flags->space)
	{
		count = write(1, " ", 1);
		if (count < 0)
			return (-1);
	}
	if (write(1, "0x", 2) < 0)
		return (-1);
	re = print_rec((unsigned long)address);
	if (re < 0)
		return (-1);
	count += re;
	return (count + 2);
}
