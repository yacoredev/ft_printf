/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexa_lower.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabaadi <yabaadi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 16:01:47 by yabaadi           #+#    #+#             */
/*   Updated: 2026/11/07 10:44:32 by yabaadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

static ssize_t	print_rec(unsigned int decimal)
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

ssize_t	ft_printhexa_lower(unsigned int decimal, t_flags *flags)
{
	ssize_t	count;

	count = 0;
	if (!decimal)
		return (write(1, "0", 1));
	if (flags->hash)
	{
		count = write(1, "0x", 2);
		if (count < 0)
			return (-1);
	}
	count += print_rec(decimal);
	if (count < 0)
		return (-1);
	return (count);
}
