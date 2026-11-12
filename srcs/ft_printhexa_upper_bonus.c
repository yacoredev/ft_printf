/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexa_upper_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabaadi <yabaadi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 12:14:01 by yabaadi           #+#    #+#             */
/*   Updated: 2026/11/09 15:16:59 by yabaadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf_bonus.h"

static ssize_t	print_rec(unsigned int decimal)
{
	char	*hexa;
	char	c;
	ssize_t	count;

	hexa = BASE16_UPPER;
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

ssize_t	ft_printhexa_upper_bonus(unsigned int decimal, t_flags *flags)
{
	ssize_t	count;
	ssize_t	re;

	count = 0;
	if (!decimal)
		return (write(1, "0", 1));
	if (flags->hash)
	{
		count = write(1, "0X", 2);
		if (count < 0)
			return (-1);
	}
	re = print_rec(decimal);
	if (re < 0)
		return (-1);
	return (count + re);
}
